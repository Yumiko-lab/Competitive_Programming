#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    string S;
    cin >> N >> D >> S;

    int cnt = count(S.begin(), S.end(), '@');

    cnt -= min(cnt, D);

    if (cnt == 0) {
        cout << string(N, '.') << '\n';
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (S[i] == '@') {
            if (cnt > 0) {
                cnt -= 1;
                cout << '@'; 
            } else {
                cout << string(N - i, '.') << '\n';
                return 0;
            }
        } else {
            cout << S[i];
        }
    }
    cout << '\n';

    return 0;
}