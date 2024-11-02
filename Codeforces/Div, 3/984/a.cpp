#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
        int d = abs(a[i] - a[i - 1]);
        if (d != 5 && d != 7) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
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