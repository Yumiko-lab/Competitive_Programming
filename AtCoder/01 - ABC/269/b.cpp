#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10, m = 10;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int A = -1, B = -1, C = -1, D = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                A = i + 1, C = j + 1;
                int x = i;
                while (x < n && s[x][j] == '#') {
                    x++;
                }
                B = x - 1 + 1;
                int y = j;
                while (j < m && s[i][y] == '#') {
                    y++;
                }
                D = y - 1 + 1;
                break;
            }
        }
        if (A != -1) {
            break;
        }
    }

    cout << A << ' ' << B << '\n';
    cout << C << ' ' << D << '\n';
    
    return 0;
}