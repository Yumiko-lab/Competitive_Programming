#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector p(3, vector<int>(n));
    vector pos(3, vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
            p[i][j]--;
            pos[i][p[i][j]] = j;
        }
    }

    vector<array<int, 2>> g(n, {-1, -1});
    g[0] = {0, 0};

    int mx[3] {p[0][0], p[1][0], p[2][0]};
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (mx[j] > p[j][i]) {
                g[i] = {j, pos[j][mx[j]]};
            }
        }
        if (g[i][0] != -1) {
            for (int j = 0; j < 3; j++) {
                mx[j] = max(mx[j], p[j][i]);
            }
        }
    }

    if (g[n - 1][0] == -1) {
        cout << "NO\n";
        return;
    }

    vector<array<int, 2>> ans;
    for (int i = n - 1; i; ) {
        auto [j, x] = g[i];
        ans.push_back({j, i});
        i = x;
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << "qkj"[x] << ' ' << y + 1 << '\n';
    }
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