#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, A, B, C;
    cin >> N >> M >> A >> B >> C;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U--, V--;
        adj[U].emplace_back(V);
        adj[V].emplace_back(U);
    }

    

    return 0;
}