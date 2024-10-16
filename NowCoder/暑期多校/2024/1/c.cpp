#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500010, MOD = 1000000007;

int s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    int cnt = 0;
    while (q--) {
        int t, v;
        cin >> t >> v;
        cnt -= t;
        cnt++;
        s[cnt] = (s[cnt - 1] + 1LL * cnt * v % MOD) % MOD;
        cout << s[cnt] << '\n';
    }

    return 0;
}