#include "../../template.h"

struct Dsu {
    vector<int> par, sz;
    vector<ll> diff;

    Dsu() {}
    Dsu(int n): par(n+1), sz(n+1, 1), diff(n+1) {
        iota(all(par), 0);
    }

    int find(int v) {
        if (v == par[v]) return v;
        int p = par[v];
        int root = find(p);
        diff[v] += diff[p];
        return par[v] = root;
    }

    // diff[v] - diff[u] = x
    void merge(int u, int v, int x) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if(sz[pu] < sz[pv]) {
            swap(u, v);
            swap(pu, pv);
        	x = -x;
        }
        par[pv] = pu;
        sz[pu] += sz[pv];
        diff[pv] = diff[u] - diff[v] + x;
    }

    // diff[v] - diff[u]
    int getDiff(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) return INT_MAX;
        return diff[v] - diff[u];
    }
};