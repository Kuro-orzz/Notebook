#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../../template.h"
#include "../Shortest_path/Bellman_ford.h"

void solve() {
    int n, m, s; cin >> n >> m >> s;
    vector<vector<pii>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<ll> d = negativeCycle(s, n, adj);
    if (d[s] == 1e18) {
        cout << "NEGATIVE CYCLE\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (d[i] == 1e18) {
            cout << "INF\n";
        } else {
            cout << d[i] << '\n';
        }
    }
}