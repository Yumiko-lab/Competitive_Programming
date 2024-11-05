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

## B. 

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



## J. 

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




## A. 


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


## C. 

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


## E. 

```cpp

```


## L. 



```cpp

```