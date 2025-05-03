---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tree/Jump_on_tree.test.cpp
    title: Tree/Jump_on_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    \ \n#define vi vector<int>\n#define pii pair<int, int>\n#define fi first\n#define\
    \ se second\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"Tree/Tree/BinaryLifting.h\"\
    \n\nclass BinLift {\npublic:\n    int n;\n    vector<vector<int>> tree, up;\n\
    \    vector<int> lg, h;\n    BinLift(int n): n(n), tree(n), up(n, vector<int>(20)),\
    \ lg(20), h(n) {}\n\n    void dfs(int u, int p) {\n        for(int v : tree[u])\
    \ {\n            if(v == p) continue;\n            up[v][0] = u;\n           \
    \ h[v] = h[u] + 1;\n            for(int j = 1; j < 20; j++)\n                up[v][j]\
    \ = up[up[v][j-1]][j-1];\n            dfs(v, u);\n        }\n    }\n\n    void\
    \ addEdge(int u, int v) {\n        tree[u].emplace_back(v);\n        tree[v].emplace_back(u);\n\
    \    }\n\n    int jump(int u, int v, int i) {\n        int t = lca(u, v);\n  \
    \      int diff1 = h[u]-h[t];\n        int diff2 = h[v]-h[t];\n        if (i >\
    \ diff1 + diff2) return -1;\n        if (i <= diff1) return ancestor_k(u, i);\n\
    \        else {\n            int step = i-diff1;\n            return ancestor_k(v,\
    \ diff2-step);\n        }\n    }\n\n    int lca(int u, int v) {\n        if(h[u]\
    \ < h[v]) swap(u, v);\n        int k = h[u]-h[v];\n        u = ancestor_k(u, k);\n\
    \        if(u == v) return u;\n\n        k = __lg(h[u]);\n        for(int j =\
    \ k; j >= 0; j--) {\n            if(up[u][j] != up[v][j]) {\n                u\
    \ = up[u][j];\n                v = up[v][j];\n            }\n        }\n     \
    \   return up[u][0];\n    }\n\n    int ancestor_k(int u, int k) {\n        for(int\
    \ j = 0; (1 << j) <= k; j++) {\n            if(k >> j & 1)\n                u\
    \ = up[u][j];\n        }\n        return u;\n    }\n};\n"
  code: "#include \"../../template.h\"\n\nclass BinLift {\npublic:\n    int n;\n \
    \   vector<vector<int>> tree, up;\n    vector<int> lg, h;\n    BinLift(int n):\
    \ n(n), tree(n), up(n, vector<int>(20)), lg(20), h(n) {}\n\n    void dfs(int u,\
    \ int p) {\n        for(int v : tree[u]) {\n            if(v == p) continue;\n\
    \            up[v][0] = u;\n            h[v] = h[u] + 1;\n            for(int\
    \ j = 1; j < 20; j++)\n                up[v][j] = up[up[v][j-1]][j-1];\n     \
    \       dfs(v, u);\n        }\n    }\n\n    void addEdge(int u, int v) {\n   \
    \     tree[u].emplace_back(v);\n        tree[v].emplace_back(u);\n    }\n\n  \
    \  int jump(int u, int v, int i) {\n        int t = lca(u, v);\n        int diff1\
    \ = h[u]-h[t];\n        int diff2 = h[v]-h[t];\n        if (i > diff1 + diff2)\
    \ return -1;\n        if (i <= diff1) return ancestor_k(u, i);\n        else {\n\
    \            int step = i-diff1;\n            return ancestor_k(v, diff2-step);\n\
    \        }\n    }\n\n    int lca(int u, int v) {\n        if(h[u] < h[v]) swap(u,\
    \ v);\n        int k = h[u]-h[v];\n        u = ancestor_k(u, k);\n        if(u\
    \ == v) return u;\n\n        k = __lg(h[u]);\n        for(int j = k; j >= 0; j--)\
    \ {\n            if(up[u][j] != up[v][j]) {\n                u = up[u][j];\n \
    \               v = up[v][j];\n            }\n        }\n        return up[u][0];\n\
    \    }\n\n    int ancestor_k(int u, int k) {\n        for(int j = 0; (1 << j)\
    \ <= k; j++) {\n            if(k >> j & 1)\n                u = up[u][j];\n  \
    \      }\n        return u;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Tree/Tree/BinaryLifting.h
  requiredBy: []
  timestamp: '2025-05-04 01:50:55+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tree/Jump_on_tree.test.cpp
documentation_of: Tree/Tree/BinaryLifting.h
layout: document
redirect_from:
- /library/Tree/Tree/BinaryLifting.h
- /library/Tree/Tree/BinaryLifting.h.html
title: Tree/Tree/BinaryLifting.h
---
