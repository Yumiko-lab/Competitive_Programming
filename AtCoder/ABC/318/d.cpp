#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int M = N * (N - 1) / 2;
    vector<vector<int>> g(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }

    for (int i = 0; i < 1 << N; i++) {
        int cnt = __builtin_popcount(i);
        if (cnt % 2) {
            continue;
        }
        
    }



    return 0;
}