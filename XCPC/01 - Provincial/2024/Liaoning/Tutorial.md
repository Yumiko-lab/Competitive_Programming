# 2024 CCPC Liaoning Provincial Contest

2024 CCPC Liaoning Provincial Contest, 2024 CCPC 辽宁省赛

> 参考题解：
>
> 

题解顺序优先按照题目相关性，然后按照题目难度排序。

> - 签到：BJA
> - 铜牌：C
> - 银牌：EL
> - 金牌：DGMK
> - 捧杯：IH
> - 防AK：F


> 个人难度评价：
>
> - 基础：BJAC
> - 略有思维难度：L
> - 需要代码能力：E
> - 需要细心思考：
> - 很天才的想法：
> - 暂时做不了：



## B. 比分幻术

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    swap(s[0], s[2]);
    cout << s << '\n';

    return 0;
}
```



## J. 结课风云

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> x(n), y(n);
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] + y[i] < c) {
            pos.emplace_back(i);
        }
    }

    int d;
    cin >> d;
    int cnt = 0;
    for (auto p : pos) {
        x[p] = min(a, x[p] + d);
        if (x[p] + y[p] >= c) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
```




## A. 爱上字典


```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    set<string> S;
    int n;
    cin >> n;
    while (n--) {
        string t;
        cin >> t;
        S.insert(t);
    }

    int ans = 0;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            int j = i;
            string t;
            while (isalpha(s[j])) {
                t += tolower(s[j]);
                j++;
            }
            if (!S.count(t)) {
                S.insert(t);
                ans++;
            }
            i = j;
        }
    }

    cout << ans << '\n';

    return 0;
}
```


