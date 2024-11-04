#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    array<int, 2> a{}, b{};
    while (n--) {
        int x;
        cin >> x;
        a[x % 2]++;
    }
    while (m--) {
        int x;
        cin >> x;
        b[x % 2]++;
    }

    cout << min(a[0], b[1]) + min(a[1], b[0]) << '\n';

    return 0;
}