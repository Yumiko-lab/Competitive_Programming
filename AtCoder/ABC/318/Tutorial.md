# AtCoder Beginner Contest 318


[Problems](https://atcoder.jp/contests/abc318/tasks) 
[Problems Rating](https://clist.by/problems/?resource=93&contest=45373738) 


> Tutorials：
> 
> - [Official - Blog](https://atcoder.jp/contests/abc318/editorial) 
> - [AA競程 - A ~ G - Video - Bilibili](https://www.bilibili.com/video/BV1fu411A75W/) 
> - [Cranewilliams - A ~ G - Blog - Zhihu](https://zhuanlan.zhihu.com/p/653967493) 





## A. Full Moon

答案：

$$
\lceil \dfrac {N - M + 1}{P} \rceil
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, P;
    cin >> N >> M >> P;

    cout << (N - M + 1 + P - 1) / P << '\n';

    return 0;
}
```

## B. Overlapping sheets

正解是扫描线，但是数据范围较小可以直接暴力求解。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int M = 110;

    int N;
    cin >> N;

    bool vis[M][M]{};
    for (int i = 0; i < N; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        for (int x = A; x < B; x++) {
            for (int y = C; y < D; y++) {
                vis[x][y] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            ans += vis[i][j];
        }
    }
    cout << ans << '\n';

    return 0;
}
```

```cpp
bool vis[N][N]{} // 不能用在匿名函数中 auto dfs = [&](auto self ..)
```

## C. Blue Spring

贪心。

枚举使用的 "一日通" 票的数量，取最值。

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D, P;
    cin >> N >> D >> P;
    vector<i64> F(N);
    i64 sum = 0;
    for (auto &x : F) {
        cin >> x;
        sum += x;
    }
    sort(F.begin(), F.end(), greater<i64>());

    for (int i = 1; i < N; i++) {
        F[i] += F[i - 1];
    }

    int cnt = (N + D - 1) / D;

    i64 ans = sum;
    for (int i = 1; i <= cnt; i++) {
        ans = min(ans, 1LL * i * P + sum - F[min(N - 1, i * D - 1)]);
    }
    cout << ans << '\n';

    return 0;
}
```


## D. General Weighted Max Matching

> Description：
>
> 给定一个无向图，求其中端点不重合的边的集合的边权和的最大值。
> - $1 \le N \le 16$


### 状态压缩 DP

$f(s)$：表示当前已经配对的点的状态是 $s$ 的最大权值。

暴力枚举其中两个匹配的点即可。

时间复杂度：$\mathcal O(N^2 \times 2^N)$




```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> g(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }

    vector<i64> f(1 << N);
    for (int s = 0; s < 1 << N; s++) {
        for (int i = 0; i < N; i++) {
            if (s >> i & 1) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (s >> j & 1) {
                    continue;
                }
                int t = s | (1 << i) | (1 << j);
                f[t] = max(f[t], f[s] + g[i][j]);
            }
        }
    }
    
    cout << f[(1 << N) - 1] << '\n';

    return 0;
}
```

### DFS 暴搜

显然答案对应的点集已经唯一 ( 点数是偶数全选，奇数最后缺一个 )，也就是说只需要考虑如何配对所有点，使得最终权值和最大。

手玩一下发现方案数最多：$15 \times 13 \times 11 \times \cdots \times 1 = 2027025 \approx 2e6$

因此也可以直接暴搜，但是明显没有状压好写。

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> g(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }

    i64 ans = 0;
    vector<bool> used(N);
    auto dfs = [&](auto self, int u, i64 sum, int skip) -> void {
        if (u == N) {
            ans = max(ans, sum);
            return;
        }
        if (used[u]) {
            self(self, u + 1, sum, skip);
            return;
        }
        if (skip) {
            self(self, u + 1, sum, 0);
        }
        for (int i = u + 1; i < N; i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            self(self, u + 1, sum + g[u][i], skip);
            used[i] = false;
        }
    };

    dfs(dfs, 0, 0, N % 2);

    cout << ans << '\n';

    return 0;
}
```

### 带权带花树

待补。

[P6699 【模板】一般图最大权匹配](https://www.luogu.com.cn/problem/P6699) 


## E. Sandwiches


> 待整理优化 $\sum$ 的问题。


经典优化 $\sum$ 的问题。

此题枚举中间的数即可，枚举的途中维护左右两边的数集的增量。

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> L, R;
    for (auto &x : A) {
        cin >> x;
        R[x]++;
    }

    i64 ans = 0, now = 0;
    for (int i = 0; i < N; i++) {
        int x = A[i];
        R[x]--;
        now += -L[x];
        ans += now - (1LL * L[x] * R[x]);
        L[x]++;
        now += R[x];
    }

    cout << ans << '\n';

    return 0;
}
```

## F. Octopus

> Description：
>
> 


看起来很简单，实际上需要**非常敏锐和深刻的观察**。


观察：

1. 排序**手的长度** $L_{1 \sim n}$，对于某一个头的位置 $x$ 来说，显然有一个明显的贪心：根据距离宝藏的位置**从小到大依次分配**对应长度的手。




```cpp

```


## G. Typical Path Problem

> Description：
>
> 给定一张 $N$ 个点 $M$ 条边的无向图，同时给定三个点 $A, B, C$，问图中是否存在一条**依次**经过点 $A, B, C$ 的简单路径。

此题的做法非常多：

1. 网络流
2. 缩点 + 树链剖分 —— jiangly
3. 圆方树



```cpp

```


## Ex. Count Strong Test Cases


多项式待补。

```cpp

```


