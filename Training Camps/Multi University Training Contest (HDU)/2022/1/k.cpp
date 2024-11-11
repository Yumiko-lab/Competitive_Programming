#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (n - m) * (MOD + 1LL) / 2 % MOD << '\n';
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