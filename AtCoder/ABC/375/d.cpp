#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> pos(26);

    for (int i = 0; i < n; i++) {
        pos[s[i] - 'A'].emplace_back(i);
    }

    i64 res = 0;
    for (int i = 0; i < 26; i++) {
        i64 t = res;
        i64 s = 0;
        for (int j = 1; j < pos[i].size(); j++) {
            i64 now = pos[i][j] - pos[i][j - 1] - 1;
            s += j * now + (j - 1);
            res += s;
        }
    }
    cout << res << '\n';

    return 0;
}