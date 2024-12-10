#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x + 1 << ' ' << x + 1 << '\n';
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