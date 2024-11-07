#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int m = (n - 1) / 2;
    int cur = 1;
    for (int i = m; i < n; i++) {
        a[i] = cur++;
    }
    for (int i = 0; i < m; i++) {
        a[i] = cur++;
    }
    for (auto x : a) {
        cout << x << ' ';
    }
    cout << '\n';
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