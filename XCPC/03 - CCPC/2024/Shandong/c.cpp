#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first 
#define y second

constexpr int N = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<PII> segs(n);
    for (auto &[l, r] : segs) {
        cin >> l >> r;
    }
    sort(segs.begin(), segs.end());
    
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