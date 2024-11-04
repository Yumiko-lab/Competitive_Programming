#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> f(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i] >> a[i];
        adj[f[i]].emplace_back(i);
    }

    vector<i64> sum(n + 1);

    auto dfs = [&](auto self, auto u) -> void {
        if (adj[u].empty()) {
            sum[u] = a[u];
            return;
        }
        for (auto v : adj[u]) {
            self(self, v);
            sum[u] += sum[v];
        }
    };

    dfs(dfs, 0);

    if (sum[0] > 2200) {
        return cout << "NO\n", 0;
    }

    vector<int> w, p;
    for (int i = 1; i <= n; i++) {
        if (!adj[i].empty()) {
            w.emplace_back(sum[i]);
            p.emplace_back(a[i]);
        }
    }
    sort(w.begin(), w.end(), greater<int>());
    sort(p.begin(), p.end(), greater<int>());

    int siz = w.size();
    for (int i = 0; i < siz; i++) {
        if (w[i] > p[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";

    return 0;
}