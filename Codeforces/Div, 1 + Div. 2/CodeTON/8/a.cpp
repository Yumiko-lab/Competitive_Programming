#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k != 1 && k != n) {
        cout << "-1\n";
        return;
    }
    if (k == 1) {
        cout << 1 << ' ';
        for (int i = 0; i < n - 1; i++) {
            cout << 2 << ' ';
        }
        cout << '\n';
        return;
    }
    // k == n
    for (int i = 0; i < n; i++) {
        cout << 1 << ' ';
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