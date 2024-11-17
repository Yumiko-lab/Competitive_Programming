# 牛客小白月赛60

## A. 


```cpp

```


## B. 


```cpp

```


## C. 


```cpp

```


## D. 

```cpp

```



## E. 


判断两个数是否可以合并：

1. 标记所有质数的幂次
2. 求所有数包含的不同质因子的个数
3. 分解质因数暴力求公共质因子次数


求答案：

1. 树形 DP
2. 并查集合并




- 树形 DP：


```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 5000010;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> p(N), mark(N);
    mark[1] = 1;

    for (int i = 2; i < N; i++) {
        if (!p[i]) {
            for (int j = i + i; j < N; j += i) {
                p[j] = 1;
            }
            for (i64 j = i; j < N; j *= i) {
                mark[j] = 1;
            }
        }
    }

    int ans = 0;
    vector<int> dp(n);
    auto dfs = [&](auto self, int u, int from) -> void {
        dp[u] = 1;
        for (auto v : adj[u]) {
            if (v == from) {
                continue;
            }
            self(self, v, u);
            if (!mark[__gcd(a[u], a[v])]) {
                dp[u] += dp[v];
            }
        }
        ans = max(ans, dp[u]);
    };

    dfs(dfs, 0, -1);

    cout << ans << '\n';

    return 0;
}
```


- 并查集暴力合并：

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> minp, primes;
vector<set<int>> f;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

struct DSU {
    vector<int> p, siz;
    
    DSU() {}
    DSU(int n) : p(n), siz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] > siz[y]) {
            swap(x, y);
        }
        siz[y] += siz[x];
        p[x] = y; // x -> y
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(5E6);

    int n;
    cin >> n;
    f = vector<set<int>>(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x > 1) {
            int p = minp[x];
            x /= p;
            f[i].insert(p);
        }
    }

    DSU dsu(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int cnt = 0;
        if (f[u].size() > f[v].size()) {
            swap(u, v);
        }
        for (auto x : f[u]) {
            if (f[v].count(x)) {
                if (++cnt == 2) {
                    break;
                }
            }
        }
        if (cnt == 2) {
            dsu.merge(u, v);
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (dsu.p[i] == i) {
            mx = max(mx, dsu.size(i));
        }
    }

    cout << mx << '\n';

    return 0;
}
```

## F. 



```cpp

```