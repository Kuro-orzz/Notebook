---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Tree/Tree_diameter.h
    title: Tree/Tree_diameter.h
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"Tree/Yosupo/Diameter_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/tree_diameter\"\n\n#line 2 \"template.h\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n#define\
    \ MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x) x.erase(unique(all(x)),\
    \ x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define\
    \ inf (ll)1e18\n\n#define vi vector<int>\n#define pii pair<int, int>\n#define\
    \ pll pair<ll, ll>\n#define fi first\n#define se second\n\nconst int mod = 998244353;\n\
    \nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"Tree/Tree_diameter.h\"\n\n\
    pair<ll, vector<int>> tree_diameter(const vector<vector<pii>>& g) {\n    int n\
    \ = g.size();\n    vector<ll> d(n); // dist\n    vector<int> p(n); // par\n\n\
    \    function<void(int, int, ll)> dfs = [&] (int u, int par, ll cur_d) {\n   \
    \     d[u] = cur_d;\n        p[u] = par;\n        for (auto [v, w] : g[u]) {\n\
    \            if (v == par) continue;\n            dfs(v, u, cur_d + w);\n    \
    \    }\n    };\n    dfs(0, -1, 0);\n    // r = furthest node from root\n    int\
    \ r = max_element(d.begin(), d.end()) - d.begin();\n    dfs(r, -1, 0);\n    //\
    \ r->s = longest path\n    int s = max_element(d.begin(), d.end()) - d.begin();\n\
    \n    vector<int> path;\n    for (int x = s; x >= 0; x = p[x]) { \n        path.push_back(x);\n\
    \    }\n    return {d[s], path};\n}\n#line 5 \"Tree/Yosupo/Diameter_tree.test.cpp\"\
    \n\nvoid solve() {\n    int n; cin >> n;\n    vector<vector<pii>> adj(n);\n  \
    \  for (int i = 0; i < n-1; i++) {\n        int u, v, w; cin >> u >> v >> w;\n\
    \        adj[u].emplace_back(v, w);\n        adj[v].emplace_back(u, w);\n    }\n\
    \    auto [len, path] = tree_diameter(adj);\n    cout << len << \" \" << path.size()\
    \ << '\\n';\n    reverse(all(path));\n    for (int x : path) {\n        cout <<\
    \ x << \" \";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../../template.h\"\n#include \"../Tree_diameter.h\"\n\nvoid solve() {\n  \
    \  int n; cin >> n;\n    vector<vector<pii>> adj(n);\n    for (int i = 0; i <\
    \ n-1; i++) {\n        int u, v, w; cin >> u >> v >> w;\n        adj[u].emplace_back(v,\
    \ w);\n        adj[v].emplace_back(u, w);\n    }\n    auto [len, path] = tree_diameter(adj);\n\
    \    cout << len << \" \" << path.size() << '\\n';\n    reverse(all(path));\n\
    \    for (int x : path) {\n        cout << x << \" \";\n    }\n}"
  dependsOn:
  - template.h
  - Tree/Tree_diameter.h
  isVerificationFile: true
  path: Tree/Yosupo/Diameter_tree.test.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Tree/Yosupo/Diameter_tree.test.cpp
layout: document
redirect_from:
- /verify/Tree/Yosupo/Diameter_tree.test.cpp
- /verify/Tree/Yosupo/Diameter_tree.test.cpp.html
title: Tree/Yosupo/Diameter_tree.test.cpp
---
