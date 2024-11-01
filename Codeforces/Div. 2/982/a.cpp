#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        x = max(x, w);
        y = max(y, h);
    }
    cout << 2 * x + 2 * y << '\n';
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