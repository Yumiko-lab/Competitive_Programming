#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1E5;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(N + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (!cnt[i]) {
            int g = 0;
            for (int j = i; j <= N; j += i) {
                if (cnt[j]) {
                    g = __gcd(g, j);
                }
            }
            if (g == i) {
                ans++;
            }
        }
    }

    cout << (ans % 2 ? "dXqwq" : "Haitang") << '\n';
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

/*

具体如何操作不会影响最终的集合的样子  =>  操作次数的奇偶性

*/