# 2024-2025 ICPC, NERC, Southern and Volga Russian Regional

[2024-2025 ICPC, NERC, Southern and Volga Russian Regional Contest](https://codeforces.com/contest/2038) 



> 参考题解：
>
> - [芋饼饭 - NJCALKGB - Video - Bilibili](https://www.bilibili.com/video/BV19oU4YbEss/) 
> - [ExtractStars - NJLCAGKB - Blog - Cnblogs](https://www.cnblogs.com/extractstars/p/18559773) 
> - [YipChip - B - Blog - Cnblogs](https://www.cnblogs.com/YipChipqwq/p/18559613#_label0) 


## J. 


```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    i64 f = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        char e;
        int x;
        cin >> e >> x;
        if (e == 'P') {
            cnt += x;
        } else {
            i64 mn = min((i64)x, cnt);
            x -= mn, cnt -= mn;
            cout << (x > 0 ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
```

## N. 


```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;
    char &mi = s[1];
    if (mi == '=') {
        if (s[0] < s[2]) {
            mi = '<';
        } else if (s[0] > s[2]) {
            mi = '>';
        }
    } else if (mi == '<') {
        if (s[0] == s[2]) {
            mi = '=';
        } else if (s[0] > s[2]) {
            mi = '>';
        }
    } else {
        if (s[0] == s[2]) {
            mi = '=';
        } else if (s[0] < s[2]) {
            mi = '<';
        }
    }
    cout << s << '\n';
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

