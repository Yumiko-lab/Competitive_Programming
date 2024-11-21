#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 8> a {};
    for (auto &x : a) {
        cin >> x;
    }

    i64 ans = 0, f = 0;
    for (int i = 0; i < 8; i++) {
        a[i] += f;
        f = 0;
        int cnt = a[i] / 3;
        ans += 3LL * (i + 1) * cnt;
        f = cnt;
        a[i] %= 3;
        ans += min(cnt, a[i]) * (i + 1);
    }

    cout << ans << '\n';

    return 0;
}