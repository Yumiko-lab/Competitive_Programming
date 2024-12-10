#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, k, t;
    char c;
    cin >> x >> y >> k >> t >> c;

    int ans = -1;
    if (c == 'G') {
        if (k >= t) {
            ans = t;
        } else {
            ans = k + x + t;
        }
    } else {
        ans = k + t;
    }

    cout << ans << '\n';

    return 0;
}