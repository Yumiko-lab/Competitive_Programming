# Acwing 第 13 场周赛


[Problems](https://www.acwing.com/activity/content/competition/problem_list/65/) 

[yxc Tutorial](https://www.bilibili.com/video/BV1e3411B7ZB/) 


## A. 排列


```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << (i % n + 1) << ' ';
    }
    cout << '\n';
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


## B. 机器人走迷宫


```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int dir[][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S') {
                sx = i, sy = j;                
            }
        }
    }

    string op;
    cin >> op;

    vector<int> p{0, 1, 2, 3};

    auto vaild = [&](auto x, auto y) {
        return (x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#');
    };

    auto check = [&](auto p) {
        int x = sx, y = sy;
        for (auto c : op) {
            int w = c - '0';
            x += dir[p[w]][0], y += dir[p[w]][1];
            if (!vaild(x, y)) {
                return false;
            }
            if (s[x][y] == 'E') {
                return true;
            }
        }
        return false;
    };

    int ans = 0;
    do {
        if (check(p)) {
            ans++;
        }
    } while (next_permutation(p.begin(), p.end()));
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

## C. 最大路径权值



### STL

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> adj(n);
    vector<int> din(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        din[v]++;
    }

    vector<int> seq;
    auto topo = [&]() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (din[i] == 0) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            seq.emplace_back(u);
            for (auto v : adj[u]) {
                if (--din[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    };

    topo();

    if (seq.size() < n) {
        return cout << -1, 0;
    }

    vector f(26, vector<int>(n));
    for (int i = 0; i < n; i++) { // initialization the value of 0 indegree Node
        f[s[i] - 'a'][i] = 1;
    }

    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        int w = c - 'a';
        for (auto u : seq) {
            for (auto v : adj[u]) {
                f[w][v] = max(f[w][v], f[w][u] + (s[v] == c));
            }
            ans = max(ans, f[w][u]);
        }
    }
    cout << ans << '\n';

    return 0;
}
```

### 链式前向星

```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300010, M = 300010;

int n, m;
int h[N], e[M], ne[M], idx;
char s[N];
int q[N], din[N];
int f[26][N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topo() {
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        if (din[i] == 0) {
            q[++tt] = i;
        }
    }
    while (hh <= tt) {
        auto u = q[hh++];
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (--din[v] == 0) {
                q[++tt] = v;
            }
        }
    }
    return tt == n - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);

    cin >> n >> m;
    cin >> s;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        add(u, v);
        din[v]++;
    }

    if (!topo()) {
        return cout << -1, 0;
    }

    for (int i = 0; i < n; i++) {
        f[s[i] - 'a'][i] = 1;
    }

    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        int w = c - 'a';
        for (int i = 0; i < n; i++) {
            for (int j = h[q[i]]; ~j; j = ne[j]) {
                int k = e[j];
                f[w][k] = max(f[w][k], f[w][q[i]] + (s[k] == c));
            }
            ans = max(ans, f[w][q[i]]);
        }
    }
    cout << ans << '\n';

    return 0;
}
```