---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tree/Diameter_tree.test.cpp
    title: Tree/Diameter_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\
    #define vi vector<int>\n#define pii pair<int, int>\n#define pll pair<ll, ll>\n\
    #define fi first\n#define se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\
    \nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Tree/Tree/Tree.h\"\n\npair<ll, vector<int>> tree_diameter(const\
    \ vector<vector<pii>>& g) {\n    int n = g.size();\n    vector<ll> d(n); // dist\n\
    \    vector<int> p(n); // par\n\n    function<void(int, int, ll)> dfs = [&] (int\
    \ u, int par, ll cur_d) {\n        d[u] = cur_d;\n        p[u] = par;\n      \
    \  for (auto [v, w] : g[u]) {\n        \tif (v == par) continue;\n           \
    \ dfs(v, u, cur_d + w);\n        }\n    };\n    dfs(0, -1, 0);\n    // r = furthest\
    \ node from root\n    int r = max_element(d.begin(), d.end()) - d.begin();\n \
    \   dfs(r, -1, 0);\n    // r->s = longest path\n    int s = max_element(d.begin(),\
    \ d.end()) - d.begin();\n\n    vector<int> path;\n    for (int x = s; x >= 0;\
    \ x = p[x]) { \n    \tpath.push_back(x);\n    }\n    return {d[s], path};\n}\n"
  code: "#include \"../../template.h\"\n\npair<ll, vector<int>> tree_diameter(const\
    \ vector<vector<pii>>& g) {\n    int n = g.size();\n    vector<ll> d(n); // dist\n\
    \    vector<int> p(n); // par\n\n    function<void(int, int, ll)> dfs = [&] (int\
    \ u, int par, ll cur_d) {\n        d[u] = cur_d;\n        p[u] = par;\n      \
    \  for (auto [v, w] : g[u]) {\n        \tif (v == par) continue;\n           \
    \ dfs(v, u, cur_d + w);\n        }\n    };\n    dfs(0, -1, 0);\n    // r = furthest\
    \ node from root\n    int r = max_element(d.begin(), d.end()) - d.begin();\n \
    \   dfs(r, -1, 0);\n    // r->s = longest path\n    int s = max_element(d.begin(),\
    \ d.end()) - d.begin();\n\n    vector<int> path;\n    for (int x = s; x >= 0;\
    \ x = p[x]) { \n    \tpath.push_back(x);\n    }\n    return {d[s], path};\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Tree/Tree/Tree.h
  requiredBy: []
  timestamp: '2025-05-06 22:27:53+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tree/Diameter_tree.test.cpp
documentation_of: Tree/Tree/Tree.h
layout: document
redirect_from:
- /library/Tree/Tree/Tree.h
- /library/Tree/Tree/Tree.h.html
title: Tree/Tree/Tree.h
---
