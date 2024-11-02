#include <bits/stdc++.h>
using namespace std;

constexpr int N = 110, M = 15;

int n, m, MOD;
char s[N][N];
int a[N][N];
int f[N][N][M]; // f[i][j][k] : 从最后一行走到 (i, j) 且点权和 % (MOD + 1) = k 的最大点权和
int g[N][N][M]; // 记录转移: -1 = L, 1 = R

int get(int x) {
    return (x % (MOD + 1) + MOD + 1) % (MOD + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> MOD;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[i][j - 1] - '0';
        }
    }
    
    memset(f, -1, sizeof f);

    for (int j = 1; j <= m; j++) {
        f[n][j][get(a[n][j])] = a[n][j];
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= MOD; k++) { // % (MOD + 1) = 0 .. MOD
                // pull dp
                int w = a[i][j];
                if (j + 1 <= m && f[i + 1][j + 1][get(k - w)] != -1) {
                    if (f[i][j][k] < f[i + 1][j + 1][get(k - w)] + w) {
                        f[i][j][k] = f[i + 1][j + 1][get(k - w)] + w;
                        g[i][j][k] = -1;
                    }
                }
                if (j - 1 >= 1 && f[i + 1][j - 1][get(k - w)] != -1) {
                    if (f[i][j][k] < f[i + 1][j - 1][get(k - w)] + w) {
                        f[i][j][k] = f[i + 1][j - 1][get(k - w)] + w;
                        g[i][j][k] = 1;
                    }
                }
            }
        }
    }

    int mx = -1, mj = -1;
    for (int j = 1; j <= m; j++) {
        if (f[1][j][0] > mx) {
            mx = f[1][j][0];
            mj = j;
        }
    }

    if (mx == -1) {
        return cout << -1, 0;
    }

    cout << mx << '\n';

    stack<char> stk;
    int x = 1, y = mj, mod = 0;
    while (x < n) {
        char w = -1;
        int old = mod;
        mod = get(mod - a[x][y]);
        if (g[x][y][old] == -1) {
            w = 'L';
            y++;
        } else {
            w = 'R';
            y--;
        }
        x++;
        stk.push(w);
    }

    cout << y << '\n';
    do {
        cout << stk.top();
        stk.pop();
    } while (!stk.empty()); 

    return 0;
}