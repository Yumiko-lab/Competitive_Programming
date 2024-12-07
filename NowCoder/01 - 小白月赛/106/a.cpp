#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b == 0) {
        cout << ((c + d) % 2 == 1 ? "YES" : "NO") << '\n';
        return 0;
    }

    if (a % 2 == 1) {
        if (c % 2 == 0) {
            cout << (d % 2 == 1 ? "YES" : "NO") << '\n';
        } else {
            cout << (d % 2 == 1 ? "NO" : "YES") << '\n';
        }
    } else { // a is even        
        cout << (d % 2 == 1 ? "YES" : "NO") << '\n';
    }

    return 0;
}