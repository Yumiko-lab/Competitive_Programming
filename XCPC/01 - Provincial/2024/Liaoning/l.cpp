#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 k;

i64 calc(i64 x) {
    i64 sum = x / 4; // + x / 400 - x / 400
    
    return x - sum;
}

bool check(i64 mi) {
    return calc(mi) - calc(2024) >= k;
}

void solve() {
    cin >> k;
    i64 lo = 1, hi = 1e18;
    while (lo < hi) {
        i64 mi = (lo + hi) >> 1;
        if (check(mi)) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << 2024 + lo << '\n';
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