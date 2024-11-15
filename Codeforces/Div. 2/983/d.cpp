#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 2; i < n; i++) { // query(1, 2 .. n - 1)
        int ans = query(1, i);
        if (ans == 0) {
            p[i] = 1;
        } else {
            p[i] = 0;
        }
    }

    cout << "! ";
    for (int i = 1; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}