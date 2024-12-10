# 牛客周赛 Round 70


> 参考题解：
>
> 1. [牛客周赛70题目讲解 - Bilibili - Video](https://www.bilibili.com/video/BV1jCzHYhEXV/) 
> 2. [牛客周赛70文字版本题解 - 重生之我要当分子](https://ac.nowcoder.com/discuss/1442948?type=101%E2%88%A8der=0&pos=2&page=0&channel=-1&source_id=1) 
> 3. [出题人的致歉信 - yeVegeTable](https://ac.nowcoder.com/discuss/1443253?type=101&order=0&pos=2&page=0&channel=-1&source_id=1) 
> 4. [牛客周赛 Round 70 A~G 题解 - AdviseDY](https://ac.nowcoder.com/discuss/1445102?type=101&order=0&pos=1&page=0&channel=-1&source_id=1) 





## A. 



```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    for (int i = 0; i < 4; i++) {
        if (a[i] != a[0]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    set<int> S;
    for (int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        S.insert(x);
    }
    cout << (S.size() == 1 ? "NO" : "YES") << '\n';
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

## B. 


```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, k, t;
    char c;
    cin >> x >> y >> k >> t >> c;

    int ans = -1;
    if (c == 'G') {
        if (k >= t) {
            ans = t;
        } else {
            ans = k + x + t;
        }
    } else {
        ans = k + t;
    }

    cout << ans << '\n';

    return 0;
}
```


## C. 


```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x + 1 << ' ' << x + 1 << '\n';
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
```

## D. 


```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }
    vector<int> mx(n);
    mx[0] = a[0];
    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i - 1], a[i]);
    }

    int ans = 0;
    for (int i = n - 1; i > 0; i--) {
        int r = k - (n - i - 1);
        if (r < 0) {
            break;
        }
        ans = max(ans, a[i] + mx[min(r, i - 1)]);
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

## E. 


找规律题。

naive 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

constexpr int inf = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<PII>> adj;

    set<PII> S;
    int mn = inf;
    auto dfs = [&](auto self, int u, int tar, int sum, int from) { // tar: Target
        if (sum > mn) {
            return;
        }
        if (u == tar) {
            mn = min(mn, sum);
            return;
        }
        for (auto [v, w] : adj[u]) {
            if (v == from || S.count({u, v})) {
                continue;                
            }
            S.insert({u, v});
            self(self, v, tar, sum + w, u);
            S.erase({u, v});
        }
    };

    auto naive = [&](int n) {
        adj = vector<vector<PII>>(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                adj[i].emplace_back(j, (i ^ j));
                adj[j].emplace_back(i, (i ^ j));                
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            S.clear();
            mn = inf;
            dfs(dfs, 1, i, 0, 0);
            ans ^= mn;
        }
        return ans;
    };

    int n = 15;
    for (int i = 1; i <= n; i++) {
        cout << i << " : " << naive(i) << '\n';
    }

    return 0;
}

/*

1: 0
2: 3
3: 5
4: 4
5: 


4k + 1 = 0
4k + 2 = n + 1
4k + 3 = 1
4k + 4 = n

*/
```

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int r = (n - 1) % 4;
    if (r == 0) {
        cout << 0;
    } else if (r == 1) {
        cout << n + 1;
    } else if (r == 2) {
        cout << 1;
    } else {
        cout << n;
    }
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
```

## F. 


```cpp

```

## G. 



```cpp

```

