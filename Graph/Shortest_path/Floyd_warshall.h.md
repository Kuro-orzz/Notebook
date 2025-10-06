---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Graph/Aizu/aizu_grl_1_c_floyd_warshall.test.cpp
    title: Graph/Aizu/aizu_grl_1_c_floyd_warshall.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
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
    \ 0;\n}\n#line 2 \"Graph/Shortest_path/Floyd_warshall.h\"\n\nvoid initTrace(int\
    \ n, vector<vector<int>> &trace) {\n    for (int u = 1; u <= n; ++u) {\n     \
    \   for (int v = 1; v <= n; ++v) {\n            trace[u][v] = u;\n        }\n\
    \    }\n}\n\nvoid floyd_warshall(int n, vector<vector<ll>> &dist, vector<vector<int>>\
    \ &trace) {\n    initTrace(n, trace);\n    for (int k = 1; k <= n; ++k) {\n  \
    \      for (int u = 1; u <= n; ++u) {\n            for (int v = 1; v <= n; ++v)\
    \ {\n                if (dist[u][k] != 1e18 && dist[k][v] != 1e18 && dist[u][v]\
    \ > dist[u][k] + dist[k][v]) {\n                    dist[u][v] = dist[u][k] +\
    \ dist[k][v];\n                    trace[u][v] = trace[k][v];\n              \
    \  }\n            }\n        }\n    }\n}\n"
  code: "#include \"../../template.h\"\n\nvoid initTrace(int n, vector<vector<int>>\
    \ &trace) {\n    for (int u = 1; u <= n; ++u) {\n        for (int v = 1; v <=\
    \ n; ++v) {\n            trace[u][v] = u;\n        }\n    }\n}\n\nvoid floyd_warshall(int\
    \ n, vector<vector<ll>> &dist, vector<vector<int>> &trace) {\n    initTrace(n,\
    \ trace);\n    for (int k = 1; k <= n; ++k) {\n        for (int u = 1; u <= n;\
    \ ++u) {\n            for (int v = 1; v <= n; ++v) {\n                if (dist[u][k]\
    \ != 1e18 && dist[k][v] != 1e18 && dist[u][v] > dist[u][k] + dist[k][v]) {\n \
    \                   dist[u][v] = dist[u][k] + dist[k][v];\n                  \
    \  trace[u][v] = trace[k][v];\n                }\n            }\n        }\n \
    \   }\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Graph/Shortest_path/Floyd_warshall.h
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Graph/Aizu/aizu_grl_1_c_floyd_warshall.test.cpp
documentation_of: Graph/Shortest_path/Floyd_warshall.h
layout: document
redirect_from:
- /library/Graph/Shortest_path/Floyd_warshall.h
- /library/Graph/Shortest_path/Floyd_warshall.h.html
title: Graph/Shortest_path/Floyd_warshall.h
---
