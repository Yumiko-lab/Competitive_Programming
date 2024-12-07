#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    string s, r;
    cin >> k >> s >> r;
    int n = s.size(), m = r.size();
    if (n < m) {
        cout << "0\n";
        return;
    }

    int ans = 0;
    for (int i = 0; i + m - 1 < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != r[j]) {
                cnt += 1;
            }
        }
        if (cnt == k) {
            ans += 1;
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