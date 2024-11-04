#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    set<string> S;
    int n;
    cin >> n;
    while (n--) {
        string t;
        cin >> t;
        S.insert(t);
    }

    int ans = 0;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            int j = i;
            string t;
            while (isalpha(s[j])) {
                t += tolower(s[j]);
                j++;
            }
            if (!S.count(t)) {
                S.insert(t);
                ans++;
            }
            i = j;
        }
    }

    cout << ans << '\n';

    return 0;
}