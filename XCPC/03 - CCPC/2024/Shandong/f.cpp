#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 500010;

int n;
int a[N];
i64 suf[N];
i64 ans[N];

void solve() {
    int n;
    cin >> n;
    i64 s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += 1LL * i * a[i];
        suf[i] = a[i];
    }
    for (int i = n - 1; i >= 1; i--) {
        suf[i] += suf[i + 1];
    }
    sort(suf + 2, suf + 1 + n);
    ans[1] = s;
    for (int i = 2; i <= n; i++) {
        ans[i] = ans[i - 1] - suf[i];
    }
    for (int i = n; i >= 1; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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