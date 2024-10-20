#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int M = 110;

    int N;
    cin >> N;

    bool vis[M][M]{};
    for (int i = 0; i < N; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        for (int x = A; x < B; x++) {
            for (int y = C; y < D; y++) {
                vis[x][y] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            ans += vis[i][j];
        }
    }
    cout << ans << '\n';

    return 0;
}