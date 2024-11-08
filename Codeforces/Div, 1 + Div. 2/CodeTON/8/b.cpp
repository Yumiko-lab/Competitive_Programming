#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (auto &x:  a) {
        cin >> x;
    }
    int mex = n, cur = n - 1;
    while (cur >= 0) {
        p[cur] = mex - a[cur];
        if (p[cur] < mex) {
            mex = p[cur];
        }
        cur--;
    }
    for (auto x : p) {
        cout << x << ' ';
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