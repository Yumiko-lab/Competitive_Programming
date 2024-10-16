#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info {
    int t, l, w;
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<Info> a(n);
    for (auto &[t, l, w] : a) {
        cin >> t >> l >> w;
    }

    auto check = [&](auto mi) {
        i64 cnt = 0;
        for (auto [t, l, w] : a) {
            i64 M = mi, T = 1LL * t * l + w;
            i64 m = M / T;
            cnt += m * l;
            M %= T;
            cnt += min(1LL * l, M / t);
            if (cnt >= k) {
                return true;
            }
        }
        return false;
    };

    i64 lo = 0, hi = 2e18;
    while (lo < hi) {
        auto mi = (lo + hi) >> 1;
        if (check(mi)) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << hi << '\n';
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