#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << 1LL * (n - m) * (MOD + 1) / 2 % MOD << '\n';
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