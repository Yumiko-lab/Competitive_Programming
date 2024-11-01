#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

string str = "NESW";

void solve() {
    int n;
    cin >> n;
    vector<pair<char, int>> a(n);
    for (auto &[d, x] : a) {
        cin >> d >> x;
    }
    cout << 2 * n - 1 << ' ' << a[0].x << '\n';
    for (int i = 0; i + 1 < n; i++) {
        cout << "Z " << a[i].y << '\n';
        int d = (str.find(a[i + 1].x) - str.find(a[i].x));
        cout << (d == -1 || d == 3? "L" : "R") << '\n';
    }
    cout << "Z " << a[n - 1].y << '\n';
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