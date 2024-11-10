#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r, k;
    cin >> l >> r >> k;

    int lo = l, hi = r;
    while (lo < hi) {
        int mi = (lo + hi + 1) >> 1;
        if (r / mi >= k) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    if (r / lo < k) {
        return cout << "0\n", void();
    }
    cout << lo - (l - 1) << '\n';
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