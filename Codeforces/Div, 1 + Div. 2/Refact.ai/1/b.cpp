#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s, r;
    cin >> n >> s >> r;
    array<int, 2> cnt{};
    for (auto c : s) {
        cnt[c - '0']++;
    }
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        if (!cnt[0] || !cnt[1]) {
            ok = false;
            break;
        }
        cnt[0] -= 1, cnt[1] -= 1;
        cnt[r[i] - '0'] += 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
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

/*

1
4
1101
001

*/