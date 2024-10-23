#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200010;

set<int> S[N];
multiset<int> T[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    while (q--) {
        int t, i, j;
        cin >> t >> i;
        if (t == 1) {
            cin >> j;
            S[i].insert(j);
            T[j].insert(i);
        } else if (t == 2) {
            for (auto x : T[i]) {
                cout << x << ' ';
            }
            cout << '\n';
        } else if (t == 3) {
            for (auto x : S[i]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}