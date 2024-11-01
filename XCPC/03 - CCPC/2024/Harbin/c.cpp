#include <bits/stdc++.h>
using namespace std;

string str = "NESW";

struct Dir {
    char d;
    int x;
};

void solve() {
    int n;
    cin >> n;
    vector<Dir> a(n);
    int hor = 0, ver = 0;
    for (auto &[d, x] : a) {
        cin >> d >> x;
        if (d == 'N') {
            hor += x;
        } else if (d == 'S') {
            hor -= x;
        } else if (d == 'E') {
            ver += x;
        } else {
            ver -= x;
        }
    }
    cout << "3 ";
    cout << (hor > 0 ? "N" : "S") << '\n';
    cout << "Z " << abs(hor) << '\n';
    if (hor > 0) {
        cout << (ver > 0 ? "R" : "L") << '\n';
    } else {
        cout << (ver > 0 ? "L" : "R") << '\n';
    }
    cout << "Z " << abs(ver) << '\n';
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
3
S 3
W 2
N 1

*/