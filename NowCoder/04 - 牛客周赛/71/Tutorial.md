# 牛客周赛 Round 71

[【题解】牛客周赛 Round 71 - 重生之我要当分子](https://ac.nowcoder.com/discuss/1445315?type=101%E2%88%A8der=3&pos=1&page=0&channel=-1&source_id=1) 

## A. 

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    cout << (k <= n - 1? "YES" : "NO") << '\n';

    return 0;
}
```

## B. 

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> p(26);
    for (int i = 0; i < n; i++) {
        p[s[i] - 'a'].push_back(i);
    }
    int ans = n;
    for (int i = 0; i < 26; i++) {
        if (!p[i].empty()) {
            int siz = p[i].size();
            for (int j = 1; j < siz; j++) {
                ans = min(ans, p[i][j] - p[i][j - 1] - 1);
            }
            if (siz > 1) {
                ans = min(ans, p[i][0] + n - p[i][siz - 1] - 1);
            }
        }
    }
    if (ans == n) {
        ans = -1;
    }
    cout << ans << '\n';
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
```

## C. 

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    map<char, int> cnt;
    for (auto c : s) {
        cnt[c] += 1;
    }

    cout << cnt.size() << '\n';

    return 0;
}
```

## D. 

全排列枚举三种颜色的顺序，然后 $dp$ 转移。



```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<int> ord {0, 1, 2};
    i64 ans = 1e18;
    do {
        vector f(n + 1, vector<i64>(3, 1e18));
        f[0] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k <= j; k++) {
                    f[i + 1][ord[j]] = min(f[i + 1][ord[j]], f[i][ord[k]] + (s[i] - '0' != ord[j]) * t[i]);
                }
            }
        }
        ans = min(ans, *min_element(f[n].begin(), f[n].end()));
    } while (next_permutation(ord.begin(), ord.end()));

    cout << ans << '\n';

    return 0;
}
```