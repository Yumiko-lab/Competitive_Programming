#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        if (i + 2 < n && s[i] == '#' && s[i + 1] == '.' && s[i + 2] == '#') {
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}