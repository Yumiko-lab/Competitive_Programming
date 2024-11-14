#include <bits/stdc++.h>
using namespace std;

string S = "qkj";

void solve() {
    int n;
    cin >> n;
    vector a(3, vector<int>(n));
    vector pos(3, vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
            pos[i][a[i][j]] = j;
        }
    }

    
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

/*

1
3
1 3 2
2 1 3
1 2 3

*/