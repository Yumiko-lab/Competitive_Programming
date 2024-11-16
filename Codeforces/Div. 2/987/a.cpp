#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int cnt = 0;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        b.push_back(j - i);
        i = j - 1;
    }
    int ans = n;
    for (auto x : b) {
        ans = min(ans, n - x);
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