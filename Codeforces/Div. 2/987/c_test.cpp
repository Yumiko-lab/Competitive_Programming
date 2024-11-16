#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> S;
    i64 t = 1;
    while (t * t <= 1E6) {
        S.insert(t * t);
        t++;
    }

    cout << S.size() << '\n';

    vector<int> sqr(S.begin(), S.end());

    int n = sqr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (S.count(sqr[i] + sqr[j])) {
                cout << sqr[i] << ' ' << sqr[j] << ' ' << sqr[i] + sqr[j] << '\n';
            }
        }
    }
    cout << '\n';


    // bool has = false;
    // for (i64 x = 1;; x++) {
    //     if (2 * x * x > 1E6) {
    //         break;
    //     }
    //     if (S.count(2 * x * x)) {
    //         has = true;
    //         cout << 2 * x * x << ' ' << sqrt(2 * x * x) << '\n';
    //         break;
    //     }
    // }
    // if (!has) {
    //     cout << "-1\n";
    // }

    return 0;
}