#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 5000010;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> p(N), mark(N);
    mark[1] = 1;

    for (int i = 2; i < N; i++) {
        if (!p[i]) {
            for (int j = i + i; j < N; j += i) {
                p[j] = 1;
            }
            for (i64 j = i; j < N; j *= i) {
                mark[j] = 1;
            }
        }
    }

    int ans = 0;
    vector<int> dp(n);
    auto dfs = [&](auto self, int u, int from) -> void {
        dp[u] = 1;
        for (auto v : adj[u]) {
            if (v == from) {
                continue;
            }
            self(self, v, u);
            if (!mark[__gcd(a[u], a[v])]) {
                dp[u] += dp[v];
            }
        }
        ans = max(ans, dp[u]);
    };
    
    dfs(dfs, 0, -1);

    cout << ans << '\n';

    return 0;
}