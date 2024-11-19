#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D, P;
    cin >> N >> D >> P;
    vector<i64> F(N);
    i64 sum = 0;
    for (auto &x : F) {
        cin >> x;
        sum += x;
    }
    sort(F.begin(), F.end(), greater<i64>());

    for (int i = 1; i < N; i++) {
        F[i] += F[i - 1];
    }
    int cnt = (N + D - 1) / D;

    i64 ans = sum;
    for (int i = 1; i <= cnt; i++) {
        ans = min(ans, 1LL * i * P + sum - F[min(N - 1, i * D - 1)]);
    }

    cout << ans << '\n';

    return 0;
}