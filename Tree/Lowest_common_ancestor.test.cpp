#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../template.h"
#include "Tree/Lca.h"

void solve() {
    int n, q; cin >> n >> q;
    Lca lca(n);
    for (int i = 1; i <= n-1; i++) {
        int x; cin >> x;
        lca.tree[i].emplace_back(x);
        lca.tree[x].emplace_back(i);
    }
    lca.dfs(0, -1);
    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca.query(u, v) << '\n';
    }
}