#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> brd(k); // brand
    for (int i = 0; i < k; i++) {
        int b, c;
        cin >> b >> c;
        b--;
        brd[b].emplace_back(c);
    }
    vector<int> sum;
    int noe = 0; // non-empty
    for (int i = 0; i < k; i++) {
        if (!brd[i].empty()) {
            noe++;
            int s = 0;
            for (auto x : brd[i]) {
                s += x;
            }
            sum.emplace_back(s);
        }
    }
    sort(sum.begin(), sum.end(), greater<int>());
    int ans = 0;
    n = min(n, noe);
    for (int i = 0; i < n; i++) {
        ans += sum[i];
    }
    cout << ans << '\n';
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