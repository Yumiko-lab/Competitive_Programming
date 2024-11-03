#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    array<int, 26> cnt{};
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    int i = 0;
    while (k > cnt[i]) {
        k -= cnt[i++];
    }
    // k <= cnt[i]
    char c = (char)(i + 'a');
    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            p.emplace_back(i);
        }
    }
    int idx = p[p.size() - k];
    cout << c;
    for (int i = 0; i < n; i++) {
        if (i != idx) {
            cout << s[i];
        }
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

/*

1
5 2
cbaca

*/