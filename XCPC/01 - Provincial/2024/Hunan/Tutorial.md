# 2024 Hunan Provincial


[如何评价2024年湖南省大学生程序设计竞赛(HNCPC)?](https://www.zhihu.com/question/663248911) 



> 参考题解：
>
> [Resot - G - Blog - Zhihu](https://zhuanlan.zhihu.com/p/1256476588) 





## C. easy math



令 $\prod_{i = 1}^n a_i = 2^s$。



则有：
$$
2^s \le 2024^b \implies s \le b \cdot \log_22024
$$


可以大致估算，$s$ 不会超过 $500$，故答案 $b$ 不会超过 $50$，因此直接从 $0$ 开始枚举 $b$ 的取值，求第一个满足不等式的对应的 $b$ 即可。



```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for (auto &x : a) {
        cin >> x;
        s += __lg(x);
    }
    
    double down = log2(2024);
    double ans = 0;
    while (ans * down < s) {
        ans++;
    }
    cout << ans << '\n';

    return 0;
}
```









## I. 数据检索系统



简单模拟题。



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m, q;
    cin >> n >> k >> m >> q;

    vector<bool> in(n);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int p = 1;
        for (int j = 0; j < k; j++) {
            p = p * x % n;
            in[p] = 1;
        }
    }

    while (q--) {
        int x;
        cin >> x;
        bool ok = true;
        int p = 1;
        for (int i = 0; i < k; i++) {
            p = p * x % n;
            if (!in[p]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? 1 : 0) << ' ';
    }

    return 0;
}
```





## E. 拼接串



> 赛时理解错题意了，每个正整数我以为是 $0 \sim 9$，但其实就是 $a$ 的范围。





$f(state)$：表示出现数字的集合是 $s$ 的最大长度。

$g(state)$：表示出现数字的集合是 $s$ 的子集的最大长度。







```cpp
```









## K. 渡劫





```cpp
```





## J. Beautiful Sequence





```cpp
```





## H. 经文





```cpp
```









## D. Too much noise!





```cpp
```







## A. 贪吃蛇



```cpp
```







## G. Utakotoba



线性基待补。



