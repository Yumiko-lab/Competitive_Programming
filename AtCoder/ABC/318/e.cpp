#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A) {
        cin >> x;
    }

    map<int, int> L, R;
    
    for (auto x : A) {
        R[x]++;
    }

    i64 ans = 0, now = 0;
    for (int i = 0; i < N; i++) {
        int x = A[i];
        R[x]--;
        now += -L[x];
        ans += now - (1LL * L[x] * R[x]);
        L[x]++;
        now += R[x];
    }

    cout << ans << '\n';

    return 0;
}