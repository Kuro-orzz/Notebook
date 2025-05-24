---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tree/Vertex_add_subtree_sum.test.cpp
    title: Tree/Vertex_add_subtree_sum.test.cpp
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
    \ 0;\n}\n#line 2 \"Tree/EulerTour/EulerTour.h\"\n\nvector<int> EulerTour(vector<int>\
    \ &st, vector<int> &en, \n\t\t\t\tvector<vector<int>> &adj, int root = 0, int\
    \ type = 0) {\n\tint n = adj.size();\n\tst.assign(n, 0);\n\ten.assign(n, 0);\n\
    \tvector<int> tour;\n\tif (type == 0) tour.reserve(n);\n\telse if (type == 1)\
    \ tour.reserve(2 * n);\n\tint pos = 0;\n\tfunction<void(int, int)> dfs = [&] (int\
    \ u, int par) {\n\t\ttour.push_back(u);\n\t\tst[u] = ++pos;\n\t\tfor (int v :\
    \ adj[u]) {\n\t\t\tif (v == par) continue;\n\t\t\tdfs(v, u);\n\t\t}\n\t\tif (type\
    \ == 1) {\n\t\t\ttour.push_back(u);\n\t\t\tpos++;\n\t\t}\n\t\ten[u] = pos;\n\t\
    };\n\tdfs(root, -1);\n\treturn tour;\n}\n"
  code: "#include \"../../template.h\"\n\nvector<int> EulerTour(vector<int> &st, vector<int>\
    \ &en, \n\t\t\t\tvector<vector<int>> &adj, int root = 0, int type = 0) {\n\tint\
    \ n = adj.size();\n\tst.assign(n, 0);\n\ten.assign(n, 0);\n\tvector<int> tour;\n\
    \tif (type == 0) tour.reserve(n);\n\telse if (type == 1) tour.reserve(2 * n);\n\
    \tint pos = 0;\n\tfunction<void(int, int)> dfs = [&] (int u, int par) {\n\t\t\
    tour.push_back(u);\n\t\tst[u] = ++pos;\n\t\tfor (int v : adj[u]) {\n\t\t\tif (v\
    \ == par) continue;\n\t\t\tdfs(v, u);\n\t\t}\n\t\tif (type == 1) {\n\t\t\ttour.push_back(u);\n\
    \t\t\tpos++;\n\t\t}\n\t\ten[u] = pos;\n\t};\n\tdfs(root, -1);\n\treturn tour;\n\
    }"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Tree/EulerTour/EulerTour.h
  requiredBy: []
  timestamp: '2025-05-25 00:26:18+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tree/Vertex_add_subtree_sum.test.cpp
documentation_of: Tree/EulerTour/EulerTour.h
layout: document
redirect_from:
- /library/Tree/EulerTour/EulerTour.h
- /library/Tree/EulerTour/EulerTour.h.html
title: Tree/EulerTour/EulerTour.h
---
