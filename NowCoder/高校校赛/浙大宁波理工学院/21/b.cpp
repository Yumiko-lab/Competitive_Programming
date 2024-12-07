#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> p(10);
    for (int i = 0; i < n; i++) {
        p[s[i] - '0'].emplace_back(i);
    }
    int cur = 0;
    for (int i = 9; i >= 0; i--) {
        bool swp = false;
        for (auto pos : p[i]) {
            if (pos != cur) {
                swap(s[p[i].back()], s[cur]);
                swp = true;
                break;
            } else {
                cur += 1;
            }
        }
        if (swp) {
            break;
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