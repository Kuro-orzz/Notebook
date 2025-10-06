#include "../template.h"


// Longest path in graph

int n, m;
vector<vector<int>> adj;
vector<int> vis, d;
stack<int> topo;

void topoSort(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        topoSort(v);
    }
    topo.push(u);
}

void solve() {
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    vis.resize(n+1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        topoSort(i);
    }
    fill(all(vis), 0);
    d.resize(n+1, 0);
    while (!topo.empty()) {
        int u = topo.top(); topo.pop();
        for (int v : adj[u]) {
            d[v] = max(d[v], d[u] + 1);
        }
    }
    cout << *max_element(all(d));
}