# 2024 CCPC Harbin

> 参考题解：
>
> - [俊杰Charles - CCPC2024哈尔滨 总结 - Video - Bilibili](https://www.bilibili.com/video/BV14UyHYdEeN/) 
> - [LingKerly - CGJKM - Blog - Zhihu](https://zhuanlan.zhihu.com/p/3503864231) 
> - [景影3 - C - Blog - Bilibili](https://www.bilibili.com/read/cv39637445/) 
> - [Dashcoding编程社 - K - Video - Bilibili](https://www.bilibili.com/video/BV1imS9Y5EEj/) 





题解顺序优先按照题目相关性，然后按照题目难度排序。

> - 签到：MCG
> - 铜牌：KJ
> - 银牌：AL
> - 金牌：BE
> - 捧杯：ID
> - 防AK：FH


> 个人难度评价：
>
> - 基础：MC
> - 略有思维难度：
> - 需要代码能力：G
> - 需要细心思考：
> - 很天才的想法：
> - 暂时做不了：


## M. 


```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> divide(int n) {
    vector<int> d;
    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            d.emplace_back(i);
            if (i != n / i) {
                d.emplace_back(n / i);
            }
        }
    }
    sort(d.begin(), d.end());
    return d;
}

void solve() {
    int n;
    cin >> n;
    auto d = divide(n);
    i64 ans = 0;
    for (int i = 1; i < d.size(); i++) {
        ans += (1LL * d[i] - d[i - 1]) * (n / d[i - 1]);
    }
    cout << ans + 1 << '\n';
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
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

string str = "NESW";

void solve() {
    int n;
    cin >> n;
    vector<pair<char, int>> a(n);
    for (auto &[d, x] : a) {
        cin >> d >> x;
    }
    cout << 2 * n - 1 << ' ' << a[0].x << '\n';
    for (int i = 0; i + 1 < n; i++) {
        cout << "Z " << a[i].y << '\n';
        int d = (str.find(a[i + 1].x) - str.find(a[i].x));
        cout << (d == -1 || d == 3 ? "L" : "R") << '\n';
    }
    cout << "Z " << a[n - 1].y << '\n';
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


## G. 


```cpp

```



## K. 

补题的时候始终没看懂题，一直在虚空犯难。



```cpp

```

## J. 


```cpp

```


## A. 造计算机

构造题

```cpp

```

## L. 

```cpp

```