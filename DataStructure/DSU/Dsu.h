#include "../../template.h"

struct Dsu {
    vector<int> par, sz;

    Dsu(int n): par(n+1), sz(n+1, 1) {
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    int find(int v) {
        if(v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
};