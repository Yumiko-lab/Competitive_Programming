#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

int main() {
    int N, D;
    cin >> N >> D;
    vector<PII> acc(N);
    for (auto &[a, b] : acc) {
        cin >> a >> b;
    }
    
    auto check = [&](auto a, auto b) {
        int dx = a.x - b.x;
        int dy = a.y - b.y;
        return dx * dx + dy * dy <= D * D;
    };

    vector<int> is(N);
    is[0] = 1;

    queue<int> q;
    q.emplace(0);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if (!is[i] && check(acc[u], acc[i])) {
                is[i] = 1;
                q.emplace(i);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << (is[i] ? "Yes" : "No") << '\n';
    }

    return 0;
}