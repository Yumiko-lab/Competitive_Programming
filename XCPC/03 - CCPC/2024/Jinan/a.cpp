#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    map<string, int> cnt;
    map<string, array<int, 2>> ids;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            string t = s.substr(j * k, k);
            cnt[t]++;
            ids[t] = {i + 1, j + 1};
        }
    }

    for (auto [x, y] : cnt) {
        if (y == 1) {
            cout << ids[x][0] << ' ' << ids[x][1] << '\n';
            break;
        }
    }

    return 0;
}