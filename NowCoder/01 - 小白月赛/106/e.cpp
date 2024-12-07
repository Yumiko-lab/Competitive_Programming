#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<array<int, 2>> mx(n, {-1, -1});

    auto dfs = [&](auto self, int u, int from) -> int {
        mx[u][0] = 1;
        for (auto v : adj[u]) {
            if (v == from) {
                continue;
            }
            int d = self(self, v, u) + 1;
            if (d >= mx[u][0]) {
                mx[u][1] = mx[u][0], mx[u][0] = d;
            } else if (d > mx[u][1]) {
                mx[u][1] = d;
            }
        }
        return mx[u][0];
    };

    dfs(dfs, 0, -1);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " : " << mx[i][0] << ' ' << mx[i][1] << '\n';
    }

    return 0;
}