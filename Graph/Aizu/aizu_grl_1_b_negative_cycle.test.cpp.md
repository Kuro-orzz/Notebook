---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Shortest_path/Bellman_ford.h
    title: Graph/Shortest_path/Bellman_ford.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Graph/Shortest_path/Bellman_ford.h\"\n\n// if exist negative\
    \ cycle d[S] = 1e18\n// else return shortest path\nvector<ll> negativeCycle(int\
    \ S, int n, vector<vector<pii>> &g){\n    vector<ll> d(n+1, 1e18);\n    d[S] =\
    \ 0;\n    for (int i = 0; i < n - 1; i++) {\n        for (int u = 0; u < n; u++)\
    \ {\n            for (auto [v, w] : g[u]) {\n                if (d[u] != 1e18)\
    \ {\n                    d[v] = min(d[v], d[u]+w);\n                }\n      \
    \      }\n        }\n    }\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ u = 0; u < n; u++) {\n            for (auto [v, w] : g[u]) {\n             \
    \   if (d[u] != 1e18 && d[v] > d[u] + w) {\n                    d[S] = 1e18;\n\
    \                    return d;\n                }\n            }\n        }\n\
    \    }\n    return d;\n}\n#line 5 \"Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp\"\
    \n\nvoid solve() {\n    int n, m, s; cin >> n >> m >> s;\n    vector<vector<pii>>\
    \ adj(n+1);\n    for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u\
    \ >> v >> w;\n        adj[u].push_back({v, w});\n    }\n    vector<ll> d = negativeCycle(s,\
    \ n, adj);\n    if (d[s] == 1e18) {\n        cout << \"NEGATIVE CYCLE\\n\";\n\
    \        return;\n    }\n    for (int i = 0; i < n; i++) {\n        if (d[i] ==\
    \ 1e18) {\n            cout << \"INF\\n\";\n        } else {\n            cout\
    \ << d[i] << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include \"../../template.h\"\n#include \"../Shortest_path/Bellman_ford.h\"\
    \n\nvoid solve() {\n    int n, m, s; cin >> n >> m >> s;\n    vector<vector<pii>>\
    \ adj(n+1);\n    for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u\
    \ >> v >> w;\n        adj[u].push_back({v, w});\n    }\n    vector<ll> d = negativeCycle(s,\
    \ n, adj);\n    if (d[s] == 1e18) {\n        cout << \"NEGATIVE CYCLE\\n\";\n\
    \        return;\n    }\n    for (int i = 0; i < n; i++) {\n        if (d[i] ==\
    \ 1e18) {\n            cout << \"INF\\n\";\n        } else {\n            cout\
    \ << d[i] << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  - Graph/Shortest_path/Bellman_ford.h
  isVerificationFile: true
  path: Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp
layout: document
redirect_from:
- /verify/Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp
- /verify/Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp.html
title: Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp
---
