#include <bits/stdc++.h>
using namespace std;

constexpr int dir[][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

string s = "NESW";

void solve() {
    int n, a, b;
    string t;
    cin >> n >> a >> b >> t;
    int x = 0, y = 0;
    for (auto c : t) {
        int p = s.find(c);
        x += dir[p][0], y += dir[p][1];
        // if (x == a && y == b) {
        //     return cout << "YES\n", void();
        // }
    }
    cout << x << ' ' << y << '\n';
    // if (a * x < 0 || b * y < 0) {
    //     return cout << "NO\n", void();
    // }
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