# 2024牛客暑期多校训练营8

## K. Haitang and Ava


非常经典的题目，布尔 DP 判断字符串拼接。


```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<int> dp(n + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (string t : {"ava", "avava"}) {
            int m = t.size();
            if (i - m + 1 >= 1 && s.substr(i - m + 1, m) == t) {
                dp[i] |= dp[i - m];
            }
        }
    }
    cout << (dp[n] ? "Yes" : "No") << '\n';
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

## A. 

> 看似博弈论，实际上是数论。

观察不难发现，集合最终会变成什么样是确定的，不会因为具体操作而改变，因此只需要统计一下总操作次数即可。

```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1E5;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(N + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (!cnt[i]) {
            int g = 0;
            for (int j = i; j <= N; j += i) {
                if (cnt[j]) {
                    g = __gcd(g, j);
                }
            }
            if (g == i) {
                ans++;
            }
        }
    }

    cout << (ans % 2 ? "dXqwq" : "Haitang") << '\n';
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

具体如何操作不会影响最终的集合的样子  =>  操作次数的奇偶性

*/
```

## E. 


> Description：
>
> 给定 $n$，问有多少 $m \le n$，满足 $n \bmod m = S(m)$，( $S(m)$ 为 $m$ 的十进制下数位和 )。
> - $1 \le n \le 1 \times 10^{12}$

**数位和的深刻理解**：

1. $S(m) \le 9 \lceil  \log_{10} m\rceil$。
2. 当 $m > 10$ 时，$S(m) < m$ 天然成立。




```cpp

```


## J. 

> Description：
>
> 构造一个长度为 $n$ 的排列，使得其中恰好有 $m$ 个长度为 $3$ 的子区间可以组成非退化三角形。
> - $3 \le n \le 3 \times 10^5$，$0 \le m \le n - 2$

构造题。



```cpp

```

## D. 


大模拟。


```cpp

```

---

## G. 

> Description：
>
> 


DP。


```cpp

```

其它题目暂时补不了，通过人数 $< 10$。