## C. 插排串联

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> f(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i] >> a[i];
        adj[f[i]].emplace_back(i);
    }

    vector<i64> sum(n + 1);

    auto dfs = [&](auto self, auto u) -> void {
        if (adj[u].empty()) {
            sum[u] = a[u];
            return;
        }
        for (auto v : adj[u]) {
            self(self, v);
            sum[u] += sum[v];
        }
    };

    dfs(dfs, 0);

    if (sum[0] > 2200) {
        return cout << "NO\n", 0;
    }

    vector<int> w, p;
    for (int i = 1; i <= n; i++) {
        if (!adj[i].empty()) {
            w.emplace_back(sum[i]);
            p.emplace_back(a[i]);
        }
    }
    sort(w.begin(), w.end(), greater<int>());
    sort(p.begin(), p.end(), greater<int>());

    int siz = w.size();
    for (int i = 0; i < siz; i++) {
        if (w[i] > p[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";

    return 0;
}
```


## E. 俄式简餐

与 [2024牛客暑期多校训练营5 — B. 珑](https://ac.nowcoder.com/acm/contest/81600) 这题非常类似 — 分类讨论。

在本题中，还需要输出具体方案，如何把代码写短比较考验代码能力。

[shift - Code](https://qoj.ac/submission/713539) 

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n * m & 1) {
        cout << "NO\n";
        return;
    }

    if (n % 4 == 0 or m % 4 == 0) {
        bool is = false;
        if(n % 4 != 0) {
            is = true;
            swap(n, m);
        }
        vector<vector<int>> g(n, vector<int>(m));
        int now = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i % 4 == 0) {
                    g[i][j] = now++;
                } else {
                    g[i][j] = g[i - 1][j];
                }
            }
        }
        cout << "YES\n";
        if (is) {
            swap(n, m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (is) {
                    cout << g[j][i] << " \n"[j == m - 1];
                } else {
                    cout << g[i][j] << " \n"[j == m - 1];
                }
            }
        }
    } else if (n % 2 == 0 and m % 2 == 0) {
        int now = 1;
        bool is = false;
        if (n <= 4 and m <= 4) {
            cout << "NO\n";
            return;
        } else if (n < m) {
            is = true;
            swap(n, m);
        }
        vector<vector<int>> g(n, vector<int>(m));
        for (int j = 0; j < m; j += 2) {
            g[0][j] = now;
            g[0][j + 1] = now;
            g[1][j] = now;
            g[2][j] = now;
            now += 1;

            g[n - 1][j] = now;
            g[n - 1][j + 1] = now;
            g[n - 2][j] = now;
            g[n - 3][j] = now;
            now += 1;

            for (int i = 3; i <= n - 4; i++) {
                if(i % 4 == 3) {
                    g[i][j] = now++;
                } else {
                    g[i][j] = g[i - 1][j];
                }
            }
            for (int i = 1; i <= n - 2; i++) {
                if (i % 4 == 1) {
                    g[i][j + 1] = now++;
                } else {
                    g[i][j + 1] = g[i - 1][j + 1];
                }
            }
        }
        if (is) {
            swap(n, m);
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (is) {
                    cout << g[j][i] << " \n"[j == m - 1];
                } else {
                    cout << g[i][j] << " \n"[j == m - 1];
                }
            }
        }
    } else {
        cout << "NO\n";
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



## L. 龙之研习


> 非常 CF 风格的一题，**前缀和 + 二分答案**的内核非常典。

思考到最后不难发现，只需要实现一个求 $1 \sim x$ ( $x \in 1e18$ ) 中闰年的个数即可。

对于题目中不同的 $p$，由于题目要求其是**唯一的**，因此每一个 $p$ 对应的闰年是不会相交的 ( 否则 $p$ 就不是唯一的 )，因此 $1 \sim x$ 的闰年个数为：

$$
\sum_{p = 0}^{\infty} \lfloor \frac x{4 \times 100^p}\rfloor - \lfloor \frac x{ 100^{p + 1}}\rfloor
$$

( 容斥原理 )


二分上界需要开 $2e18$，否则会 WA。

思考：此题如何估算二分上界？


```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 k;

i64 calc(i64 x) {
    i64 sum = 0;
    for (i64 p = 1; p <= x; p *= 100) {
        sum += x / (4 * p) - x / (100 * p);
    }
    return x - sum;
}

bool check(i64 mi) {
    return calc(mi) - calc(2024) >= k;
}

void solve() {
    cin >> k;
    i64 lo = 2025, hi = 2e18;
    while (lo < hi) {
        i64 mi = (lo + hi) >> 1;
        if (check(mi)) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << lo << '\n';
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

## D. 都市叠高

> 假的计算几何，实则 dp。



> 观察：
>
> 1. "面积最小的凸多边形" $\implies$ 所有点都作为凸多边形的顶点
> 2. "**移除了原版叠叠高的平衡性判定**" $\implies$ 只会利用凸多边形中**距离最远的两个顶点**


---

错误思路——

$f(i)$：考虑前 $i$ 个点的最大答案。

转移：枚举最后一个凸多边形利用的点的集合，同时维护任意两个点之间的距离最大值。

时间复杂度：$\mathcal O(n \times n^2)$

---

实际上不需要维护两个点之间的距离最大值，不是枚举点集求最大距离，反而**枚举最大值在哪两个点之间**。

转移：

$$
f(i) = \max(f(j - 1) + dis(p_i, p_j))
$$

时间复杂度：$\mathcal O(n \times n)$ 


```cpp
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<PII> p(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    auto dis = [&](auto a, auto b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    };

    vector<double> f(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i] = max(f[i], f[j - 1] + dis(p[i], p[j]));
        }
    }

    cout << f[n] << '\n';

    return 0;
}
```

> 代码细节：
>
> 当 $j$ 枚举到 $i$ 的时候，等价于不使用第 $i$ 个点 ( $dis(i, j) = 0$ )。






## G. 顾影自怜

最大值的出现次数至少 $k$ 次，不难观察到，其贡献和数组的长度没有关系

```cpp

```



## K. 可重集合



```cpp

```




## M. 盲盒谜题



```cpp

```

