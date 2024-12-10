#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }
    vector<int> mx(n);
    mx[0] = a[0];
    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i - 1], a[i]);
    }

    int ans = 0;
    for (int i = n - 1; i > 0; i--) {
        int r = k - (n - i - 1);
        if (r < 0) {
            break;
        }
        ans = max(ans, a[i] + mx[min(r, i - 1)]);
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