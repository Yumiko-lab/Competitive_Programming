#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    vector<array<int, 2>> mx;
    
    DSU() {}
    DSU(int n) : p(n + 1), mx(n + 1, {-1, -1}) {
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
        // mx[y] = max(mx[y], mx[x])

        p[x] = y; // x -> y
        return true;
    }

    int get(int x) {
        return mx[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1);
    DSU dsu(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dsu.mx[i] = a[i];
    }

    vector<int> stk;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && a[i] <= a[stk.back()]) {
            int b = stk.back();
            dsu.merge(i, b);
            stk.pop_back();
        }
        stk.push_back(i);
        cout << i << " : ";
        for (auto x : stk) {
            cout << a[x] << ' ';
        }
        cout << '\n';
    }
    

    for (int i = 1; i <= n; i++) {
        cout << dsu.get(i) << ' ';
    }
    cout << '\n';
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

/*

1
4
2 1 1 3

1
4
1 1 3 1

1
8
2 4 1 6 3 8 5 7

*/