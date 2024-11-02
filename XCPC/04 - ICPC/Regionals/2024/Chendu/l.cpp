#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    cout << 100 << '\n';
    for (int i = 0; i < 50; i++) {
        cout << a << ' ';
    }
    for (int i = 0; i < 95 - 50; i++) {
        cout << b << ' ';
    }
    for (int i = 0; i < 99 - 95; i++) {
        cout << c << ' ';
    }
    cout << c + 1 << '\n';

    return 0;
}