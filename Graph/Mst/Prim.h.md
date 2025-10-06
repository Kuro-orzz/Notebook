---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DSU/Dsu.h
    title: DataStructure/DSU/Dsu.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/DSU/Dsu.h\"\n\n/* Diff: different between a[u]\
    \ and a[par[u]] */\n\nstruct Dsu {\n    vector<int> par, sz;\n    vector<ll> diff;\n\
    \n    Dsu() {}\n    Dsu(int n): par(n+1), sz(n+1, 1), diff(n+1) {\n        iota(all(par),\
    \ 0);\n    }\n\n    int find(int v) {\n        if (v == par[v]) return v;\n  \
    \      return par[v] = find(par[v]);\n    }\n    \n    void merge(int a, int b)\
    \ {\n        a = find(a);\n        b = find(b);\n        if (a == b) return;\n\
    \        if (sz[a] < sz[b]) swap(a, b);\n        par[b] = a;\n        sz[a] +=\
    \ sz[b];\n    }\n\n    bool same_component(int u, int v) {\n        return find(u)\
    \ == find(v);\n    }\n\n    int component_size(int u) {\n        u = find(u);\n\
    \        return sz[u];\n    }\n\n    /* https://judge.yosupo.jp/problem/unionfind_with_potential\
    \ */\n    int findPotential(int v, int mod) {\n        if (v == par[v]) return\
    \ v;\n        int p = par[v];\n        int root = findPotential(p, mod);\n   \
    \     diff[v] = (diff[v] + diff[p]) % mod;\n        return par[v] = root;\n  \
    \  }\n\n    bool mergePotential(int u, int v, int x, int mod) {\n        int pu\
    \ = findPotential(u, mod);\n        int pv = findPotential(v, mod);\n        if\
    \ (pu == pv) {\n            return (diff[u] - diff[v] + mod) % mod == x;\n   \
    \     }\n        if(sz[pu] < sz[pv]) {\n            swap(u, v);\n            swap(pu,\
    \ pv);\n            x = (mod - x) % mod;\n        }\n        par[pv] = pu;\n \
    \       sz[pu] += sz[pv];\n        diff[pv] = ((diff[u] - diff[v] - x) % mod +\
    \ mod) % mod;\n        return true;\n    }\n\n    int getDiff(int u, int v, int\
    \ mod) {\n        int pu = findPotential(u, mod);\n        int pv = findPotential(v,\
    \ mod);\n        if (pu != pv) return -1;\n        return (diff[u] - diff[v] +\
    \ mod) % mod;\n    }\n};\n#line 3 \"Graph/Mst/Prim.h\"\n\nstruct Edge {\n    int\
    \ u, v, w;\n    Edge() {}\n    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w)\
    \ {}\n};\n\npair<ll, vector<Edge>> prim(int s, int n, vector<vector<pii>> &g)\
    \ {\n    ll ans = 0;\n    vector<int> par(n+1);\n    vector<Edge> MST;\n    vector<int>\
    \ vis(n+1);\n    vector<ll> d(n+1, 1e18);\n    priority_queue<pii, vector<pii>,\
    \ greater<pii>> pq;\n    d[s] = 0;\n    pq.push({d[s], s});\n    while (!pq.empty())\
    \ {\n        auto [dist, u] = pq.top(); pq.pop();\n        if (vis[u]) continue;\n\
    \        vis[u] = 1;\n        ans += dist;\n        if (s != u) {\n          \
    \  MST.emplace_back(u, par[u], dist);\n        }\n        for (auto [v, w] : g[u])\
    \ {\n            if (!vis[v] && d[v] > w) {\n                d[v] = w;\n     \
    \           pq.push({d[v], v});\n            }\n        }\n    }\n    return {ans,\
    \ MST};\n}\n"
  code: "#include \"../../template.h\"\n#include \"../../DataStructure/DSU/Dsu.h\"\
    \n\nstruct Edge {\n    int u, v, w;\n    Edge() {}\n    Edge(int _u, int _v, int\
    \ _w): u(_u), v(_v), w(_w) {}\n};\n\npair<ll, vector<Edge>> prim(int s, int n,\
    \ vector<vector<pii>> &g) {\n    ll ans = 0;\n    vector<int> par(n+1);\n    vector<Edge>\
    \ MST;\n    vector<int> vis(n+1);\n    vector<ll> d(n+1, 1e18);\n    priority_queue<pii,\
    \ vector<pii>, greater<pii>> pq;\n    d[s] = 0;\n    pq.push({d[s], s});\n   \
    \ while (!pq.empty()) {\n        auto [dist, u] = pq.top(); pq.pop();\n      \
    \  if (vis[u]) continue;\n        vis[u] = 1;\n        ans += dist;\n        if\
    \ (s != u) {\n            MST.emplace_back(u, par[u], dist);\n        }\n    \
    \    for (auto [v, w] : g[u]) {\n            if (!vis[v] && d[v] > w) {\n    \
    \            d[v] = w;\n                pq.push({d[v], v});\n            }\n \
    \       }\n    }\n    return {ans, MST};\n}"
  dependsOn:
  - template.h
  - DataStructure/DSU/Dsu.h
  isVerificationFile: false
  path: Graph/Mst/Prim.h
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Mst/Prim.h
layout: document
redirect_from:
- /library/Graph/Mst/Prim.h
- /library/Graph/Mst/Prim.h.html
title: Graph/Mst/Prim.h
---
