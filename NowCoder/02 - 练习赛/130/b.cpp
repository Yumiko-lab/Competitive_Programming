#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, h, L, R;
    cin >> n >> k >> h >> L >> R;

    i64 mn = h + 1LL * L * k, mx = h + 1LL * R * k;

    if (mn > 0) {
        return cout << "impossible\n", 0;
    }

    // L < 0
    vector<int> a(n);
    for (int i = 0; i < k; i++) {
        a[i] = L;
    }

    i64 d = max(0LL, abs(mn) - abs(L) + 1);

    for (int i = 0; i < k; i++) {
        if (d == 0) {
            break;
        }
        i64 mn = min(1LL * R - a[i], d);
        a[i] += mn;
        d -= mn;
    }
    
    bool ok = true;
    int now = h;
    for (int i = 0; i < k; i++) {
        now += a[i];
        if (i != k - 1 && now <= 0) {
            ok = false;
            break;
        }
    }
    if (now > 0) {
        ok = false;
    }

    if (!ok) {
        return cout << "impossible\n", 0;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
    
    return 0;
}