#include "../template.h"

const int N = 2e5 + 6;
vector<vector<int>> adj;
vector<int> a, ans;
set<int> s[N];

// AC: https://oj.vnoi.info/problem/lis
int LIS(vector<int> &a) {
    multiset<int> s;
    for (int x : a) {
        auto it = s.lower_bound(x);
        if (it != s.end()) {
            s.erase(it);
        }
        s.insert(x);
    }
    return s.size();
}

int __LIS(vector<int> &a) {
    vector<int> v;
    for (int x : a) {
        auto it = lower_bound(all(v), x);
        if (it != v.end()) {
            (*it) = min((*it), x);
        } else {
            v.push_back(x);
        }
    }
    return v.size();
}

// LIS on tree
// AC: https://marisaoj.com/problem/276
// AC: https://hnoj.edu.vn/contest/hnoi2023v1/all
void dfs(int u, int par) {
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
        if (s[u].size() < s[v].size()) {
            swap(s[u], s[v]);
        }
        for (auto it : s[v]) {
            s[u].insert(it);
        }
    }
    auto it = s[u].lower_bound(a[u]);
    if (it != s[u].end()) {
        s[u].erase(it);
    }
    s[u].insert(a[u]);
    ans[u] = s[u].size();
}