#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r, k;
    cin >> l >> r >> k;

    auto calc = [&]() { // l .. r  and  k
        // int lo = 0, hi = r;
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
            return 0;
        }
        return lo - (l - 1);
    };

    cout << calc() << '\n';
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

1
1 1000000000 2

1
3 9 2

1
154 220 2

*/