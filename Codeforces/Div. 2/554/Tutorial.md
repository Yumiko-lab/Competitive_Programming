# Codeforces Round 554 (Div. 2)

[Codeforces Round 554 (Div. 2)](https://codeforces.com/contest/1152) 



## A. 

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    array<int, 2> a{}, b{};
    while (n--) {
        int x;
        cin >> x;
        a[x % 2]++;
    }
    while (m--) {
        int x;
        cin >> x;
        b[x % 2]++;
    }

    cout << min(a[0], b[1]) + min(a[1], b[0]) << '\n';

    return 0;
}
```


## B. 

$1 \le x \le 1 \times 10^6 < 2^{20}$，即 $x$ 最多 $20$ 位二进制位，而操作次数上限恰好是 $40$ 次，因此不难想到按二进制位处理，**每一位二进制位最多操作两次**。

按照以上思路思考，不难想到答案。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    vector<int> ans;

    while (true) {
        int lst = __builtin_ctz(x);
        ans.emplace_back(lst);
        x ^= (1 << lst) - 1;
        if (x + 1 == (x + 1 & -x - 1)) {
            break;
        }
        x += 1;
    }

    cout << 2 * ans.size() - 1 << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
```


## C. 

给定两个数 $a, b$，研究 $a + k, b + k$ 的 $\gcd$ 和 $\rm lcm$  非常经典。

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 lcm(int x, int y) {
    return 1LL * x / __gcd(x, y) * y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    if (a < b) {
        swap(a, b);
    }

    array<i64, 2> ans{0, lcm(a, b)}; // {k = 0, lcm(a, b)}
    auto calc = [&](auto f) { // factor
        i64 k = f - (a % f), l = lcm(a + k, b + k);
        if (l < ans[1]) {
            ans = {k, l};
        }
    };

    int d = a - b;
    for (int i = 1; i <= d / i; i++) {
        if (d % i == 0) {
            calc(i);
            if (i != d / i) {
                calc(d / i);
            }
        }
    }

    cout << ans[0] << '\n';
    
    return 0;
}
```


## D. Neko and Aki's Prank

> Description：
>
> 把长度为 $2n$ 所有合法括号序列塞进一个 Tire 里，求这个 Tire 树的**最大边独立集**。






```cpp

```


## E. 


## F1. 




## F2. 






