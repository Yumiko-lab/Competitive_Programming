#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, siz;
    
    DSU() {}
    DSU(int n) : p(n + 1), siz(n + 1, 1) {
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
        siz[y] += siz[x];
        p[x] = y; // x -> y
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    DSU dsu(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != i) {
            dsu.merge(a[i], i);
        }
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.p[i] == i) {
            int siz = dsu.size(i);
            ans += siz / 3;
            cnt += (siz % 3 == 2);
        }
    }
    cout << ans + (cnt + 1) / 2 << '\n';
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