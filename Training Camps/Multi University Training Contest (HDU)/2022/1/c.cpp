#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1 << 10;

int n, m;
bitset<N> f[N], g[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < N; i++) {
        f[i].reset();
    }
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = 0; j < N; j++) {
            g[j] = f[j];
        }
        // g = f[i - 1]
        for (int j = 0; j < N; j++) {
            f[j] |= (g[j ^ w] << v);
        }
    }

    int ans = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (f[i][m]) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
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