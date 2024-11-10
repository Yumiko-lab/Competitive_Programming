# Refact.ai Match 1 (Codeforces Round 985)

> 参考题解：
>
> - [Official - Blog](https://codeforces.com/blog/entry/133516)
> - [楜桃林東麓 - A ~ E - Blog - Zhihu](https://zhuanlan.zhihu.com/p/5983087340) 




## A. 

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r, k;
    cin >> l >> r >> k;

    int lo = l, hi = r;
    while (lo < hi) {
        int mi = (lo + hi + 1) >> 1;
        if (r / mi >= k) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    if (r / lo < k) {
        return cout << "0\n", void();
    }
    cout << lo - (l - 1) << '\n';
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
    string s, r;
    cin >> n >> s >> r;
    array<int, 2> cnt {};
    for (auto c : s) {
        cnt[c - '0']++;
    }
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        if (!cnt[0] || !cnt[1]) {
            ok = false;
            break;
        }
        cnt[0] -= 1, cnt[1] -= 1;
        cnt[r[i] - '0'] += 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
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


## C. 

```cpp

```



## D. 

```cpp

```



## E. 

```cpp

```


## F. 

```cpp

```



后续题目待补。