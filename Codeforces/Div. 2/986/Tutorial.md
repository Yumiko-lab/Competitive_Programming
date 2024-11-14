# Codeforces Round 986 (Div. 2)


> 参考题解：
>
> - [Official - Blog](https://codeforces.com/blog/entry/136096) 
> - [芋饼饭 - A ~ E - Video - Bilibili](https://www.bilibili.com/video/BV1WCmsYqEUv/)
> - [楜桃林東麓 - EF - Blog - Zhihu](https://zhuanlan.zhihu.com/p/6194889843) 
> - [FakeDuck - A ~ D - Blog - Zhihu](https://zhuanlan.zhihu.com/p/6092616433) 


[CLIST - Problems Rating Distribution](https://clist.by/problems/?resource=1&contest=54499723) 



## A. 

数据范围很小，直接暴力模拟 $1000$ 次，看是否可以到达即可。

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    int x = 0, y = 0;
    for (int i = 0; i < 1000; i++) {
        for (auto c : s) {
            if (c == 'N') {
                y++;
            } else if (c == 'E') {
                x++;
            } else if (c == 'S') {
                y--;
            } else {
                x--;
            }
            if (x == a && y == b) {
                cout << "YES\n";
                return;
            }
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


## B. 


```cpp

```


## C. 

思路非常好想，代码有点难写。


```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n + 1);
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    vector<int> f(n + 1), g(n + 2);
    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        sum += a[i];
        if (sum >= v) {
            sum = 0;
            f[i]++;
        }
    }
    sum = 0;
    for (int i = n; i >= 1; i--) {
        g[i] = g[i + 1];
        sum += a[i];
        if (sum >= v) {
            sum = 0;
            g[i]++;
        }
    }

    i64 ans = -1;
    for (int i = 0; i <= n; i++) {
        if (i == 0 || f[i] != f[i - 1]) {
            int lo = i + 1, hi = n + 1;
            while (lo < hi) {
                int mi = (lo + hi + 1) >> 1;
                if (g[mi] >= m - f[i]) {
                    lo = mi;
                } else {
                    hi = mi - 1;
                }
            }
            if (g[lo] >= m - f[i]) {
                ans = max(ans, s[lo - 1] - s[i]); // i + 1 .. lo - 1
            }
        }
    }

    for (int i = n + 1; i >= 1; i--) {
        if (i == n + 1 || g[i] != g[i + 1]) {
            int lo = 0, hi = i - 1;
            while (lo < hi) {
                int mi = (lo + hi) >> 1;
                if (f[mi] >= m - g[i]) {
                    hi = mi;
                } else {
                    lo = mi + 1;
                }
            }
            if (f[lo] >= m - g[i]) {
                ans = max(ans, s[i - 1] - s[lo]); // lo + 1 .. i - 1
            }
        }
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



## D. Alice's Adventures in Cards

> Description：
>
> Alice 准备和 Q, K, J 三个人换牌，Alice 初始只有牌 $1$，目标是换到牌 $n$。
> 
> Q, K, J 初始有 $1 \sim n$ 各一张牌，且他们对 $1 \sim n$ 所有牌的偏好可以看作是一个排列 $p$，若 $p_a > p_b$，则该牌手更偏爱 $a$，而不是 $b$。
>
> Alice 对牌的偏好是一个 $1 \sim n$ 的**正排列** ( 即牌的数字越大越好 )。
>
> 每一次换牌操作，Alice 可以随机选择一个人，但是**必须满足双方准备交换的牌都是对于自己来说更加偏好的牌**，问 Alice 是否可以从牌 $1$ 换到牌 $n$，如果可以输出具体换牌方案。


Alice 换牌的序列一定是一个递增的序列，即牌 $i$ 只能从 $1 \sim i - 1$ 换来，因此，可以直接枚举 $2 \sim n$，模拟每一张牌的换牌过程。

具体步骤：

从小到大枚举每张牌 $2 \sim n$，对每张牌枚举每个人，如果这个人前面的牌的 $rank$ 有比这张牌高的，就可以从前面那张牌转移过来，模拟这个过程即可。



```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector p(3, vector<int>(n));
    vector pos(3, vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
            p[i][j]--;
            pos[i][p[i][j]] = j;
        }
    }

    vector<array<int, 2>> g(n, {-1, -1});
    g[0] = {0, 0};

    int mx[3] {p[0][0], p[1][0], p[2][0]};
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (mx[j] > p[j][i]) {
                g[i] = {j, pos[j][mx[j]]};
            }
        }
        if (g[i][0] != -1) {
            for (int j = 0; j < 3; j++) {
                mx[j] = max(mx[j], p[j][i]);
            }
        }
    }

    if (g[n - 1][0] == -1) {
        cout << "NO\n";
        return;
    }

    vector<array<int, 2>> ans;
    for (int i = n - 1; i; ) {
        auto [j, x] = g[i];
        ans.push_back({j, i});
        i = x;
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << "qkj"[x] << ' ' << y + 1 << '\n';
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



## E. 


```cpp

```


## F. 


```cpp

```




