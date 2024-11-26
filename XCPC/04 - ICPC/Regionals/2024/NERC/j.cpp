#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    i64 f = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        char e;
        int x;
        cin >> e >> x;
        if (e == 'P') {
            cnt += x;
        } else {
            i64 mn = min((i64)x, cnt);
            x -= mn, cnt -= mn;
            cout << (x > 0 ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}