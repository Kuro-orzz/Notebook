#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include "../../template.h"
#include "../Mst/Kruskal.h"

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    cout << kruskal(n, edges) << '\n';
}