#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, P;
    cin >> N >> M >> P;

    cout << (N - M + 1 + P - 1) / P << '\n';

    return 0;
}