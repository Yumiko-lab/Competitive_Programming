#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> g(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }

    vector<i64> f(1 << N);
    for (int s = 0; s < 1 << N; s++) {
        for (int i = 0; i < N; i++) {
            if (s >> i & 1) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (s >> j & 1) {
                    continue;
                }
                int t = s | (1 << i) | (1 << j);
                f[t] = max(f[t], f[s] + g[i][j]);
            }
        }
    }
    
    cout << f[(1 << N) - 1] << '\n';

    return 0;
}