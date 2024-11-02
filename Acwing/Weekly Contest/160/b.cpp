#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s; // a.deb
    int n = s.size();
    int a = s[0] - '0';

    int e = s.find('e');
    string d = s.substr(2, e - 2), b = s.substr(e + 1);
    int num_b = stoi(b);

    if (num_b >= d.size()) {
        if (a > 0) {
            cout << a;
            cout << d;
        } else {
            int noz = -1; // non-zero
            for (int i = 0; i < d.size(); i++) {
                if (d[i] > '0') {
                    cout << d.substr(i);
                    break;
                }
            }
        }
        num_b -= d.size();
        while (num_b--) {
            cout << 0;
        }
    } else {
        if (a > 0) {
            cout << a;
            cout << d.substr(0, num_b);
            cout << '.';
            cout << d.substr(num_b);
        } else {
            int noz = -1;
            string t;
            for (int i = 0; i < d.size(); i++) {
                if (d[i] > '0') {
                    noz = i;
                    t = d.substr(i);
                    break;
                }
            }
            // 0 .. noz - 1: zeros'
            if (num_b <= noz) {
                cout << "0.";
                cout << t;
            } else {
                num_b -= noz;
                cout << d.substr(0, num_b);
                cout << '.';
                cout << d.substr(num_b);
            }
        }
    }

    return 0;
}