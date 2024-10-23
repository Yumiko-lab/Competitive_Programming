#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    vector b(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    auto check = [&](auto a, auto b) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1 && b[i][j] != 1) {
                    return false;
                }
            }
        }
        return true;
    };
    
    bool ok = false;
    for (int k = 0; k < 4; k++) {
        vector t(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                t[i][j] = a[j][n - i - 1];
            }
        }
        if (check(t, b)) {
            ok = true;
            break;
        }
        a = t;
    }

    cout << (ok ? "Yes" : "No") << '\n';    

    return 0;
}