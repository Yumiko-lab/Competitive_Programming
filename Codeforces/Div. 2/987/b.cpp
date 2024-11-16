#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p) {
        cin >> x;
    }
    for (int i = 0; i < n; i++) {
        if (p[i] != i + 1) {
            if (i - 1 >= 0 && abs(p[i] - p[i - 1]) == 1) {
                swap(p[i], p[i - 1]);
            }
            if (i + 1 < n && abs(p[i] - p[i + 1]) == 1) {
                swap(p[i], p[i + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (p[i] != i + 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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