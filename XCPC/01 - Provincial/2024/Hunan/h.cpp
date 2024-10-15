#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string s;
    cin >> n >> k >> s;

    int m = s.size();
    if (m * k > n) {
        return cout << 0, 0;
    }

    int r = n - m * k;

    int ans = 1;
    for (int i = 0; i < r; i++) {
        ans = ans * 26 % MOD;
    }

    for (int i = 0; i < r; i++) {
        ans = ans * (k + 1) % MOD;
    }

    cout << ans << '\n';

    return 0;
}