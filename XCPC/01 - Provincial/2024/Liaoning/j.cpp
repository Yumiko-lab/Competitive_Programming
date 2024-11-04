#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> x(n), y(n);
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] + y[i] < c) {
            pos.emplace_back(i);
        }
    }

    int d;
    cin >> d;
    int cnt = 0;
    for (auto p : pos) {
        x[p] = min(a, x[p] + d);
        if (x[p] + y[p] >= c) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}