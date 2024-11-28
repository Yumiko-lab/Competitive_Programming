#include <bits/stdc++.h>
using namespace std;

constexpr int dir[][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    auto calc = [&](int x, int y) {
        int cnt = 0;
        for (auto [dx, dy] : dir) {
            int a = x + dx, b = y + dy;
            if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] != 1) {
                continue;
            }
            cnt++;
        }
        return cnt;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 1) {
                ans += 1 + calc(i, j);
                g[i][j] = 0;
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}