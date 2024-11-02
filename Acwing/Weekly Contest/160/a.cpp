#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x > 90 && x < 180) {
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}