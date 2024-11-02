#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    int a = s[0] - '0';
    int p = s.find('.');

    string d = s.substr(2, p - 2);

    int b = 0;
    for (int i = p + 1; i < n; i++) {
        b = b * 10 + (s[i] - '0'); 
    }

    if (b >= d.size()) {
        cout << a << d;
        b -= d.size();
        while (b--) {
            cout << 0;
        }
        return 0;
    }

    cout << a;
    cout << d.substr(0, b);
    cout << '.';
    cout << d.substr(b);

    return 0;
}