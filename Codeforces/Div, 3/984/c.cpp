#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    multiset<int> ids; // 1100 (第一个'1'的坐标)
    for (int i = 0; i + 3 < n; i++) {
        if (s.substr(i, 4) == "1100") {
            ids.insert(i);
        }
    }

    while (q--) {
        int i, v;
        cin >> i >> v;
        i--;
        if (s[i] - '0' == v) {
            cout << (ids.empty() ? "NO" : "YES") << '\n';
            continue;    
        }
        vector<int> bup = {i, i - 1, i - 2, i - 3};
        for (auto x : bup) {
            if (ids.find(x) != ids.end()) {
                ids.erase(ids.lower_bound(x));
            }
        }
        s[i] ^= 1;
        for (auto x : bup) {
            if (x >= 0 && x + 3 < n && s.substr(x, 4) == "1100") {
                ids.insert(x);
            }
        }
        cout << (ids.empty() ? "NO" : "YES") << '\n';
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