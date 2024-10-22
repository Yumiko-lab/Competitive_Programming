# AtCoder Beginner Contest 304

[Official - Blog](https://atcoder.jp/contests/abc304/editorial) 



## A. First Player

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Info {
    string s;
    int age;
};

int main() {
    int n;
    cin >> n;
    vector<Info> a(n);
    for (auto &[s, age] : a) {
        cin >> s >> age;
    }

    int mn = 1e9, mi = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].age < mn) {
            mn = a[i].age;
            mi = i;
        }
    }

    int j = mi;
    for (int i = 0; i < n; i++) {
        cout << a[(j + i) % n].s << '\n';
    }

    return 0;
}
```


## B. Subscribers

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int len = to_string(n).size();
    int p = pow(10, max(0, len - 3));

    cout << n / p * p << '\n';

    return 0;
}
```



## C. Virus

```cpp
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

int main() {
    int N, D;
    cin >> N >> D;
    vector<PII> acc(N);
    for (auto &[a, b] : acc) {
        cin >> a >> b;
    }
    
    auto check = [&](auto a, auto b) {
        int dx = a.x - b.x;
        int dy = a.y - b.y;
        return dx * dx + dy * dy <= D * D;
    };

    vector<int> is(N);
    is[0] = 1;

    queue<int> q;
    q.emplace(0);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if (!is[i] && check(acc[u], acc[i])) {
                is[i] = 1;
                q.emplace(i);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << (is[i] ? "Yes" : "No") << '\n';
    }

    return 0;
}
```


## D. A Piece of Cake


```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    vector<PII> acc(N);
    for (auto &[p, q] : acc) {
        cin >> p >> q;
    }

    int A;
    cin >> A;
    vector<int> a(A + 1);
    for (int i = 0; i < A; i++) {
        cin >> a[i];
    }
    a[A] = W;

    int B;
    cin >> B;
    vector<int> b(B + 1);
    for (int i = 0; i < B; i++) {
        cin >> b[i];
    }
    b[B] = H;

    map<PII, int> cnt;
    for (auto [p, q] : acc) {
        int x = lower_bound(a.begin(), a.end(), p) - a.begin();
        int y = lower_bound(b.begin(), b.end(), q) - b.begin();
        cnt[{x, y}]++;
    }
    int mn = N, mx = 0;
    for (auto [P, y] : cnt) {
        mn = min(mn, y);
        mx = max(mx, y);
    }

    if (cnt.size() < (A + 1LL) * (B + 1)) {
        mn = 0;
    }
    cout << mn << ' ' << mx << '\n';

    return 0;
}
```


## E. Good Graph


```cpp
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

struct DSU {
    vector<int> p;
    
    DSU() {}
    DSU(int n) : p(n + 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y); 
    }
    
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        p[x] = y; // x -> y
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }

    set<PII> S;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x = dsu.find(x), y = dsu.find(y);
        S.insert({x, y});
        S.insert({y, x});
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int p, q;
        cin >> p >> q;
        p = dsu.find(p), q = dsu.find(q);
        cout << (!S.count({p, q}) ? "Yes" : "No") << '\n';
    }
    cout << '\n';

    return 0;
}
```


## F. Shift Table



```cpp

```



## G. Max of Medians



```cpp

```



## Ex. Constrained Topological Sort



```cpp

```
