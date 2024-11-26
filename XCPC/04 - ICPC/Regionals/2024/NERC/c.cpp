#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<PII> cnt(mp.begin(), mp.end());
    vector<int> ans;
    int m = cnt.size();
    int l = -1;
    for (int i = 0; i < m; i++) {
        if (cnt[i].y >= 2) {
            ans.emplace_back(cnt[i].x);
            for (int j = i + 1; j < m; j++) {
                if (cnt[j].y >= 2) {
                    ans.emplace_back(cnt[j].x);
                    l = j;
                    break;
                }
            }
            break;
        }
    }
    for (int i = m - 1; i > l; i--) {
        if (cnt[i].y >= 2) {
            ans.emplace_back(cnt[i].x);
            for (int j = i - 1; j > l; j--) {
                if (cnt[j].y >= 2) {
                    ans.emplace_back(cnt[j].x);
                    break;
                }
            }
            break;
        }
    }


    if (ans.size() < 4) {
        for (int i = 0; i < m; i++) {
            if (cnt[i].y >= 4) {
                ans.emplace_back(cnt[i].x);
            }
        }
    }
    if (ans.size() < 4) {
        for (int i = 0; i < m; i++) {
            if (cnt[i].y >= 6) {
                ans.emplace_back(cnt[i].x);
            }
        }
    }
    if (ans.size() < 4) {
        for (int i = 0; i < m; i++) {
            if (cnt[i].y >= 8) {
                ans.emplace_back(cnt[i].x);
            }
        }
    }
    if (ans.size() < 4) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[0] << ' ' << ans[2] << ' ';
    cout << ans[3] << ' ' << ans[1] << ' ' << ans[3] << ' ' << ans[2] << '\n';
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

/*

1
18
-26 -10 -26 -64 52 52 39 -64 52 -26 52 34 -64 39 -26 -64 39 39

*/