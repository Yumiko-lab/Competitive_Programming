#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

constexpr int dir[][2] = {
    {-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}
};

struct DSU {
    vector<int> p;
    int cnt;
    
    DSU() {}
    DSU(int n) : p(n + 1), cnt(n) {
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
        cnt--;
        p[x] = y; // x -> y
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    DSU dsu(n);
    
    vector<PII> acc(n);
    map<PII, int> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        acc[i] = {x, y};
        mp[{x, y}] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        for (auto [dx, dy] : dir) {
            int a = acc[i].x + dx, b = acc[i].y + dy;
            if (mp.count({a, b})) {
                dsu.merge(i + 1, mp[{a, b}]);
            }
        }
    }

    cout << dsu.cnt << '\n';
    
    return 0;
}