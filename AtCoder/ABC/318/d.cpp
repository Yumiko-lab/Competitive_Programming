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

    i64 ans = 0;
    vector<bool> used(N);
    auto dfs = [&](auto self, int u, i64 sum, int skip) -> void {
        if (u == N) {
            ans = max(ans, sum);
            return;
        }
        if (used[u]) {
            self(self, u + 1, sum, skip);
            return;
        }
        if (skip) {
            self(self, u + 1, sum, 0);
        }
        for (int i = u + 1; i < N; i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            self(self, u + 1, sum + g[u][i], skip);
            used[i] = false;
        }
    };

    dfs(dfs, 0, 0, N % 2);

    cout << ans << '\n';

    return 0;
}