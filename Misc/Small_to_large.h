#include "../template.h"

const int N = 1e5 + 6;
vector<vector<int>> adj;
vector<int> color;
set<int> cnt[N];
vector<int> ans;

// AC: https://oj.vnoi.info/src/6109008
void dfs(int u, int par) {
    cnt[u].insert(color[u]);
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
        if (cnt[u].size() < cnt[v].size()) {
            cnt[u].swap(cnt[v]);
        }
        for (int i : cnt[v]) {
            cnt[u].insert(i);
        }
    }
    ans[u] = cnt[u].size();
}