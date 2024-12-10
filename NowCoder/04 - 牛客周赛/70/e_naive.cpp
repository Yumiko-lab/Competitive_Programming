#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

constexpr int inf = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<PII>> adj;

    set<PII> S;
    int mn = inf;
    auto dfs = [&](auto self, int u, int tar, int sum, int from) { // tar: Target
        if (sum > mn) {
            return;
        }
        if (u == tar) {
            mn = min(mn, sum);
            return;
        }
        for (auto [v, w] : adj[u]) {
            if (v == from || S.count({u, v})) {
                continue;                
            }
            S.insert({u, v});
            self(self, v, tar, sum + w, u);
            S.erase({u, v});
        }
    };

    auto naive = [&](int n) {
        adj = vector<vector<PII>>(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                adj[i].emplace_back(j, (i ^ j));
                adj[j].emplace_back(i, (i ^ j));                
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            S.clear();
            mn = inf;
            dfs(dfs, 1, i, 0, 0);
            ans ^= mn;
        }
        return ans;
    };

    int n = 15;
    for (int i = 1; i <= n; i++) {
        cout << i << " : " << naive(i) << '\n';
    }

    return 0;
}

/*

1: 0
2: 3
3: 5
4: 4
5: 


4k + 1 = 0
4k + 2 = n + 1
4k + 3 = 1
4k + 4 = n

*/