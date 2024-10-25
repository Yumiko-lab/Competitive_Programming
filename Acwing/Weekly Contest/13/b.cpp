#include <bits/stdc++.h>
using namespace std;

constexpr int dir[][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S') {
                sx = i, sy = j;                
            }
        }
    }

    string op;
    cin >> op;

    vector<int> p{0, 1, 2, 3};

    auto vaild = [&](auto x, auto y) {
        return (x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#');
    };

    auto check = [&](auto p) {
        int x = sx, y = sy;
        for (auto c : op) {
            int w = c - '0';
            x += dir[p[w]][0], y += dir[p[w]][1];
            if (!vaild(x, y)) {
                return false;
            }
            if (s[x][y] == 'E') {
                return true;
            }
        }
        return false;
    };

    int ans = 0;
    do {
        if (check(p)) {
            ans++;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
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