#include "../../template.h"

/* Diff: different between a[u] and a[par[u]] */

struct Dsu {
    vector<int> par, sz;
    vector<ll> diff;

    Dsu() {}
    Dsu(int n): par(n+1), sz(n+1, 1), diff(n+1) {
        iota(all(par), 0);
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

    bool same_component(int u, int v) {
        return find(u) == find(v);
    }

    int component_size(int u) {
        u = find(u);
        return sz[u];
    }

    /* https://judge.yosupo.jp/problem/unionfind_with_potential */
    int findPotential(int v, int mod) {
        if (v == par[v]) return v;
        int p = par[v];
        int root = findPotential(p, mod);
        diff[v] = (diff[v] + diff[p]) % mod;
        return par[v] = root;
    }

    bool mergePotential(int u, int v, int x, int mod) {
        int pu = findPotential(u, mod);
        int pv = findPotential(v, mod);
        if (pu == pv) {
            return (diff[u] - diff[v] + mod) % mod == x;
        }
        if(sz[pu] < sz[pv]) {
            swap(u, v);
            swap(pu, pv);
            x = (mod - x) % mod;
        }
        par[pv] = pu;
        sz[pu] += sz[pv];
        diff[pv] = ((diff[u] - diff[v] - x) % mod + mod) % mod;
        return true;
    }

    int getDiff(int u, int v, int mod) {
        int pu = findPotential(u, mod);
        int pv = findPotential(v, mod);
        if (pu != pv) return -1;
        return (diff[u] - diff[v] + mod) % mod;
    }
};