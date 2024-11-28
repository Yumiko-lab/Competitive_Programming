#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    cerr << "---\n";

    i64 ans = n;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // i .. j - 1
            int cnt = 0;
            for (auto v : adj[j]) {
                if (v >= i && v < j) {
                    cnt++;
                }
            }
            if (cnt < j - i) { 
                i = j - 1;
                break;
            }
            ans += (j - i); // i .. j - 1
        }
    }

    cout << ans << '\n';

    return 0;
}