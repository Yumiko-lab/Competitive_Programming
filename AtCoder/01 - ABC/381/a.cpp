#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    if (n % 2 == 0) {
        return cout << "No\n", 0;
    }

    int cnt = (n - 1) / 2;
    string a = s.substr(0, cnt), b = s.substr(cnt + 1);

    cout << (a == string(cnt, '1') && s[cnt] == '/' && b == string(cnt, '2') ? "Yes" : "No") << '\n';

    return 0;
}