#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m, q;
    cin >> n >> k >> m >> q;

    vector<bool> in(n);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int t = 1;
        for (int j = 0; j < k; j++) {
            t = 1LL * t * x % n;
            in[t] = 1;
        }
    }

    while (q--) {
        int x;
        cin >> x;
        bool ok = true;
        int t = 1;
        for (int i = 0; i < k; i++) {
            t = 1LL * t * x % n;
            if (!in[t]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? 1 : 0) << ' ';
    }

    return 0;
}