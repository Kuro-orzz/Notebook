#include "../template.h"

pair<ll, vector<int>> tree_diameter(const vector<vector<pii>>& g) {
    int n = g.size();
    vector<ll> d(n); // dist
    vector<int> p(n); // par

    function<void(int, int, ll)> dfs = [&] (int u, int par, ll cur_d) {
        d[u] = cur_d;
        p[u] = par;
        for (auto [v, w] : g[u]) {
            if (v == par) continue;
            dfs(v, u, cur_d + w);
        }
    };
    dfs(0, -1, 0);
    // r = furthest node from root
    int r = max_element(d.begin(), d.end()) - d.begin();
    dfs(r, -1, 0);
    // r->s = longest path
    int s = max_element(d.begin(), d.end()) - d.begin();

    vector<int> path;
    for (int x = s; x >= 0; x = p[x]) { 
        path.push_back(x);
    }
    return {d[s], path};
}