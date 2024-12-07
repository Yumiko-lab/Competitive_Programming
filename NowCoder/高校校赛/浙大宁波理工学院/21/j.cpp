#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    array<int, 2> S {}, T {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 1) {
                S = {i, j};
                int x = i, y = j;
                while (g[x][y] == 1) {
                    y += 1;
                }
                y -= 1;
                while (g[x][y] == 1) {
                    x += 1;
                }
                x -= 1;
                T = {x, y};
                break;
            }
        }
        if (S != array<int, 2> {}) {
            break;
        }
    }
    bool has = false;
    for (int x = S[0]; x <= T[0]; x++) {
        for (int y = S[1]; y <= T[1]; y++) {
            if (g[x][y] == 0) {
                has = true;
            }
        }
    }
    cout << (has ? "Yes" : "No") << '\n';
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