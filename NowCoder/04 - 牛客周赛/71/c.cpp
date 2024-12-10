#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    map<char, int> cnt;
    for (auto c : s) {
        cnt[c] += 1;
    }

    cout << cnt.size() << '\n';

    return 0;
}