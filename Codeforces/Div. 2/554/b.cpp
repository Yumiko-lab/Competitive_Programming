#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    vector<int> ans;

    while (true) {
        int lst = __builtin_ctz(x);
        ans.emplace_back(lst);
        x ^= (1 << lst) - 1;
        if (x + 1 == (x + 1 & -x - 1)) {
            break;
        }
        x += 1;
    }

    cout << 2 * ans.size() - 1 << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}