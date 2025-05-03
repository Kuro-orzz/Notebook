#include "../../template.h"

class BinLift {
public:
    int n;
    vector<vector<int>> tree, up;
    vector<int> lg, h;
    BinLift(int n): n(n), tree(n), up(n, vector<int>(20)), lg(20), h(n) {}

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

    void addEdge(int u, int v) {
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    int jump(int u, int v, int i) {
        int t = lca(u, v);
        int diff1 = h[u]-h[t];
        int diff2 = h[v]-h[t];
        if (i > diff1 + diff2) return -1;
        if (i <= diff1) return ancestor_k(u, i);
        else {
            int step = i-diff1;
            return ancestor_k(v, diff2-step);
        }
    }

    int lca(int u, int v) {
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