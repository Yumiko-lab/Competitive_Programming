#include <bits/stdc++.h>
using namespace std;

vector<int> minp, primes;
vector<set<int>> f;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

struct DSU {
    vector<int> p, siz;
    
    DSU() {}
    DSU(int n) : p(n), siz(n, 1) {
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
        siz[y] += siz[x];
        p[x] = y; // x -> y
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(5E6);

    int n;
    cin >> n;
    f = vector<set<int>>(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x > 1) {
            int p = minp[x];
            x /= p;
            f[i].insert(p);
        }
    }

    DSU dsu(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int cnt = 0;
        if (f[u].size() > f[v].size()) {
            swap(u, v);
        }
        for (auto x : f[u]) {
            if (f[v].count(x)) {
                if (++cnt == 2) {
                    break;
                }
            }
        }
        if (cnt == 2) {
            dsu.merge(u, v);
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (dsu.p[i] == i) {
            mx = max(mx, dsu.size(i));
        }
    }

    cout << mx << '\n';

    return 0;
}