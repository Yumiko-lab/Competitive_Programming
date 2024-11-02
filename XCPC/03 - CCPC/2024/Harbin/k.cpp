#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info {
    int w, l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Info> a(n + 1);
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        int w, l, r;
        cin >> w >> l >> r;
        a[i] = {w, l, r};
        ans += 1LL * l * w;
        m -= l;
    }

    a[0].w = 1e9;
    sort(a.begin(), a.end(), [&](auto x, auto y) {
        return x.w > y.w;
    });

    for (int i = 1; i <= n; i++) {
        if (m == 0) {
            break;
        }
        int mn = min(m, a[i].r - a[i].l);
        m -= mn;
        ans += 1LL * a[i].w * mn;
    }



    return 0;
}