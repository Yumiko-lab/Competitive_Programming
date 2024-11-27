#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<int> dp(n + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (string t : {"ava", "avava"}) {
            int m = t.size();
            if (i - m + 1 >= 1 && s.substr(i - m + 1, m) == t) {
                dp[i] |= dp[i - m];
            }
        }
    }
    cout << (dp[n] ? "Yes" : "No") << '\n';
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