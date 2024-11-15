#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int sqr = min(x, y);
    cout << 0 << ' ' << 0 << ' ' << sqr << ' ' << sqr << '\n';
    cout << 0 << ' ' << sqr << ' ' << sqr << ' ' << 0 << '\n';
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