#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            cout << i + 1 << ' ' << i + 1 << ' ';
        }
        cout << '\n';
    } else {
        if (n < 9) {
            cout << "-1\n";
        } else {
            int c = 2;
            cout << 1 << ' ';
            for (int i = 0; i < 8 / 2; i++) {
                cout << c << ' ' << c << ' ';
                c++;
            }
            
        }
    }
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