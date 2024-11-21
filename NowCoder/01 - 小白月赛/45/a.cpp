#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;
    if (n <= x) {
        cout << 1LL * n * x << '\n';
    } else {
        cout << x << '\n';
    }

    return 0;
}