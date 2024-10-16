#include <bits/stdc++.h>
#define int long long
using namespace std;
using PIII = tuple<int, int, int>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<vector<int>> adj(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    // f[i][j] : 从 1 .. i, 且前面已经连续 j 个节点不休息
    vector<vector<int>> f(n, vector<int>(k + 1, 1e18));
    auto dp = [&](auto s) {
        priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
        f[0][0] = a[0], f[0][1] = 1;
        heap.emplace(f[0][0], 0, 0);
        heap.emplace(f[0][1], 0, 1);
        while (!heap.empty()) {
            auto [d, u, c] = heap.top();
            heap.pop();
            for (auto v : adj[u]) {
                if (f[v][0] > f[u][c] + a[u]) {
                    f[v][0] = f[u][c] + a[u];
                    heap.emplace(f[v][0], v, 0);
                }
                if (c + 1 > k) {
                    continue;
                }
                if (f[v][c + 1] > f[u][c] + 1) {
                    f[v][c + 1] = f[u][c] + 1;
                    heap.emplace(f[v][c + 1], v, c + 1);
                }
            }
        }
    };

    dp(0);
    cout << *min_element(f[n - 1].begin(), f[n - 1].end()) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}