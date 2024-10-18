#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    if (n < k) {
        cout << "NO\n";
        return;
    }
    set<int> S;
    for (auto x : a) {
        if (!S.count(x) && x >= 1 && x <= k) {
            S.insert(x);
        }
    }
    cout << (S.size() == k ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}