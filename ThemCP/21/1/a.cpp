#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int now = (1 << 30) - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        now &= a[i];
        if (now == 0) {
            ans += 1;
            now = (1 << 30) - 1;
        }
    }
    if (now > 0 && ans == 0) {
        ans += 1;
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