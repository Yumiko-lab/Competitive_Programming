#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<int> ord {0, 1, 2};
    i64 ans = 1e18;
    do {
        vector f(n + 1, vector<i64>(3, 1e18));
        f[0] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k <= j; k++) {
                    f[i + 1][ord[j]] = min(f[i + 1][ord[j]], f[i][ord[k]] + (s[i] - '0' != ord[j]) * t[i]);
                }
            }
        }
        ans = min(ans, *min_element(f[n].begin(), f[n].end()));
    } while (next_permutation(ord.begin(), ord.end()));

    cout << ans << '\n';

    return 0;
}