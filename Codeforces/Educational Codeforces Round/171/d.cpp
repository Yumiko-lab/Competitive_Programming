#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 300010;

int n, q;
int a[N];
i64 s[N];
i64 cnt[N], sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    sum[1] = s[n];
    cnt[1] = n;
    for (int i = 2; i <= n; i++) {
        cnt[i] = cnt[i - 1] - 1;
        sum[i] = sum[i - 1] - a[i - 1] * (n - i + 2);
    }

    for (int i = 1; i <= n; i++) {
        cout << sum[i] << ' ';
    }
    cout << '\n';
    
    auto calc = [&](auto x) {
        return 0;
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << '\n';
    }

    return 0;
}