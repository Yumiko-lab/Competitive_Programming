#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    vector<PII> acc(N);
    for (auto &[p, q] : acc) {
        cin >> p >> q;
    }

    int A;
    cin >> A;
    vector<int> a(A + 1);
    for (int i = 0; i < A; i++) {
        cin >> a[i];
    }
    a[A] = W;

    int B;
    cin >> B;
    vector<int> b(B + 1);
    for (int i = 0; i < B; i++) {
        cin >> b[i];
    }
    b[B] = H;

    map<PII, int> cnt;
    for (auto [p, q] : acc) {
        int x = lower_bound(a.begin(), a.end(), p) - a.begin();
        int y = lower_bound(b.begin(), b.end(), q) - b.begin();
        cnt[{x, y}]++;
    }
    int mn = N, mx = 0;
    for (auto [P, y] : cnt) {
        mn = min(mn, y);
        mx = max(mx, y);
    }

    if (cnt.size() < (A + 1LL) * (B + 1)) {
        mn = 0;
    }
    cout << mn << ' ' << mx << '\n';

    return 0;
}