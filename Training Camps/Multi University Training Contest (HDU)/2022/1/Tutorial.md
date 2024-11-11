# 2022 杭电多校 1


> 参考题解：
>
> - [Yijan - A ~ L - Blog](https://yijan.co/2022multiu1/) 
> - [NoobDream_ - BCDFGHIKL - Blog - CSDN](https://blog.csdn.net/qq_30320171/article/details/131252752) 
> - [Time_Limit_Exceeded - H - Blog - Acwing](https://www.acwing.com/solution/content/129999/) 



题解顺序优先按照题目相关性，然后按照题目难度排序。

> - 签到：
> - 铜牌：
> - 银牌：
> - 金牌：
> - 捧杯：
> - 防AK：


> 个人难度评价：
>
> - 基础：
> - 略有思维难度：
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
> 求体积**恰好**为 $m$，价值的**异或和**的最大值。




```cpp

```




## B. Dragon slayer



```cpp

```


## I. Laser



```cpp

```