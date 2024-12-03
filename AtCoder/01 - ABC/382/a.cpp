#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    string S;
    cin >> N >> D >> S;

    int cnt = count(S.begin(), S.end(), '@');

    cout << N - cnt + min(cnt, D) << '\n';

    return 0;
}