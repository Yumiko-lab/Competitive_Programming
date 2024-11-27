#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    // s[i] = a[i] - c[i] * b[i]
    vector<int> mxc(n);
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        mxc[i] = a[i] / b[i];
        sum += mxc[i];
    }

    if (sum < k) {
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        return 0;
    }

    

    return 0;
}