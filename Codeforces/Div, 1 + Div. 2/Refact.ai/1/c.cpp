#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > x[i - 1]) {
            x[i] = x[i - 1] + 1;
        } else if (a[i] == x[i - 1]) {
            x[i] = x[i - 1];
        } else {
            x[i] = x[i - 1] - 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " \n"[i == n];
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

// 倍增
f[i][j]: 从 i 开始往后跳 2^j 步区间之后的得分

---

DP or Binary Search on Answer

*/