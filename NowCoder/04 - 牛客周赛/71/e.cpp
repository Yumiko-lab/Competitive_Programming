#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

double calc(int a, int b, int c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    for (auto &[l, c] : a) {
        cin >> l >> c;
    }
    sort(a.begin(), a.end(), [&](PII a, PII b) {
        if (a.x != b.x) {
            return a.x > b.x;
        }
        return a.y > b.y;
    });
    double ans = -1;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && a[i].y >= 2) {
            ans = max(ans, calc(a[i].x, a[i].x, a[i + 1].x));
        }
    }
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && a[i + 1].y >= 2 && a[i + 1].x * 2 > a[i].x) {
            ans = max(ans, calc(a[i].x, a[i + 1].x, a[i + 1].x));
        }
    }

    cout << (ans < 0 ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}