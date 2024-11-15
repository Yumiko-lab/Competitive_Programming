#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = n;
    for (int i = 0, j = 0; i < n; i++) {
        while (j + 1 < i && a[j] + a[j + 1] <= a[i]) {
            j++;
        }
        ans = min(ans, n - (i - j + 1));
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