#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;
    char &mi = s[1];
    if (mi == '=') {
        if (s[0] < s[2]) {
            mi = '<';
        } else if (s[0] > s[2]) {
            mi = '>';
        }
    } else if (mi == '<') {
        if (s[0] == s[2]) {
            mi = '=';
        } else if (s[0] > s[2]) {
            mi = '>';
        }
    } else {
        if (s[0] == s[2]) {
            mi = '=';
        } else if (s[0] < s[2]) {
            mi = '<';
        }
    }
    cout << s << '\n';
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