---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Shortest_path/Floyd_warshall.h
    title: Graph/Shortest_path/Floyd_warshall.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"Graph/test/aizu_grl_1_c_floyd_warshall.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Graph/Shortest_path/Floyd_warshall.h\"\n\nvoid initTrace(int\
    \ n, vector<vector<int>> &trace) {\n\tfor (int u = 1; u <= n; ++u) {\n\t\tfor\
    \ (int v = 1; v <= n; ++v) {\n\t\t\ttrace[u][v] = u;\n\t\t}\n\t}\n}\n\nvoid floyd_warshall(int\
    \ n, vector<vector<ll>> &dist, vector<vector<int>> &trace) {\n\tinitTrace(n, trace);\n\
    \tfor (int k = 1; k <= n; ++k) {\n\t\tfor (int u = 1; u <= n; ++u) {\n\t\t\tfor\
    \ (int v = 1; v <= n; ++v) {\n\t\t\t\tif (dist[u][k] != 1e18 && dist[k][v] !=\
    \ 1e18 && dist[u][v] > dist[u][k] + dist[k][v]) {\n\t\t\t\t\tdist[u][v] = dist[u][k]\
    \ + dist[k][v];\n\t\t\t\t\ttrace[u][v] = trace[k][v];\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n}\n#line 5 \"Graph/test/aizu_grl_1_c_floyd_warshall.test.cpp\"\n\nvoid\
    \ solve() {\n\tint n, m; cin >> n >> m;\n\tvector<vector<ll>> d(n+1, vector<ll>(n+1,\
    \ 1e18));\n\tvector<vector<int>> trace(n+1, vector<int>(n+1));\n\tfor (int i =\
    \ 1; i <= n; i++) {\n\t\td[i][i] = 0;\n\t}\n\tfor (int i = 0; i < m; i++) {\n\t\
    \tll u, v, w; cin >> u >> v >> w;\n\t\td[u+1][v+1] = min(d[u+1][v+1], w);\n\t\
    }\n\tfloyd_warshall(n, d, trace);\n\tfor (int i = 1; i <= n; i++) {\n\t\tif (d[i][i]\
    \ < 0) {\n\t\t\tcout << \"NEGATIVE CYCLE\\n\";\n\t\t\treturn;\n\t\t}\n\t}\n\t\
    for (int i = 0; i < n; i++) {\n\t\tfor (int j = 0; j < n; j++) {\n\t\t\tif (d[i+1][j+1]\
    \ == 1e18) {\n\t\t\t\tcout << \"INF\";\n\t\t\t} else {\n\t\t\t\tcout << d[i+1][j+1];\n\
    \t\t\t}\n\t\t\tcout << (j == n - 1 ? '\\n' : ' ');\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include \"../../template.h\"\n#include \"../Shortest_path/Floyd_warshall.h\"\
    \n\nvoid solve() {\n\tint n, m; cin >> n >> m;\n\tvector<vector<ll>> d(n+1, vector<ll>(n+1,\
    \ 1e18));\n\tvector<vector<int>> trace(n+1, vector<int>(n+1));\n\tfor (int i =\
    \ 1; i <= n; i++) {\n\t\td[i][i] = 0;\n\t}\n\tfor (int i = 0; i < m; i++) {\n\t\
    \tll u, v, w; cin >> u >> v >> w;\n\t\td[u+1][v+1] = min(d[u+1][v+1], w);\n\t\
    }\n\tfloyd_warshall(n, d, trace);\n\tfor (int i = 1; i <= n; i++) {\n\t\tif (d[i][i]\
    \ < 0) {\n\t\t\tcout << \"NEGATIVE CYCLE\\n\";\n\t\t\treturn;\n\t\t}\n\t}\n\t\
    for (int i = 0; i < n; i++) {\n\t\tfor (int j = 0; j < n; j++) {\n\t\t\tif (d[i+1][j+1]\
    \ == 1e18) {\n\t\t\t\tcout << \"INF\";\n\t\t\t} else {\n\t\t\t\tcout << d[i+1][j+1];\n\
    \t\t\t}\n\t\t\tcout << (j == n - 1 ? '\\n' : ' ');\n\t\t}\n\t}\n}"
  dependsOn:
  - template.h
  - Graph/Shortest_path/Floyd_warshall.h
  isVerificationFile: true
  path: Graph/test/aizu_grl_1_c_floyd_warshall.test.cpp
  requiredBy: []
  timestamp: '2025-06-07 22:39:21+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/test/aizu_grl_1_c_floyd_warshall.test.cpp
layout: document
redirect_from:
- /verify/Graph/test/aizu_grl_1_c_floyd_warshall.test.cpp
- /verify/Graph/test/aizu_grl_1_c_floyd_warshall.test.cpp.html
title: Graph/test/aizu_grl_1_c_floyd_warshall.test.cpp
---
