#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].emplace_back(i);
    }

    auto dfs = [&](auto self, int u) -> int {
        int mx = 0;
        for (auto v : adj[u]) {
            int d = self(self, v);
            mx = max(mx, d + 1);
        }
        return mx;
    };

    cout << dfs(dfs, 0) << '\n';
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