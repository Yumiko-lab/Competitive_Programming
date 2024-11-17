#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 5) {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> p(2);
    for (int i = 1; i <= n; i++) {
        p[i % 2].push_back(i);
    }
    swap(p[1][0], p[1][2]);
    reverse(p[1].begin(), p[1].end());
    for (auto x : p[1]) {
        cout << x << ' ';
    }
    swap(p[0][0], p[0][1]);
    for (auto x : p[0]) {
        cout << x << ' ';
    }
    cout << '\n';
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