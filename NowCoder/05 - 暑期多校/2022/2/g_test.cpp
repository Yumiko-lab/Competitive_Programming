#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // vector<int> p{1, 2, 3, 4, 5};
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> p(5);
    iota(p.begin(), p.end(), 0);

    auto lis = [&](auto a) {
        int n = a.size();
        vector<int> f(n + 1);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            f[i + 1] = 1;
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) {
                    f[i + 1] = max(f[i + 1], f[j + 1] + 1);
                }
            }
            mx = max(mx, f[i + 1]);
        }
        return mx;
    };

    auto lds = [&](auto a) {
        auto ra = a;
        reverse(ra.begin(), ra.end());
        return lis(ra);
    };

    do {
        vector<int> t;
        for (auto x : p) {
            t.emplace_back(a[x]);
        }
        // cout << lis(t) + lds(t) << '\n';
        for (auto x : t) {
            cout << x << ' ';
        }
        cout << " : ";
        cout << lis(t) << ' ' << lds(t) << '\n';
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}