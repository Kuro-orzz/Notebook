---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Tree/Tree/Lca.h
    title: Tree/Tree/Lca.h
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"Tree/Yosupo/Lowest_common_ancestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"template.h\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n#define MOD\
    \ (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x) x.erase(unique(all(x)),\
    \ x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define\
    \ inf (ll)1e18\n\n#define vi vector<int>\n#define pii pair<int, int>\n#define\
    \ pll pair<ll, ll>\n#define fi first\n#define se second\n\nconst int mod = 998244353;\n\
    \nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"Tree/Tree/Lca.h\"\n\nstruct\
    \ Lca {\n    vector<vector<int>> tree, up;\n    vector<int> h;\n\n    Lca() {}\n\
    \    Lca(int n): tree(n+1), up(n+1, vector<int>(20)), h(n+1, 0) {}\n\n    void\
    \ dfs(int u, int p) {\n        for(int v : tree[u]) {\n            if(v == p)\
    \ continue;\n            up[v][0] = u;\n            h[v] = h[u] + 1;\n       \
    \     for(int j = 1; j < 20; j++) {\n                up[v][j] = up[up[v][j-1]][j-1];\n\
    \            }\n            dfs(v, u);\n        }\n    }\n\n    void addEdge(int\
    \ u, int v) {\n        tree[u].emplace_back(v);\n        tree[v].emplace_back(u);\n\
    \    }\n\n    int query(int u, int v) {\n        if(h[u] < h[v]) swap(u, v);\n\
    \        int k = h[u]-h[v];\n        u = ancestor_k(u, k);\n        if(u == v)\
    \ return u;\n\n        k = __lg(h[u]);\n        for(int j = k; j >= 0; j--) {\n\
    \            if(up[u][j] != up[v][j]) {\n                u = up[u][j];\n     \
    \           v = up[v][j];\n            }\n        }\n        return up[u][0];\n\
    \    }\n\n    int dist(int u, int v) {\n        int node = query(u, v);\n    \
    \    return h[u] + h[v] - 2 * h[node];\n    }\n\n    int ancestor_k(int u, int\
    \ k) {\n        for(int j = 0; (1 << j) <= k; j++) {\n            if(k >> j &\
    \ 1)\n                u = up[u][j];\n        }\n        return u;\n    }\n};\n\
    #line 5 \"Tree/Yosupo/Lowest_common_ancestor.test.cpp\"\n\nvoid solve() {\n  \
    \  int n, q; cin >> n >> q;\n    Lca lca(n);\n    for (int i = 1; i <= n-1; i++)\
    \ {\n        int x; cin >> x;\n        lca.tree[i].emplace_back(x);\n        lca.tree[x].emplace_back(i);\n\
    \    }\n    lca.dfs(0, -1);\n    while (q--) {\n        int u, v; cin >> u >>\
    \ v;\n        cout << lca.query(u, v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../template.h\"\
    \n#include \"../Tree/Lca.h\"\n\nvoid solve() {\n    int n, q; cin >> n >> q;\n\
    \    Lca lca(n);\n    for (int i = 1; i <= n-1; i++) {\n        int x; cin >>\
    \ x;\n        lca.tree[i].emplace_back(x);\n        lca.tree[x].emplace_back(i);\n\
    \    }\n    lca.dfs(0, -1);\n    while (q--) {\n        int u, v; cin >> u >>\
    \ v;\n        cout << lca.query(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - template.h
  - Tree/Tree/Lca.h
  isVerificationFile: true
  path: Tree/Yosupo/Lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Tree/Yosupo/Lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/Tree/Yosupo/Lowest_common_ancestor.test.cpp
- /verify/Tree/Yosupo/Lowest_common_ancestor.test.cpp.html
title: Tree/Yosupo/Lowest_common_ancestor.test.cpp
---
