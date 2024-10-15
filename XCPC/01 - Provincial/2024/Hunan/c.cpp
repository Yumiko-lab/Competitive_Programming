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

    if (s == 0) {
        return cout << 0, 0;
    }

    double down = log2(2024);
    double ans = 1;
    while (ans * down < s) {
        ans++;
    }
    cout << ans << '\n';

    return 0;
}