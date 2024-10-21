#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int len = to_string(n).size();
    int p = pow(10, max(0, len - 3));

    cout << n / p * p << '\n';

    return 0;
}