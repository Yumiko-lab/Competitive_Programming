#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<int> a(k);
    map<int, int> cnt;
    for (auto &x : a) {
        cin >> x;
        cnt[x]++;
    }
    int n = -1, m = -1;
    for (auto x : a) {
        if ((k - 2) % x == 0 && (((k - 2) / x != x && cnt[(k - 2) / x] >= 1) || cnt[(k - 2) / x] >= 2)) {
            n = x, m = (k - 2) / x;
            break;
        }
    }
    cout << n << ' ' << m << '\n';
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