#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n, b, c;
    cin >> n >> b >> c;

    i64 ans = -1;
    if (b != 0) {
        ans = n - (c < n ? (n - 1 - c) / b + 1 : 0);
    } else if (c >= n) {
        ans = n;
    } else if (c >= n - 2) {
        ans = n - 1;
    } else {
        ans = -1;
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