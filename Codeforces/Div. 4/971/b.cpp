#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i][j] == '#') {
                stk.push(j + 1);
            }
        }
    }
    do {
        cout << stk.top() << ' ';
        stk.pop();
    } while (!stk.empty());
    cout << '\n';
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