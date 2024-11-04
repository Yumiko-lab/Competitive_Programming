#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 lcm(int x, int y) {
    return 1LL * x / __gcd(x, y) * y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    if (a < b) {
        swap(a, b);
    }

    array<i64, 2> ans{0, lcm(a, b)}; // {k = 0, lcm(a, b)}
    auto calc = [&](auto f) { // factor
        i64 k = f - (a % f), l = lcm(a + k, b + k);
        if (l < ans[1]) {
            ans = {k, l};
        }
    };

    int d = a - b;
    for (int i = 1; i <= d / i; i++) {
        if (d % i == 0) {
            calc(i);
            if (i != d / i) {
                calc(d / i);
            }
        }
    }

    cout << ans[0] << '\n';
    
    return 0;
}