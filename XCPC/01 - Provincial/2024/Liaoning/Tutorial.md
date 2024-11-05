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

与 [2024牛客暑期多校训练营5 — B. 珑](https://ac.nowcoder.com/acm/contest/81600) 这题非常类似，分类讨论。

在本题中，还需要输出具体方案，如何把代码写短比较考验代码能力。

```cpp

```


## L. 龙之研习


非常 CF 风格的一题，前缀和 + 二分的内核非常典。


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