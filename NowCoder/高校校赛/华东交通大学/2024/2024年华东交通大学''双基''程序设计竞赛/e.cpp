#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];

    auto check = [&](auto s) {
        int sum = 0;
        for (auto c : s) {
            sum += c - '0';
        }
        return sum % 3 == 0;
    };

    for (int i = 0; i < 3; i++) {
        if (check(s[i])) {
            cout << "LaoSu Like Fake\n";
            return;
        }
    }
    cout << "LaoSu Don't Like Fake\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}