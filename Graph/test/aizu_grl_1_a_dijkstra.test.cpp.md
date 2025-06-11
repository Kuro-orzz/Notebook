---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Shortest_path/Dijkstra.h
    title: Graph/Shortest_path/Dijkstra.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"Graph/test/aizu_grl_1_a_dijkstra.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\n\n#line\
    \ 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define\
    \ ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Graph/Shortest_path/Dijkstra.h\"\n\nvector<ll> dijkstra(int\
    \ s, int n, vector<vector<pii>> &g) {\n    vector<int> vis(n + 1);\n    vector<ll>\
    \ d(n + 1, LLONG_MAX);\n    priority_queue<pii, vector<pii>, greater<pii>> pq;\n\
    \    pq.push({d[s], s});\n    d[s] = 0;\n    while (!pq.empty()) {\n        auto\
    \ [dist, u] = pq.top(); pq.pop();\n        if (vis[u]) continue;\n        vis[u]\
    \ = 1;\n        for (auto [v, w] : g[u]) {\n            if (d[v] > d[u] + w) {\n\
    \                d[v] = d[u] + w;\n                pq.push({d[v], v});\n     \
    \       }\n        }\n    }\n    return d;\n}\n#line 5 \"Graph/test/aizu_grl_1_a_dijkstra.test.cpp\"\
    \n\nvoid solve() {\n    int n, m, s; cin >> n >> m >> s;\n    vector<vector<pii>>\
    \ adj(n+1);\n    for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u\
    \ >> v >> w;\n        adj[u].push_back({v, w});\n    }\n    vector<ll> d = dijkstra(s,\
    \ n, adj);\n    for (int i = 0; i < n; i++) {\n        if (d[i] == LLONG_MAX)\
    \ {\n            cout << \"INF\\n\";\n        } else {\n            cout << d[i]\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../../template.h\"\n#include \"../Shortest_path/Dijkstra.h\"\n\n\
    void solve() {\n    int n, m, s; cin >> n >> m >> s;\n    vector<vector<pii>>\
    \ adj(n+1);\n    for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u\
    \ >> v >> w;\n        adj[u].push_back({v, w});\n    }\n    vector<ll> d = dijkstra(s,\
    \ n, adj);\n    for (int i = 0; i < n; i++) {\n        if (d[i] == LLONG_MAX)\
    \ {\n            cout << \"INF\\n\";\n        } else {\n            cout << d[i]\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  - Graph/Shortest_path/Dijkstra.h
  isVerificationFile: true
  path: Graph/test/aizu_grl_1_a_dijkstra.test.cpp
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/test/aizu_grl_1_a_dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Graph/test/aizu_grl_1_a_dijkstra.test.cpp
- /verify/Graph/test/aizu_grl_1_a_dijkstra.test.cpp.html
title: Graph/test/aizu_grl_1_a_dijkstra.test.cpp
---
