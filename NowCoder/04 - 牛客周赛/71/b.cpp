#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> p(26);
    for (int i = 0; i < n; i++) {
        p[s[i] - 'a'].push_back(i);
    }
    int ans = n;
    for (int i = 0; i < 26; i++) {
        if (!p[i].empty()) {
            int siz = p[i].size();
            for (int j = 1; j < siz; j++) {
                ans = min(ans, p[i][j] - p[i][j - 1] - 1);
            }
            if (siz > 1) {
                ans = min(ans, p[i][0] + n - p[i][siz - 1] - 1);
            }
        }
    }
    if (ans == n) {
        ans = -1;
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