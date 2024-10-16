#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] == s[n - 1]) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cout << i << '\n';
            return;
        }
    }
    cout << "-1\n";
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