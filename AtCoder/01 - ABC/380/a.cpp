#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    array<int, 10> cnt {};
    for (auto c : s) {
        cnt[c - '0'] += 1;
    }

    cout << (cnt[1] == 1 && cnt[2] == 2 && cnt[3] == 3 ? "Yes" : "No") << '\n';

    return 0;
}