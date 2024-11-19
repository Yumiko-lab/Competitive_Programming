#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    auto dis = [&](int x1, int y1, int x2, int y2) {
        double dx = x1 - x2;
        double dy = y1 - y2;
        return sqrt(dx * dx + dy * dy);
    };

    int n;
    cin >> n;
    double res = 0;
    int nx = 0, ny = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        res += dis(nx, ny, x, y);
        nx = x, ny = y;
    }
    res += dis(nx, ny, 0, 0);
    cout << res << '\n';

    return 0;
}