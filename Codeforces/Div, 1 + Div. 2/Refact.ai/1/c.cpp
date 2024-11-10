#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1E9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    array<int, 3> f {0, -INF, -INF}; // f[-1]
    for (int i = 0; i < n; i++) {
        f[2] = max(f[2], f[1]);
        f[1] = max(f[1], f[0]);
        for (int j = 0; j < 3; j++) {
            if (j == 1) {
                continue;
            }
            int &x = f[j];
            if (a[i] > x) {
                x++;
            } else if (a[i] < x) {
                x--;
            }
        }
    }
    cout << max(f[1], f[2]) << '\n';
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