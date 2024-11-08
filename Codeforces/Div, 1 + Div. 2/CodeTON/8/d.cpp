#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1010;

int n, k;
int a[N][N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> a[i][j];
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