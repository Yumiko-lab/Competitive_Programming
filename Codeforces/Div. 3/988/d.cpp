#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<PII> segs(n), power(m);
    int mx = 0;
    for (auto &[l, r] : segs) {
        cin >> l >> r;
        mx = max(mx, r - l + 1);
    }
    for (auto &[x, v] : power) {
        cin >> x >> v;
    }
    vector<i64> s(m);
    s[0] = power[0].second;
    for (int i = 1; i < m; i++) {
        s[i] = s[i - 1] + power[i].second;
    }
    // cerr << mx << '\n';
    int ans = 0;
    i64 now = 1;
    for (auto [l, r] : segs) {
        // <= l
        int lo = -1, hi = m - 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) >> 1;
            if (power[mi].first < l) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        if (lo == -1) {
            if (now <= r - l + 1) {
                ans = -1;
                break;
            }
            continue;
        }
        if (1 + s[lo] <= r - l + 1) {
            ans = -1;
            break;
        }
        now = 1 + s[lo];
        if (1 + s[lo] > mx) {
            for (int i = lo; i >= 0; i--) {
                if (1 + s[i] > mx) {
                    ans = i + 1;
                } else {
                    break;
                }
            }
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*

1
2 5 50
7 14
30 40
2 2
3 1
3 5
18 2
22 32


1
4 3 50
4 6
15 18
20 26
34 38
1 2
8 2
10 2

*/