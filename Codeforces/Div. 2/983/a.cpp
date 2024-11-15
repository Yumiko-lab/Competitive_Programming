#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    array<int, 2> cnt{};
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    cout << cnt[1] % 2 << ' ' << (cnt[1] < n ? cnt[1] : 2 * n - cnt[1]) << '\n';
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