# AtCoder Beginner Contest 318


> Tutorials：
> 
> - [Official - Blog](https://atcoder.jp/contests/abc318/editorial) 
> - [AA競程 - A ~ G - Video - Bilibili](https://www.bilibili.com/video/BV1fu411A75W/) 





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

显然答案对应的点集已经唯一 ( 点数是偶数全选，奇数最后缺一个 )，也就是说只需要考虑如何配对所有点，使得最终权值和最大。

方案数最多：$15 \times 13 \times 11 \times \cdots \times 1 = 2027025 \approx 2e6$



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
    for (auto &x : A) {
        cin >> x;
    }

    map<int, int> L, R;
    
    for (auto x : A) {
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



## G. Typical Path Problem


## Ex. Count Strong Test Cases


