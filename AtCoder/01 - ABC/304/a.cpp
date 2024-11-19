#include <bits/stdc++.h>
using namespace std;

struct Info {
    string s;
    int age;
};

int main() {
    int n;
    cin >> n;
    vector<Info> a(n);
    for (auto &[s, age] : a) {
        cin >> s >> age;
    }

    int mn = 1e9, mi = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].age < mn) {
            mn = a[i].age;
            mi = i;
        }
    }

    int j = mi;
    for (int i = 0; i < n; i++) {
        cout << a[(j + i) % n].s << '\n';
    }

    return 0;
}