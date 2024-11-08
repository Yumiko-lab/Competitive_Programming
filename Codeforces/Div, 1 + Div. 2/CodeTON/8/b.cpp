#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    vector<int> a(n), p(n);
    for (auto &x:  a) {
        cin >> x;
    }
    p[0] = (a[0] == 1 ? 0 : -a[0]);
    p[n - 1] = n - a[n - 1];
    
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