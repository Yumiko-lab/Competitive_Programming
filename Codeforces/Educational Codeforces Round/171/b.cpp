#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }

    if (n % 2 == 0) {
        i64 mx = 1;
        for (int i = 1; i < n; i += 2) {
            mx = max(mx, a[i] - a[i - 1]);
        }
        cout << mx << '\n';
    } else {
        // i64 mx = 1;
        i64 mn = n;
        vector<i64> pre(n), suf(n);
        for (int i = 1; i < n; i += 2) {
            pre[i] = max(pre[max(0, i - 2)], a[i] - a[i - 1]);
        }
        for (int i = n - 2; i >= 0; i -= 2) {
            suf[i] = max(suf[min(n - 1, i + 1)], a[i + 1] - a[i]);
        }
        // for (int i = 0; i < n; i++) {
        //     cout << pre[i] << ' ';
        // }
        // cout << '\n';
        // for (int i = 0; i < n; i++) {
        //     cout << suf[i] << ' ';
        // }
        // cout << '\n';
        for (int i = 0; i < n; i += 2) {
            if (i == 0 || i == n - 1 || a[i] > a[i - 1] + 1 || a[i] < a[i + 1] - 1) {
                mn = min(mn, max(pre[max(0, i - 1)], suf[min(n - 1, i + 1)]));
            }
        }
        cout << mn << '\n';
    }
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
3
2 4 9

*/