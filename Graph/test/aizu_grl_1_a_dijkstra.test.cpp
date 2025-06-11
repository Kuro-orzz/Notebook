#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../../template.h"
#include "../Shortest_path/Dijkstra.h"

void solve() {
    int n, m, s; cin >> n >> m >> s;
    vector<vector<pii>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<ll> d = dijkstra(s, n, adj);
    for (int i = 0; i < n; i++) {
        if (d[i] == LLONG_MAX) {
            cout << "INF\n";
        } else {
            cout << d[i] << '\n';
        }
    }
}