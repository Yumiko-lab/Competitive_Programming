#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

constexpr int d[][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, sx, sy, ex, ey;
    cin >> n >> m >> x >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;

    vector w(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> w[i][j];
        }
    }

    vector f(n, vector<int>(m, inf)), g(n, vector<int>(m, inf));

    auto bfs = [&](int sx, int sy, auto &dis) {
        dis[sx][sy] = 0;
        queue<array<int, 2>> q;
        q.push({sx, sy});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto &[dx, dy] : d) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= n || b < 0 || b >= m || w[a][b] == -1 || dis[a][b] != inf) {
                    continue;
                }
                dis[a][b] = dis[x][y] + 1;
                q.push({a, b});
            }
        }
    };

    bfs(sx, sy, f);
    bfs(ex, ey, g); 

    int ans = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (w[i][j] > x) {
                ans = min(ans, f[i][j] + g[i][j]);
            }
        }
    }
    
    if (ans == inf) {
        ans = -1;
    }
    
    cout << ans << '\n';

    return 0;
}