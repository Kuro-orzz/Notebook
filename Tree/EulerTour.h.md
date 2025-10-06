---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
    title: Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ 0;\n}\n#line 2 \"Tree/EulerTour.h\"\n\nvector<int> EulerTour(vector<int> &st,\
    \ vector<int> &en, \n                vector<vector<int>> &adj, int root = 0, int\
    \ type = 0) {\n    int n = adj.size();\n    st.assign(n, 0);\n    en.assign(n,\
    \ 0);\n    vector<int> tour;\n    if (type == 0) tour.reserve(n);\n    else if\
    \ (type == 1) tour.reserve(2 * n);\n    int pos = 0;\n    function<void(int, int)>\
    \ dfs = [&] (int u, int par) {\n        tour.push_back(u);\n        st[u] = ++pos;\n\
    \        for (int v : adj[u]) {\n            if (v == par) continue;\n       \
    \     dfs(v, u);\n        }\n        if (type == 1) {\n            tour.push_back(u);\n\
    \            pos++;\n        }\n        en[u] = pos;\n    };\n    dfs(root, -1);\n\
    \    return tour;\n}\n"
  code: "#include \"../template.h\"\n\nvector<int> EulerTour(vector<int> &st, vector<int>\
    \ &en, \n                vector<vector<int>> &adj, int root = 0, int type = 0)\
    \ {\n    int n = adj.size();\n    st.assign(n, 0);\n    en.assign(n, 0);\n   \
    \ vector<int> tour;\n    if (type == 0) tour.reserve(n);\n    else if (type ==\
    \ 1) tour.reserve(2 * n);\n    int pos = 0;\n    function<void(int, int)> dfs\
    \ = [&] (int u, int par) {\n        tour.push_back(u);\n        st[u] = ++pos;\n\
    \        for (int v : adj[u]) {\n            if (v == par) continue;\n       \
    \     dfs(v, u);\n        }\n        if (type == 1) {\n            tour.push_back(u);\n\
    \            pos++;\n        }\n        en[u] = pos;\n    };\n    dfs(root, -1);\n\
    \    return tour;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Tree/EulerTour.h
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
documentation_of: Tree/EulerTour.h
layout: document
redirect_from:
- /library/Tree/EulerTour.h
- /library/Tree/EulerTour.h.html
title: Tree/EulerTour.h
---
