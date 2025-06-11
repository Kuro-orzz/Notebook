#include "../../template.h"

vector<int> EulerTour(vector<int> &st, vector<int> &en, 
                vector<vector<int>> &adj, int root = 0, int type = 0) {
    int n = adj.size();
    st.assign(n, 0);
    en.assign(n, 0);
    vector<int> tour;
    if (type == 0) tour.reserve(n);
    else if (type == 1) tour.reserve(2 * n);
    int pos = 0;
    function<void(int, int)> dfs = [&] (int u, int par) {
        tour.push_back(u);
        st[u] = ++pos;
        for (int v : adj[u]) {
            if (v == par) continue;
            dfs(v, u);
        }
        if (type == 1) {
            tour.push_back(u);
            pos++;
        }
        en[u] = pos;
    };
    dfs(root, -1);
    return tour;
}