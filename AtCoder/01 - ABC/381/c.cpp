#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '/') {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < n && s[l] == '1' && s[r] == '2') {
                l--, r++;
            }
            ans = max(ans, 1 + 2 * (r - i - 1));
        }
    }

    cout << ans << '\n';

    return 0;
}