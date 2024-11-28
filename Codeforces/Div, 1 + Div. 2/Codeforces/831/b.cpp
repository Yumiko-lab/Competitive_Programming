#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;

#define x first
#define y second

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    i64 sum = 0;
    for (auto &[x, y] : a) {
        cin >> x >> y;
        if (x < y) {
            swap(x, y);
        }
        sum += 2LL * (x + y);
    }
    sort(a.begin(), a.end(), [&](auto p, auto q) {
        return p.x > q.x;
    });
    for (int i = 1; i < n; i++) {
        sum -= a[i].x * 2;
    }
    cout << sum << '\n';
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