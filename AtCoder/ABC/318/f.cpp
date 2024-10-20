#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<i64> X(N), L(N);
    for (auto &v : X) {
        cin >> v;
    }
    for (auto &v : L) {
        cin >> v;
    }
    sort(L.begin(), L.end());

    

    return 0;
}