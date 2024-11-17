#include <bits/stdc++.h>
using namespace std;

bool prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 3;
    vector<int> p(n), perm(n);
    iota(p.begin(), p.end(), 1);
    iota(perm.begin(), perm.end(), 0);

    bool has = false;

    do {
        vector<int> t;
        for (auto x : perm) {
            t.push_back(p[x]);
        }
        bool ok = true;
        for (int i = 0; i + 1 < n; i++) {
            if (prime(t[i] + t[i + 1])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (auto x : t) {
                cout << x << ' ';
            }
            cout << '\n';
            has = true;
            break;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    if (!has) {
        cout << "-1\n";
    }

    return 0;
}