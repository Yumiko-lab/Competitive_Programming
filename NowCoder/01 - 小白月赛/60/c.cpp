#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> f(n + 1), g(n + 1);

    for (int i = 1; i <= n; i++) {
        f[i] = g[max(0, i - k - 1)] + a[i];
        g[i] = max(g[i - 1], f[i]);
    }

    cout << g[n] << '\n';

    return 0;
}