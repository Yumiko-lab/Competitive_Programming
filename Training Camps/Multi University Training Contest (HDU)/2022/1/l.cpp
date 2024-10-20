#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m = 0;
    cin >> n;
    bool has = false;
    vector<int> a(n + 1); // 0 .. n
    bool ok = false;
    bool row = true; // is in a row
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        if (i > 0 && a[i] == 0) {
            row = false;
        }
        if (row && a[i] >= 2) {
            ok = true;
        }
    }
    if (a[0] > 0) {
        ok = true;
    }
    cout << (ok ? "Alice" : "Bob") << '\n';
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