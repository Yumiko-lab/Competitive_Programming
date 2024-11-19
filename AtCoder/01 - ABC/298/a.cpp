#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    bool has = false;
    for (auto c : s) {
        if (c == 'x') {
            return cout << "No\n", 0;
        }
        if (c == 'o') {
            has = true;
        }
    }
    cout << (has ? "Yes" : "No") << '\n';

    return 0;
}