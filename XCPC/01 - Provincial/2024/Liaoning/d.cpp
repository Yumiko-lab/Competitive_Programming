#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<PII> p(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    auto dis = [&](auto a, auto b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    };

    vector<double> f(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i] = max(f[i], f[j - 1] + dis(p[i], p[j]));
        }
    }

    cout << f[n] << '\n';

    return 0;
}