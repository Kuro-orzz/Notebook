---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/test/aizu_grl_1_a_dijkstra.test.cpp
    title: Graph/test/aizu_grl_1_a_dijkstra.test.cpp
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
    \ 0;\n}\n#line 2 \"Graph/Shortest_path/Dijkstra.h\"\n\nvector<ll> dijkstra(int\
    \ s, int n, vector<vector<pii>> &g) {\n\tvector<int> vis(n + 1);\n\tvector<ll>\
    \ d(n + 1, LLONG_MAX);\n\tpriority_queue<pii, vector<pii>, greater<pii>> pq;\n\
    \tpq.push({d[s], s});\n\td[s] = 0;\n\twhile (!pq.empty()) {\n\t\tauto [dist, u]\
    \ = pq.top(); pq.pop();\n\t\tif (vis[u]) continue;\n\t\tvis[u] = 1;\n\t\tfor (auto\
    \ [v, w] : g[u]) {\n\t\t\tif (d[v] > d[u] + w) {\n\t\t\t\td[v] = d[u] + w;\n\t\
    \t\t\tpq.push({d[v], v});\n\t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\n"
  code: "#include \"../../template.h\"\n\nvector<ll> dijkstra(int s, int n, vector<vector<pii>>\
    \ &g) {\n\tvector<int> vis(n + 1);\n\tvector<ll> d(n + 1, LLONG_MAX);\n\tpriority_queue<pii,\
    \ vector<pii>, greater<pii>> pq;\n\tpq.push({d[s], s});\n\td[s] = 0;\n\twhile\
    \ (!pq.empty()) {\n\t\tauto [dist, u] = pq.top(); pq.pop();\n\t\tif (vis[u]) continue;\n\
    \t\tvis[u] = 1;\n\t\tfor (auto [v, w] : g[u]) {\n\t\t\tif (d[v] > d[u] + w) {\n\
    \t\t\t\td[v] = d[u] + w;\n\t\t\t\tpq.push({d[v], v});\n\t\t\t}\n\t\t}\n\t}\n\t\
    return d;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Graph/Shortest_path/Dijkstra.h
  requiredBy: []
  timestamp: '2025-06-07 22:39:21+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/test/aizu_grl_1_a_dijkstra.test.cpp
documentation_of: Graph/Shortest_path/Dijkstra.h
layout: document
redirect_from:
- /library/Graph/Shortest_path/Dijkstra.h
- /library/Graph/Shortest_path/Dijkstra.h.html
title: Graph/Shortest_path/Dijkstra.h
---
