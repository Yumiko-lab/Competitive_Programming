#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> ans;
    vector<int> temp;
    auto dfs = [&](auto self, int u, int pre) -> void {
        if ((M - (pre + 10) + 1 + 9) / 10 < N - u) {
            return;
        }
        if (u == N) {
            ans.push_back(temp);
            return;
        }
        for (int i = pre + 10; i <= M; i++) {
            temp.push_back(i);
            self(self, u + 1, i);
            temp.pop_back();
        }
    };

    dfs(dfs, 0, -9);

    cout << ans.size() << '\n';
    for (auto v : ans) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}