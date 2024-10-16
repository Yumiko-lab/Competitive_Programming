#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define int long long

void solve() {
    int n;
    i64 sum;
    cin >> n >> sum;
    vector<int> a(n);
    i64 now = 0;
    for (auto &x : a) {
        cin >> x;
        now += x;
    }
    if (now == sum) {
        cout << "0\n";
        return;
    }
    sort(a.begin(), a.end());
    if (now > sum) {
        int cnt = 0;
        i64 s = 0;
        for (int i = n - 1; i >= 0; i--) {
            s += a[i], cnt++;
            if (now - s - cnt * 1e4 <= sum) {
                break;
            }
        }
        cout << cnt << '\n';
    } else {
        int cnt = 0;
        i64 s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i], cnt++;
            if (now - s + cnt * 1e4 >= sum) {
                break;
            }
        }
        cout << cnt << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}