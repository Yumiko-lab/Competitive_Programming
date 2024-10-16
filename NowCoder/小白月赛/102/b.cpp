#include <bits/stdc++.h>
using namespace std;

void solve() {
    double a;
    cin >> a;
    cout << (a + sqrt(a * a + 4)) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}