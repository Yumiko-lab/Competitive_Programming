#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];

    auto check = [&](char w) {
        if (s[0][0] == w && s[1][1] == w && s[2][2] == w) {
            return true;
        }
        if (s[0][2] == w && s[1][1] == w && s[2][0] == w) {
            return true;
        }
        for (int i = 0; i < 3; i++) {
            bool row = true;
            for (int j = 0; j < 3; j++) {
                if (s[i][j] != w) {
                    row = false;
                    break;
                }
            }
            if (row) {
                return true;
            }
        }
        for (int i = 0; i < 3; i++) {
            bool col = true;
            for (int j = 0; j < 3; j++) {
                if (s[j][i] != w) {
                    col = false;
                    break;
                }
            }
            if (col) {
                return true;
            }
        }
        return false;
    };

    cout << (check('X') ? "Qfish win!" : "lumo win!") << '\n';

    return 0;
}