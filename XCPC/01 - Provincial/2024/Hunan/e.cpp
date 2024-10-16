#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20, M = (1 << N) - 1;

int f[1 << N], g[1 << N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x = (1 << x);
    }

    int s = 0, cnt = 0; // state
    for (int i = 0; i < n; i++) {
        if ((s & a[i])) {
            s = a[i];
            cnt = 1;
            f[s] = max(f[s], cnt);
        } else {
            s |= a[i];
            cnt++;
            f[s] = max(f[s], cnt);
        }
    }

    for (int s = 0; s < 1 << N; s++) {
        g[s] = f[s];
        for (int i = 0; i < 20; i++) {
            if (s & (1 << i)) {
                g[s] = max(g[s], g[s ^ (1 << i)] + 1);
            }
        }
    }

    int mx = 0;
    for (int s = 0; s < 1 << N; s++) {
        mx = max(mx, g[s] + g[M ^ s]);
    }

    cout << mx << '\n';

    return 0;
}