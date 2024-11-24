#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<array<int, 2>> ids;
    string t = "nanjing";
    s = s + s;
    for (int i = 0; i + 7 - 1 < 2 * n && i < n; i++) {
        if (s.substr(i, 7) == t) {
            ids.push_back({i, (i + 7 - 1) % n});
        }
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