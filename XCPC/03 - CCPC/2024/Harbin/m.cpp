#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> divide(int n) {
    vector<int> d;
    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            d.emplace_back(i);
            if (i != n / i) {
                d.emplace_back(n / i);
            }
        }
    }
    sort(d.begin(), d.end());
    return d;
}

void solve() {
    int n;
    cin >> n;
    auto d = divide(n);
    i64 ans = 0;
    for (int i = 1; i < d.size(); i++) {
        ans += (1LL * d[i] - d[i - 1]) * (n / d[i - 1]);
    }
    cout << ans + 1 << '\n';
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