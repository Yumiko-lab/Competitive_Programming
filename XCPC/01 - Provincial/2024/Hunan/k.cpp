#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<PII>> adj(n);
    vector<i64> a(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    

    return 0;
}