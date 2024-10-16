#include <bits/stdc++.h>
using namespace std;

struct Info {
    string name;
    int s, p;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Info> a(n);
    for (auto &[name, s, p] : a) {
        cin >> name >> s >> p;
    }
    sort(a.begin(), a.end(), [](const Info &x, const Info &y) {
        if (x.s != y.s) {
            return x.s > y.s;
        }
        return x.p < y.p;
    });

    int m;
    cin >> m;
    vector<Info> b(m);
    for (auto &[name, s, p] : b) {
        cin >> name >> s >> p;
    }
    sort(b.begin(), b.end(), [](const Info &x, const Info &y) {
        if (x.s != y.s) {
            return x.s > y.s;
        }
        return x.p < y.p;
    });

    int rk1 = -1, rk2 = -1;
    set<string> S1, S2;
    for (int i = 0; i < n; i++) {
        if (a[i].name == "lzr010506") {
            rk1 = i + 1;
            break;
        }
        S1.insert(a[i].name);
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (b[i].name == "lzr010506") {
            rk2 = i + 1;
            break;
        }
        if (S1.count(b[i].name)) {
            cnt++;
        }
        S2.insert(b[i].name);
    }

    // 一场比赛可能会有多个同一个学校的队伍参加



    return 0;
}