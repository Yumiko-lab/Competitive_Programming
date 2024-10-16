#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << "Yes\n";
    vector g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        g[0][i] = i + 1;
    }
    for (int i = 1; i < n; i++) {
        g[i][0] = i + n;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            g[i][j] = g[i][0];
        }
    }
    g[1][1] = 2 * n;
    for (int i = 2; i < n; i++) {
        g[1][i] = g[0][i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }

    // cout << "!!!\n";

    // for (int x = 0; x < n; x++) {
    //     for (int z = x + 1; z < n; z++) {
    //         for (int y = 0; y < n; y++) {
    //             for (int w = y + 1; w < n; w++) {
    //                 set<int> S = {g[x][y], g[x][w], g[z][y], g[z][w]};
    //                 if (S.size() == 4) {
    //                     cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << ' ' << w + 1 << '\n';
    //                 }
    //             }
    //         }
    //     }
    // }

    return 0;
}