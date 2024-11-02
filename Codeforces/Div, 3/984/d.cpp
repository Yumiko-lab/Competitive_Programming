#include <bits/stdc++.h>
using namespace std;

constexpr int dir[][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    int x = 0, y = 0;

    auto tra = [&](int sx, int sy, int n, int m) {
        int c = 0; // cur
        int x = sx, y = sy;
        int p = 0, q = 0;
        
    };

    while (n > 0 && m > 0) {
        tra(x, y, n, m); // Traversal
        x++, y++;
        n -= 2, m -= 2;
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