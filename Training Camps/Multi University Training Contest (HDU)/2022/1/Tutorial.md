# 2022 杭电多校 1


> 参考题解：
>
> - [Yijan - A ~ L - Blog](https://yijan.co/2022multiu1/) 
> - [NoobDream_ - BCDFGHIKL - Blog - CSDN](https://blog.csdn.net/qq_30320171/article/details/131252752) 
> - [Time_Limit_Exceeded - H - Blog - Acwing](https://www.acwing.com/solution/content/129999/) 



题解顺序优先按照题目相关性，然后按照题目难度排序。

> - 签到：KL
> - 铜牌：C
> - 银牌：
> - 金牌：
> - 捧杯：
> - 防AK：


> 个人难度评价：
>
> - 基础：KC
> - 略有思维难度：L
> - 需要代码能力：
> - 需要细心思考：
> - 很天才的想法：
> - 暂时做不了：


## K. Random


> Description：
>
> 有 $n$ 个数，在 $[0, 1]$ 之间随机生成，进行 $m$ 次操作，每一次操作，$\dfrac 12$ 的概率删掉最大值，另 $\dfrac 12$ 的概率删掉最小值，问最终的 $n - m$ 个数的和的期望 ( $\bmod 1e9 + 7$ )。
> - $1 \le m \le n \le 1 \times 10^9$

直接将生成的 $n$ 个数都看作是 $\dfrac 12$，答案就是：

$$
\dfrac {(n - m)}2
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (n - m) * (MOD + 1LL) / 2 % MOD << '\n';
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




## L. Alice and Bob


> Description：
>
> 黑板上有 $n$ 个数字，范围在 $[0, n]$。
> 
> 每一次操作：若当前黑板上仍然有数字，且没有数字 $0$，Alice 可以将这些数字分成两个集合 ( 可以为空 )，Bob 选择一个集合并删掉集合内的所有数，并将另外一个集合内的所有数减去 $1$。
> 
> 在任何时刻，如果黑板上出现了数字 $0$，则 Alice 获胜，否则如果黑板上的所有数字都被 Bob 删掉了，则 Bob 获胜。
> 
> 问 Alice 和 Bob 都在采用最优策略博弈，最终谁会获胜。

有点天才想法的博弈，属实没想到。

题解做法：

把 $i$ 视作 $2^{n - i}$，那么 Alice 的目标等价于让黑板上出现 $2^n$，同时，每次 Bob 操作等价于让某个集合内的所有数乘上 $2$，然后删掉另一个集合。

而若集合中的和 $\ge 2^n$，那么一定能分成两个部分，使得每一个集合的和都大于等于 $2^{n - 1}$ (**因为不存在 $2^n$ 这个数，因此一定可以通过调整小于 $2^n$ 的数来做到**)，这样就递归到了子问题。

故直接判断初始集合内的数的总和是否大于等于 $2^n$ 即可。



```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        a[i - 1] += a[i] / 2;
    }
    cout << (a[0] > 0 ? "Alice" : "Bob") << '\n';
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


最初想法及代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    if (a[0] > 0) {
        return void(cout << "Alice\n");
    }
    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (sum - 1 >= i) {
            return void(cout << "Alice\n");
        }
    }
    cout << "Bob\n";
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




## C. Backpack


> Description：
>
> 有 $n$ 个物品，体积和价值分别为 $(v_i, w_i)$，和一个容量为 $m$ 的背包。
> 
> 求体积**恰好**为 $m$，价值的**异或和**的最大值。
> - $1 \le n, m, v_i, w_i < 2^{10}$


经典背包问题——

---

错误解法 —— **异或没有单调性**，$f(j)$ 的最值不一定由 $f(j - v)$ 的最值转移。

- 状态表示：

$f(i, j)$：考虑前 $i$ 个物品，且体积恰好为 $j$ 的价值的异或和的最大值。

初始状态：$\sum f(i) = \inf, f(0) = 0$

目标：$f(m)$


- 转移：

$$
f(i) = \max f(i - v_i) \oplus w_i
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1 << 11;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> f(N, -1);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            if (f[j - v] == -1) {
                continue;
            }
            f[j] = max(f[j], f[j - v] ^ w);
        }
    }
    cout << f[m] << '\n';
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

---


正确解法 —— 

观察到 $w_i < 2^{10}$，即最终异或和不会超过 $2^{10} - 1$，因此可以直接将元素异或和作为 DP 数组的一维。

- 状态表示：

$f(i, j, k)$：考虑前 $i$ 个物品，异或和为 $j$，体积为 $k$ 的物品组方案是否存在。

- 转移：

$$
f(i, j, k) = f(i - 1, j, k) \cup f(i - 1, j \oplus w_i, k - v_i)
$$



```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1 << 10;

int n, m;
bitset<N> f[N], g[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < N; i++) {
        f[i].reset();
    }
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = 0; j < N; j++) {
            g[j] = f[j];
        }
        // g = f[i - 1]
        for (int j = 0; j < N; j++) {
            f[j] |= (g[j ^ w] << v);
        }
    }

    int ans = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (f[i][m]) {
            ans = i;
            break;
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


## B. Dragon slayer

暴搜或状压。

```cpp

```


## I. Laser

> Description：
>
> 给定一个

计算几何。



```cpp

```

## A. 

前置：Board，KMP，扩展 KMP。


```cpp

```

## H. Path


分层图最短路。


```cpp

```

## G. 

Kruskal 重构树。

```cpp

```

