#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<PII>> adj(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<i64> f(n);
    auto dfs = [&](auto self, int u, int from) -> void {
        f[u] = a[u];
        for (auto [v, w] : adj[u]) {
            if (v == from) {
                continue;
            }
            self(self, v, u);
            f[u] = max(f[u], f[u] + w + f[v]);
        }
    };

    dfs(dfs, 0, -1);

    cout << *max_element(f.begin(), f.end()) << '\n';

    return 0;
}