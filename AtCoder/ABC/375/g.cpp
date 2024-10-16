#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;

constexpr int N = 200010, M = N * 2, K = N;

int n, m;
int h[N], e[M], w[M], ne[M], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

struct Edge {
    int u, v, w;
    bool used;
} edge[K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<PII, int> id;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {u, v, w};
        add(u, v, w), add(v, u, w);
        id[{u, v}] = id[{v, u}] = i;
    }

    int pre = -1;
    vector<i64> dis(n + 1);
    vector<bool> vis(n + 1);
    auto dijkstra = [&](auto s) {
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        dis[s] = 0;
        heap.push({dis[s], s});
        while (!heap.empty()) {
            auto [d, u] = heap.top();
            heap.pop();
            if (pre == -1) {
                pre = u;
            } else {
                edge[id[{pre, u}]].used = true;
            }
            if (vis[u]) {
                continue;
            }
            vis[u] = true;
            for (int i = h[u]; ~i; i = ne[i]) {
                int v = e[i];
                if (dis[v] > d + w[i]) {
                    dis[v] = d + w[i];
                    heap.push({dis[v], v});
                }
            }
        }
    };

    dijkstra(1);

    return 0;
}

/*

不是 MST, 而是最短路径树

1. 非树边 : NO (去掉改边, 不会影响最短路)
2. 树边 : 
    1. 
    2. 

*/