#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 x, y;
    cin >> x >> y;
    if (x == y) {
        cout << "0\n";
    } else {
        array<bool, 2> c{};
        for (int i = 60; i >= 0; i--) {
            int b1 = x >> i & 1;
            int b2 = y >> i & 1;
            if (b1 && !b2) {
                c[0] = true;
            }
            if (!b1 && b2) {
                c[1] = true;
            }
        }
        if (!c[0] || !c[1]) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
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