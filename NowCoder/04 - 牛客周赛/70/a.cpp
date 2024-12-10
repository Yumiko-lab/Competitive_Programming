#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    for (int i = 0; i < 4; i++) {
        if (a[i] != a[0]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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