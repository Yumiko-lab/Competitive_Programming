#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = n - 1;
    s += s;
    vector<int> last(26, -n);
    for (int i = 0; i < 2 * n; i++) {
        ans = min(ans, i - last[s[i] - 'a'] - 1);
        last[s[i] - 'a'] = i;
    }
    if (ans == n - 1) {
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