#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            a[i][j] |= a[i - 1][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;
        int l = 0, r = n - 1;
        bool ok = true;
        for (int j = 0; j < m; j++) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            r--;
            if (o == '>') {
                int lo = 0, hi = n;
                while (lo < hi) {
                    int mi = (lo + hi) >> 1;
                    if (a[mi][r] > c) {
                        hi = mi;
                    } else {
                        lo = mi + 1;
                    }
                }
                if (lo < n && a[lo][r] <= c) {
                    ok = false;
                }
                l = max(l, lo);
            } else {
                int lo = -1, hi = n - 1;
                while (lo < hi) {
                    int mi = (lo + hi + 1) >> 1;
                    if (a[mi][r] < c) {
                        lo = mi;
                    } else {
                        hi = mi - 1;
                    }
                }
                if (lo >= 0 && a[lo][r] >= c) {
                    ok = false;
                }
                r = min(r, lo);
            }
        }
        if (!ok || l > r) {
            cout << "-1\n";
            continue;
        }
        cout << l + 1 << '\n';
    }

    return 0;
}

/*

3 4 1
1 3 5 9
4 6 5 3
2 1 2 7
1
3 > 5

*/