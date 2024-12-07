#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> col(n);
    auto dfs = [&](auto self, int u, int from, int c) -> void {
        col[u] = c;
        for (auto v : adj[u]) {
            if (v == from || col[v]) {
                continue;
            }
            self(self, v, u, c ^ 1);
        }
    };
    
    dfs(dfs, 0, -1, 2);

    bool ok = true;
    int c = -1;
    while (k--) {
        int x;
        cin >> x;
        x--;
        if (c == -1) {
            c = col[x];
        } else if (c != col[x]) {
            ok = false;
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';

    return 0;
}