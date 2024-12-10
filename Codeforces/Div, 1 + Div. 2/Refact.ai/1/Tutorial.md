# Refact.ai Match 1 (Codeforces Round 985)

[Refact.ai Match 1 (Codeforces Round 985)](https://codeforces.com/contest/2029) 

[CLIST - Problems Rating Contribution](https://clist.by/problems/?resource=1&contest=54515779) 



> 参考题解：
>
> - [Official - Blog](https://codeforces.com/blog/entry/133516)
> - [楜桃林東麓 - A ~ E - Blog - Zhihu](https://zhuanlan.zhihu.com/p/5983087340) 


赛时题目通过惨状——

![Image](https://github.com/user-attachments/assets/dd801c9a-c8e5-4315-b41b-0d5b3a5f8d3b)


## A. 

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r, k;
    cin >> l >> r >> k;

    int lo = l, hi = r;
    while (lo < hi) {
        int mi = (lo + hi + 1) >> 1;
        if (r / mi >= k) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    if (r / lo < k) {
        return cout << "0\n", void();
    }
    cout << lo - (l - 1) << '\n';
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

void solve() {
    int n;
    string s, r;
    cin >> n >> s >> r;
    array<int, 2> cnt {};
    for (auto c : s) {
        cnt[c - '0']++;
    }
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        if (!cnt[0] || !cnt[1]) {
            ok = false;
            break;
        }
        cnt[0] -= 1, cnt[1] -= 1;
        cnt[r[i] - '0'] += 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
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

赛时没想到可以这样**状态机 DP**，属于是长见识了。

$f(i, 0/1/2)$：表示考虑前 $i$ 场比赛，且第 $i$ 场比赛在 Sikp 区间 **前/上/后** 的最大得分。

转移细节 —— 保证最多只有一段区间 Skip：



```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1E9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    array<int, 3> f {0, -INF, -INF}; // f[-1]
    for (int i = 0; i < n; i++) {
        f[2] = max(f[2], f[1]);
        f[1] = max(f[1], f[0]);
        for (int j = 0; j < 3; j++) {
            if (j == 1) {
                continue;
            }
            int &x = f[j];
            if (a[i] > x) {
                x++;
            } else if (a[i] < x) {
                x--;
            }
        }
    }
    cout << max(f[1], f[2]) << '\n';
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

```



## E. 

> Description：
> 
> 定义对 $x$ 的每次操作：$x$ 加上 $d$，$d > \ge 2$ 且 $d\mid x$。
> 
> 定义一个数字 $y$ 的 generator 是 $x$，当且仅当 $x$ 经过若干次操作之后可以变成 $y$。
> 
> 现在给定 $n$ 个整数 $a_{1 \sim n}$，问是否存在一个 $x$，使得 $x$ 是 $a_{1 \sim n}$ 的 generator。





```cpp

```


## F. 

> Description：
>
> 

```cpp

```



后续题目待补。
