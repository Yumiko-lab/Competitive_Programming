#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    if (n % 2) {
        return cout << "No\n", 0;
    }

    array<int, 26> cnt {};
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1] || ++cnt[s[i] - 'a'] == 2) {
            return cout << "No\n", 0;
        }
    }

    cout << "Yes\n";

    return 0;
}