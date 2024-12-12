# 华华中农业大学第十四届程序设计竞赛（新生赛）同步赛



## A. 


```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    char w;
    if (a == b) {
        w = '=';
    } else if (a > b) {
        w = '>';
    } else {
        w = '<';
    }
    cout << w << '\n';
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    array<int, 2> p {-1, -1};
    for (int i = 0; i < n; i++) {
        if (p[0] == -1 && s[i] == 'e') {
            p[0] = i;
        }
        if (s[i] == 'z') {
            p[1] = i;
        }
    }

    if (p[0] == -1 || p[1] == -1 || p[0] >= p[1]) {
        cout << "hard\n";
    } else {
        cout << "easy\n";
    }

    return 0;
}
```

## M. 

初始想法：贪心 + DP



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto b = a;

    for (auto &x : a) {
        x = (x == 1 ? -1 : 1);
    }

    array<int, 2> mx {0, -1};
    for (int i = 0, s = 0; i < n; i++) {
        s = max(s, 0) + a[i];
        if (s > mx[0]) {
            mx = {s, i};
        }
    }

    int r = mx[1], l = r;
    int s = 0;
    while (s < mx[0]) {
        s += a[l--];
    }
    l += 1;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < l || i > r) {
            ans += b[i];
        }
    }

    cout << (2 * (ans + mx[0]) > n ? "Yes" : "No") << '\n';

    return 0;
}

/*

f[i]: 表示以 a[i] 为结尾的最大连续子段和

f[i] = max(f[i - 1] + a[i], a[i]) =>
f[i] = max(f[i - 1], 0) + a[i] =>
s = max(s, 0) + a[i]

*/
```

```cpp

```



## F. 


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
    array<int, 10> cnt {};
    int mn = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] > 0) {
            mn += 1;
            cnt.fill(0);
            cnt[a[i]] = 1;
        }
        cnt[a[i]] += 1;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] > 0) {
            mn += 1;
            break;
        }
    }
    cout << mn << ' ' << n << '\n';
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

## K. 


```cpp

```

