#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../template.h"
#include "Tree/Tree.h"

void solve() {
    int n; cin >> n;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    auto [len, path] = tree_diameter(adj);
    cout << len << " " << path.size() << '\n';
    reverse(all(path));
    for (int x : path) {
        cout << x << " ";
    }
}