#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = n;
    if ((n % 3 % 5) == 0) {
        ans = min(ans, n / 3 + (n % 3) / 5);
    }
    if ((n % 5 % 3) == 0) {
        ans = min(ans, n / 5 + (n % 5) / 3);
    }
    if (ans == n) {
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