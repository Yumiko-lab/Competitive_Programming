#include <bits/stdc++.h>
using namespace std;

struct Info {
    // name, problems, penalty, 
    string s;
    int p, t;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Info> a(n);
    set<string> S1, S2;
    for (auto &[s, p, t] : a) {
        cin >> s >> p >> t;
        S1.insert(s);
    }
    sort(a.begin(), a.end(), [&](auto x, auto y) {
        if (x.p != y.p) {
            return x.p > y.p;
        }
        return x.t < y.t;
    });

    int m;
    cin >> m;
    vector<Info> b(m);
    for (auto &[s, p, t] : b) {
        cin >> s >> p >> t;
        S2.insert(s);
    }
    sort(b.begin(), b.end(), [&](auto x, auto y) {
        if (x.p != y.p) {
            return x.p > y.p;
        }
        return x.t < y.t;
    });


    int rk1 = -1, rk2 = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].s == "lzr010506") {
            rk1 = i;
            break;
        }
    }

    for (int i = 0; i < m; i++) {
        if (b[i].s == "lzr010506") {
            rk2 = i;
            break;
        }
    }

    // 一场比赛可能会有多个同一个学校的队伍参加
    int ans1 = rk1 + 1, ans2 = rk2 + 1;

    for (int i = 0; i < rk1; i++) {
        if (S2.count(a[i].s)) {
            ans1--;
        }
    }

    for (int i = 0; i < rk2; i++) {
        if (S1.count(b[i].s)) {
            ans2--;
        }
    }

    cout << min(ans1, ans2) << '\n';

    return 0;
}