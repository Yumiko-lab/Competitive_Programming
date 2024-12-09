#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

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

    array<int, 3> f {inf, inf, inf}, g {};
    for (int i = 0; i < n; i++) {
        for (auto c : {0, 1, 2}) {
            f[c] = min(f[c], g[c] + ((s[i] - '0') != c ? t[i] : 0));
        }
        g = f;
    }

    cout << *min_element(f.begin(), f.end()) << '\n';

    return 0;
}

/*

f[i][c]: 表示考虑 1 .. i 且以颜色 c 为结尾且满足相同颜色的气球都在一起的最小代价

f[i][c] = min() + (s[i] != c ? t[i] : 0);

*/