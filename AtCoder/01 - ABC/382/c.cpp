#include <bits/stdc++.h>
using namespace std;

constexpr int K = 2E5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> id(K + 1, -1);
    
    int cur = K;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        while (cur > a) {
            cur--;
            id[cur] = i + 1;
        }
    }

    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        cout << id[b] << '\n';
    }

    return 0;
}