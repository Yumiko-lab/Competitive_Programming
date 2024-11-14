#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    int x = 0, y = 0;
    for (int i = 0; i < 1000; i++) {
        for (auto c : s) {
            if (c == 'N') {
                y++;
            } else if (c == 'E') {
                x++;
            } else if (c == 'S') {
                y--;
            } else {
                x--;
            }
            if (x == a && y == b) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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