#include <bits/stdc++.h>
using namespace std;

int f(int a, int b) {
    int i = b;
    while (i >= 2) {
        if (a % i == 0) {
            return a / i;
        }
        i -= 1;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += f(n, i);
    }
    cout << sum << '\n';

    return 0;
}