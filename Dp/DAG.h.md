---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
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
    \ 0;\n}\n#line 2 \"Dp/DAG.h\"\n\n\n// Longest path in graph\n\nint n, m;\nvector<vector<int>>\
    \ adj;\nvector<int> vis, d;\nstack<int> topo;\n\nvoid topoSort(int u) {\n    vis[u]\
    \ = 1;\n    for (int v : adj[u]) {\n        if (vis[v]) continue;\n        topoSort(v);\n\
    \    }\n    topo.push(u);\n}\n\nvoid solve() {\n    cin >> n >> m;\n    adj.resize(n+1);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v; cin >> u >> v;\n       \
    \ adj[u].push_back(v);\n    }\n    vis.resize(n+1);\n    for (int i = 1; i <=\
    \ n; i++) {\n        if (vis[i]) continue;\n        topoSort(i);\n    }\n    fill(all(vis),\
    \ 0);\n    d.resize(n+1, 0);\n    while (!topo.empty()) {\n        int u = topo.top();\
    \ topo.pop();\n        for (int v : adj[u]) {\n            d[v] = max(d[v], d[u]\
    \ + 1);\n        }\n    }\n    cout << *max_element(all(d));\n}\n"
  code: "#include \"../template.h\"\n\n\n// Longest path in graph\n\nint n, m;\nvector<vector<int>>\
    \ adj;\nvector<int> vis, d;\nstack<int> topo;\n\nvoid topoSort(int u) {\n    vis[u]\
    \ = 1;\n    for (int v : adj[u]) {\n        if (vis[v]) continue;\n        topoSort(v);\n\
    \    }\n    topo.push(u);\n}\n\nvoid solve() {\n    cin >> n >> m;\n    adj.resize(n+1);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v; cin >> u >> v;\n       \
    \ adj[u].push_back(v);\n    }\n    vis.resize(n+1);\n    for (int i = 1; i <=\
    \ n; i++) {\n        if (vis[i]) continue;\n        topoSort(i);\n    }\n    fill(all(vis),\
    \ 0);\n    d.resize(n+1, 0);\n    while (!topo.empty()) {\n        int u = topo.top();\
    \ topo.pop();\n        for (int v : adj[u]) {\n            d[v] = max(d[v], d[u]\
    \ + 1);\n        }\n    }\n    cout << *max_element(all(d));\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Dp/DAG.h
  requiredBy: []
  timestamp: '2025-10-06 23:30:53+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dp/DAG.h
layout: document
redirect_from:
- /library/Dp/DAG.h
- /library/Dp/DAG.h.html
title: Dp/DAG.h
---
