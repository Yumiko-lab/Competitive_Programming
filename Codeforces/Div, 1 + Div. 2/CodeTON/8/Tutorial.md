# CodeTON Round 8


[CodeTON Round 8 (Div. 1 + Div. 2, Rated, Prizes!)](https://codeforces.com/contest/1942) 

[CLIST - Problems Rating Distribution](https://clist.by/problems/?resource=1&contest=50323111) 

> 参考题解：
>
> - [幻想家协会会长 - A ~ E - Video - Bilibili](https://www.bilibili.com/video/BV1xj421d7dB/) 
> - [RegenFallen - A ~ E - Video - Bilibili](https://www.bilibili.com/video/BV1Wz421o7DP/) 
> - [cup-pyy - A ~ G - Blog - Zhihu](https://zhuanlan.zhihu.com/p/689964048) 
> - [Aicu - A ~ F - Blog - Zhihu](https://zhuanlan.zhihu.com/p/690001082) 
> - [AC-Panda - A ~ E - Blog - Zhihu](https://zhuanlan.zhihu.com/p/690797769) 





## A. 


```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k != 1 && k != n) {
        cout << "-1\n";
        return;
    }
    if (k == 1) {
        cout << 1 << ' ';
        for (int i = 0; i < n - 1; i++) {
            cout << 2 << ' ';
        }
        cout << '\n';
        return;
    }
    // k == n
    for (int i = 0; i < n; i++) {
        cout << 1 << ' ';
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


## B. 


```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (auto &x:  a) {
        cin >> x;
    }
    int mex = n, cur = n - 1;
    while (cur >= 0) {
        p[cur] = mex - a[cur];
        if (p[cur] < mex) {
            mex = p[cur];
        }
        cur--;
    }
    for (auto x : p) {
        cout << x << ' ';
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

## C1. 

```cpp

```

## C2. 

```cpp

```

## D. 

```cpp

```


## E. 


```cpp

```


