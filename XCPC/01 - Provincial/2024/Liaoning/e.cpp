#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n * m & 1) {
        cout << "NO\n";
        return;
    }

    if (n % 4 == 0 or m % 4 == 0) {
        bool is = false;
        if(n % 4 != 0) {
            is = true;
            swap(n, m);
        }
        vector<vector<int>> g(n, vector<int>(m));
        int now = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i % 4 == 0) {
                    g[i][j] = now++;
                } else {
                    g[i][j] = g[i - 1][j];
                }
            }
        }
        cout << "YES\n";
        if (is) {
            swap(n, m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (is) {
                    cout << g[j][i] << " \n"[j == m - 1];
                } else {
                    cout << g[i][j] << " \n"[j == m - 1];
                }
            }
        }
    } else if (n % 2 == 0 and m % 2 == 0) {
        int now = 1;
        bool is = false;
        if (n <= 4 and m <= 4) {
            cout << "NO\n";
            return;
        } else if (n < m) {
            is = true;
            swap(n, m);
        }
        vector<vector<int>> g(n, vector<int>(m));
        for (int j = 0; j < m; j += 2) {
            g[0][j] = now;
            g[0][j + 1] = now;
            g[1][j] = now;
            g[2][j] = now;
            now += 1;

            g[n - 1][j] = now;
            g[n - 1][j + 1] = now;
            g[n - 2][j] = now;
            g[n - 3][j] = now;
            now += 1;

            for (int i = 3; i <= n - 4; i++) {
                if(i % 4 == 3) {
                    g[i][j] = now++;
                } else {
                    g[i][j] = g[i - 1][j];
                }
            }
            for (int i = 1; i <= n - 2; i++) {
                if (i % 4 == 1) {
                    g[i][j + 1] = now++;
                } else {
                    g[i][j + 1] = g[i - 1][j + 1];
                }
            }
        }
        if (is) {
            swap(n, m);
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (is) {
                    cout << g[j][i] << " \n"[j == m - 1];
                } else {
                    cout << g[i][j] << " \n"[j == m - 1];
                }
            }
        }
    } else {
        cout << "NO\n";
    }
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