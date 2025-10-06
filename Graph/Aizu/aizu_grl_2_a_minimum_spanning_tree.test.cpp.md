---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/DSU/Dsu.h
    title: DataStructure/DSU/Dsu.h
  - icon: ':x:'
    path: Graph/Mst/Kruskal.h
    title: Graph/Mst/Kruskal.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"Graph/Aizu/aizu_grl_2_a_minimum_spanning_tree.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
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
    \ mod) % mod;\n    }\n};\n#line 3 \"Graph/Mst/Kruskal.h\"\n\nstruct Edge {\n \
    \   int u, v, w;\n    Edge() {}\n    Edge(int _u, int _v, int _w): u(_u), v(_v),\
    \ w(_w) {}\n};\n\nll kruskal(int n, vector<Edge> &edges) {\n    auto cmp = [&](Edge\
    \ a, Edge b) {\n        return a.w < b.w;\n    };\n    sort(all(edges), cmp);\n\
    \    Dsu g(n);\n    ll ans = 0;\n    for (auto [u, v, w] : edges) {\n        if\
    \ (g.find(u) != g.find(v)) {\n            ans += w;\n            g.merge(u, v);\n\
    \        }\n    }\n    return ans;\n}\n#line 5 \"Graph/Aizu/aizu_grl_2_a_minimum_spanning_tree.test.cpp\"\
    \n\nvoid solve() {\n    int n, m; cin >> n >> m;\n    vector<Edge> edges;\n  \
    \  for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u >> v >> w;\n \
    \       edges.emplace_back(u, v, w);\n    }\n    cout << kruskal(n, edges) <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include \"../../template.h\"\n#include \"../Mst/Kruskal.h\"\n\nvoid solve()\
    \ {\n    int n, m; cin >> n >> m;\n    vector<Edge> edges;\n    for (int i = 0;\
    \ i < m; i++) {\n        int u, v, w; cin >> u >> v >> w;\n        edges.emplace_back(u,\
    \ v, w);\n    }\n    cout << kruskal(n, edges) << '\\n';\n}"
  dependsOn:
  - template.h
  - Graph/Mst/Kruskal.h
  - DataStructure/DSU/Dsu.h
  isVerificationFile: true
  path: Graph/Aizu/aizu_grl_2_a_minimum_spanning_tree.test.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Graph/Aizu/aizu_grl_2_a_minimum_spanning_tree.test.cpp
layout: document
redirect_from:
- /verify/Graph/Aizu/aizu_grl_2_a_minimum_spanning_tree.test.cpp
- /verify/Graph/Aizu/aizu_grl_2_a_minimum_spanning_tree.test.cpp.html
title: Graph/Aizu/aizu_grl_2_a_minimum_spanning_tree.test.cpp
---
