#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int dx = (x + k - 1) / k, dy = (y + k - 1) / k;
    int ans = max(dx, dy) * 2;
    if (dx > dy) {
        ans--;
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