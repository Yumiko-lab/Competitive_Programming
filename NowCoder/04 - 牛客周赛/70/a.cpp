#include <bits/stdc++.h>
using namespace std;

void solve() {
    set<int> S;
    for (int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        S.insert(x);
    }
    cout << (S.size() == 1 ? "NO" : "YES") << '\n';
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