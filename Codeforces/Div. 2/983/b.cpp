#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return;
    }

    if (k == 1 || k == n) {
        cout << "-1\n";
        return;
    }

    int mi = (n + 1) / 2;
    if (k == mi) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    } else if (k < mi) {
        cout << 3 << '\n';
        cout << 1 << ' ' << 2 << ' ' << 2 * k - 1 << '\n';
    } else {
        cout << 3 << '\n';
        cout << 1 << ' ' << 2 * k - n + 1 << ' ' << n << '\n';
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