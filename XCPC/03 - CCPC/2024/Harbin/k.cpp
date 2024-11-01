#include <bits/stdc++.h>
using namespace std;

struct Info {
    int w, l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Info> a(n);
    for (auto &[w, l, r] : a) {
        cin >> w >> l >> r;
    }

    sort(a.begin(), a.end(), [&](auto x, auto y) {
        return x.w > y.w;
    });

    cout << '\n';
    for (auto [w, l, r] : a) {
        cout << w << ' ' << l << ' ' << r << '\n';
    }
    cout << '\n';

    return 0;
}