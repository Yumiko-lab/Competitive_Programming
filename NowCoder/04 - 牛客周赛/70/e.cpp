#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int r = (n - 1) % 4;
    if (r == 0) {
        cout << 0;
    } else if (r == 1) {
        cout << n + 1;
    } else if (r == 2) {
        cout << 1;
    } else {
        cout << n;
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