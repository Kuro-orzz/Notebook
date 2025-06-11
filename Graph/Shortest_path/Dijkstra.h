#include "../../template.h"

vector<ll> dijkstra(int s, int n, vector<vector<pii>> &g) {
    vector<int> vis(n + 1);
    vector<ll> d(n + 1, LLONG_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({d[s], s});
    d[s] = 0;
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}