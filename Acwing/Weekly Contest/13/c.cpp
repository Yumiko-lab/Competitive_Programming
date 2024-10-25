#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> adj(n);
    vector<int> din(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        din[v]++;
    }

    vector<int> seq;
    auto topo = [&]() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (din[i] == 0) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            seq.emplace_back(u);
            for (auto v : adj[u]) {
                if (--din[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    };

    topo();

    if (seq.size() < n) {
        return cout << -1, 0;
    }

    vector f(26, vector<int>(n));
    for (int i = 0; i < n; i++) { // initialization the value of 0 indegree Node
        f[s[i] - 'a'][i] = 1;
    }

    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        int w = c - 'a';
        for (auto u : seq) {
            for (auto v : adj[u]) {
                f[w][v] = max(f[w][v], f[w][u] + (s[v] == c));
            }
            ans = max(ans, f[w][u]);
        }
    }
    cout << ans << '\n';

    return 0;
}