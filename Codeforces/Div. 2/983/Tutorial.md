# Codeforces Round 983 (Div. 2)


> 参考题解：
>
> - [RegenFallen - A ~ D - Video - Bilibili](https://www.bilibili.com/video/BV1uDSfYmExZ/) 
> - [Aicu - A ~ E - Blog - Zhihu](https://zhuanlan.zhihu.com/p/4607546675) 
> - [Lezy - A ~ E - Blog - Zhihu](https://zhuanlan.zhihu.com/p/4568543065) 
> - [FakeDuck - A ~ D - Blog - Zhihu](https://zhuanlan.zhihu.com/p/4563867688) 
> - [小猪嘟嘟 - A ~ E - Blog - Zhihu](https://zhuanlan.zhihu.com/p/4640717634) 



## A. 

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    array<int, 2> cnt{};
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    cout << cnt[1] % 2 << ' ' << (cnt[1] < n ? cnt[1] : 2 * n - cnt[1]) << '\n';
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
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return;
    }

    if (k == 1 || k == n) {
        cout << "-1\n";
        return;
    }

    int mi = (n + 1) / 2;
    if (k == mi) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    } else if (k < mi) {
        cout << 3 << '\n';
        cout << 1 << ' ' << 2 << ' ' << 2 * k - 1 << '\n';
    } else {
        cout << 3 << '\n';
        cout << 1 << ' ' << 2 * k - n + 1 << ' ' << n << '\n';
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


## C. 

只要能想到双指针，这题就比较好写了。

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = n;
    for (int i = 0, j = 0; i < n; i++) {
        while (j + 1 < i && a[j] + a[j + 1] <= a[i]) {
            j++;
        }
        ans = min(ans, n - (i - j + 1));
    }

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


## D. 


```cpp

```


## E. 

```cpp

```


## F. 

```cpp

```