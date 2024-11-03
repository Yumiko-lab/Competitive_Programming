#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    auto check = [&](string &a, string &b) { // check whether a < b
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                return true;
            } else if (a[i] > b[i]) {
                return false;   
            }
        }
        return false;
    };

    char mn = '9';
    for (auto c : s) {
        mn = min(mn, c);
    }
    string ans = s;
    for (int i = 0; i < n; i++) {
        if (s[i] == mn) {
            string t;
            int j = 0;
            for (int j = 0; j < n; j++) {
                t += s[(i + j) % n];
            }
            if (check(t, ans)) {
                ans = t;
            }
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