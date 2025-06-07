#include "../../template.h"

// if exist negative cycle d[S] = 1e18
// else return shortest path
vector<ll> negativeCycle(int S, int n, vector<vector<pii>> &g){
    vector<ll> d(n+1, 1e18);
    d[S] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : g[u]) {
                if (d[u] != 1e18) {
                    d[v] = min(d[v], d[u]+w);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : g[u]) {
                if (d[u] != 1e18 && d[v] > d[u] + w) {
                    d[S] = 1e18;
                    return d;
                }
            }
        }
    }
    return d;
}
