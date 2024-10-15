#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for (auto &x : a) {
        cin >> x;
        s += __lg(x);
    }

    cout << (s + 9) / 10 << '\n';

    return 0;
}