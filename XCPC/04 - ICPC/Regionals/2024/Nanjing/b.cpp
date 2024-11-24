#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    string t;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        if (j - i & 1) {
            t += s[i];
        }
        i = j - 1;
    }
    // cout << t << '\n';
    cout << t.size() << ' ' << t << '\n';
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