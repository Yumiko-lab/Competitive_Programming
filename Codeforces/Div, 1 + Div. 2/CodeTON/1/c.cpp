#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool one = false;
    for (auto &x : a) {
        cin >> x;
        if (x == 1) {
            one = true;
        }
    }
    if (!one) {
        cout << "YES\n";
        return;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {
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