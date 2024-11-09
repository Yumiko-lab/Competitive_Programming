#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int k = 2; k <= 10; k++) {
        cout << k << " : ";
        int a1 = k * (k - 1) / 2;
        for (int i = 0; i < 20; i++) {
            cout << a1 + i * k << ' ';
        }
        cout << '\n';
    }

    return 0;
}