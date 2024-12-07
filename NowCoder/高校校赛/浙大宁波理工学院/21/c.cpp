#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> cnt;
    while (n--) {
        int x;
        cin >> x;
        cnt[x] += 1;
    }

    for (auto [x, y] : cnt) {
        if (y == 1) {
            cout << x << ' ';
        }
    }
    cout << '\n';

    return 0;
}