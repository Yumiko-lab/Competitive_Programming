#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int n = 3; n <= 10; n++) {
        vector<PII> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = {i + 1, i + 1};
        }

        set<int> S;
        do {
            int cnt = 0;
            for (int i = 0; i + 3 - 1 < n; i++) {
                vector<int> v {p[i].y, p[i + 1].y, p[i + 2].y};
                sort(v.begin(), v.end());
                if (v[0] + v[1] > v[2]) {
                    cnt++;
                }
            }
            S.insert(cnt);
            if (cnt == 0) {
                cout << n << " : ";
                for (int i = 0; i < n; i++) {
                    cout << p[i].x << ' ';
                }
                cout << '\n';
            }
        } while (next_permutation(p.begin(), p.end()));

    }

    return 0;
}