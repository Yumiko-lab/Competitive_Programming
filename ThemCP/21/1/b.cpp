#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mn = 1e9;
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            mn = min(mn, a[i]);
        }
        sum += max(0, a[i] - 2);
    }
    if (a[0] == 1) {
        cout << "Bob\n";
    } else {
        if (mn == 1) {
            cout << "Alice\n";
        } else {
            cout << (sum % 2 == 1 ? "Alice" : "Bob") << '\n';
        }
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