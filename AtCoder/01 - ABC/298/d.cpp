#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto power10 = [&](int k) {
        int ans = 1;
        for (int i = 0; i < k; i++) {
            ans *= 10;
        }
        return ans;
    };

    deque<int> q(1, 1);

    int Q;
    cin >> Q;
    int ans = 1;
    while (Q--) {
        int t, x;
        cin >> t;
        if (t == 1) {
            cin >> x;
            q.emplace_back(x);
            ans = (ans * 10LL % MOD + x) % MOD;
        } else if (t == 2) {
            int f = q.front();
            int len = q.size();
            ans = (ans + MOD - f * power10(len - 1)) % MOD;
            q.pop_front();
        } else {
            cout << ans << '\n';
        }
    }

    return 0;
}