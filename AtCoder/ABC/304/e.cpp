#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

struct DSU {
    vector<int> p;
    
    DSU() {}
    DSU(int n) : p(n + 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y); 
    }
    
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        p[x] = y; // x -> y
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }

    set<PII> S;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x = dsu.find(x), y = dsu.find(y);
        S.insert({x, y});
        S.insert({y, x});
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int p, q;
        cin >> p >> q;
        p = dsu.find(p), q = dsu.find(q);
        cout << (!S.count({p, q}) ? "Yes" : "No") << '\n';
    }
    cout << '\n';

    return 0;
}