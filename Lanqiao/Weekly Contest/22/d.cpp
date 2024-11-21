#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int mn = 1e9;
    for (auto &x : a) {
        cin >> x;
        mn = min(mn, x);
    }

    i64 ans = 0;
    for (auto x : a) {
        ans += x - mn;
    }
    cout << ans << '\n';

    return 0;
}