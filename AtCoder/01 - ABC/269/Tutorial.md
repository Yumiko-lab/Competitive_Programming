# AtCoder Beginner Contest 269

> Tutorial：
>
> [Official - Blog](https://atcoder.jp/contests/abc269/editorial) 
> 
> [_Backl1ght - F、G、Ex - Blog - Cnblogs](https://www.cnblogs.com/zengzk/p/16704065.html) 
> 
> [稠密图 - A ~ G - Blog - Zhihu](https://zhuanlan.zhihu.com/p/580881219) 
> 
> [星宫六喰 - A ~ F - Blog - Zhihu](https://zhuanlan.zhihu.com/p/565503964) 
> 
> [kilo - A ~ F - Blog - Zhihu](https://zhuanlan.zhihu.com/p/565578984) 


## A. Anyway Takahashi

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << (a + b) * (c - d) << '\n';
    cout << "Takahashi\n";

    return 0;
}
```


## B. Rectangle Detection


```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10, m = 10;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int A = -1, B = -1, C = -1, D = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                A = i + 1, C = j + 1;
                int x = i;
                while (x < n && s[x][j] == '#') {
                    x++;
                }
                B = x - 1 + 1;
                int y = j;
                while (j < m && s[i][y] == '#') {
                    y++;
                }
                D = y - 1 + 1;
                break;
            }
        }
        if (A != -1) {
            break;
        }
    }

    cout << A << ' ' << B << '\n';
    cout << C << ' ' << D << '\n';
    
    return 0;
}
```

## C. Submask


```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;
    vector<int> bits;
    for (int i = 0; i < 60; i++) {
        if (n >> i & 1) {
            bits.emplace_back(i);
        }
    }

    int m = bits.size();
    for (int i = 0; i < 1 << m; i++) {
        i64 now = 0;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                now |= (1LL << bits[j]);
            }
        }
        cout << now << '\n';
    }
    
    return 0;
}
```

## D. Do use hexagon grid


```cpp
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

constexpr int dir[][2] = {
    {-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}
};

struct DSU {
    vector<int> p;
    int cnt;
    
    DSU() {}
    DSU(int n) : p(n + 1), cnt(n) {
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
        cnt--;
        p[x] = y; // x -> y
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    DSU dsu(n);
    
    vector<PII> acc(n);
    map<PII, int> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        acc[i] = {x, y};
        mp[{x, y}] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        for (auto [dx, dy] : dir) {
            int a = acc[i].x + dx, b = acc[i].y + dy;
            if (mp.count({a, b})) {
                dsu.merge(i + 1, mp[{a, b}]);
            }
        }
    }

    cout << dsu.cnt << '\n';
    
    return 0;
}
```


## E. Last Rook

> Description：
>
> $N \times N$ 的棋盘中已经放入 $N - 1$ 个 石头，且满足每一行和每一列都最多只有一个石头。
> 
> 最多询问 $20$ 次，每一次询问；`? A B C D`，表示一个矩形区域内已经放入了多少石头。
> 
> 回答最后一块石头可以放入的位置。





```cpp

```

## F. Numbered Checker


```cpp

```


## G. Reversible Cards 2


01 背包 + 根号算法。


```cpp

```



## Ex. Antichain


```cpp

```






