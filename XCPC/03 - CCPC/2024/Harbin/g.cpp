#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, siz;
    int cnt;

    DSU() {}
    DSU(int n) : p(n + 1), siz(n + 1, 1), cnt(n) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] > siz[y]) {
            swap(x, y);
        }
        cnt--;
        siz[y] += siz[x];
        p[x] = y;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> r;
    set<int> S;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        S.insert(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!S.count(i)) {
            r.emplace_back(i);
        }
    }
    if (r.empty()) {
        return cout << "No\n", 0;
    }

    DSU dsu(n);
    vector<vector<int>> adj(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        if (!S.count(u) && !S.count(v)) {
            dsu.merge(u, v);
        }
    }

    if (dsu.cnt > k + 1) {
        return cout << "No\n", 0;
    }

    vector<vector<int>> ans(n + 1);
    for (auto u : S) {
        bool ok = false;
        for (auto v : adj[u]) {
            if (!S.count(v) && dsu.size(v) == n - k) { // && dsu.size(v) == n - k
                ans[v].emplace_back(u);
                ok = true;
                break;
            }
        }
        if (!ok) {
            return cout << "No\n", 0;
        }
    }

    cout << "Yes\n";

    vector<vector<int>> print;

    for (int i = 1; i < n - k; i++) {
        ans[r[0]].emplace_back(r[i]);
    }

    vector<int> t;
    t.emplace_back(r[0]);
    t.emplace_back(ans[r[0]].size());
    for (auto x : ans[r[0]]) {
        t.emplace_back(x);
    }
    print.emplace_back(t);

    for (int i = 1; i <= n; i++) {
        if (i != r[0] && ans[i].size() > 0) {
            vector<int> t;
            t.emplace_back(i);
            t.emplace_back(ans[i].size());
            for (auto x : ans[i]) {
                t.emplace_back(x);
            }
            print.emplace_back(t);
        }
    }

    cout << print.size() << '\n';
    for (auto v : print) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}