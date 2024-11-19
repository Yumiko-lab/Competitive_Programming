#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

constexpr int dir[][2] = {
    {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<PII> S;
    while (m--) {
        int x, y;
        cin >> x >> y;
        S.insert({x, y});
        for (auto [dx, dy] : dir) {
            int a = x + dx, b = y + dy;
            if (a < 1 || a > n || b < 1 || b > n) {
                continue;
            }
            S.insert({a, b});
        }
    }

    cout << 1LL * n * n - S.size() << '\n';
    
    return 0;
}