#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<double> f(X + 1); // f[i][j]: 考虑前 i 个物品, 且获得 j 张卡牌的期望开包次数

    for (auto p : P) {
        for (int x = X; x >= 1; x--) {
            
        }
    }

    cout << setprecision(8) << f[X] << '\n';

    return 0;
}