#include "../../template.h"

struct Lca {
    vector<vector<int>> tree, up;
    vector<int> h;

    Lca() {}
    Lca(int n): tree(n), up(n+1, vector<int>(20)), h(n+1, 0) {}

    void dfs(int u, int p) {
        for(int v : tree[u]) {
            if(v == p) continue;
            up[v][0] = u;
            h[v] = h[u] + 1;
            for(int j = 1; j < 20; j++)
                up[v][j] = up[up[v][j-1]][j-1];
            dfs(v, u);
        }
    }

    int query(int u, int v) {
        if(h[u] < h[v]) swap(u, v);
        int k = h[u]-h[v];
        u = ancestor_k(u, k);
        if(u == v) return u;

        k = __lg(h[u]);
        for(int j = k; j >= 0; j--) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    int ancestor_k(int u, int k) {
        for(int j = 0; (1 << j) <= k; j++) {
            if(k >> j & 1)
                u = up[u][j];
        }
        return u;
    }
};