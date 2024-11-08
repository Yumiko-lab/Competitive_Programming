# CodeTON Round 8

[CLIST - Problems Rating Distribution](https://clist.by/problems/?resource=1&contest=50323111) 

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


## C2. 


## D. 


## E. 

