---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DSU/Dsu.h
    title: DataStructure/DSU/Dsu.h
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"DataStructure/Union_find.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"template.h\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n#define MOD\
    \ (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n \n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define fi first\n#define se second\n\nvoid solve();\n\
    \nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/DSU/Dsu.h\"\n\nstruct Dsu{\n    vector<int> par,\
    \ sz;\n    Dsu(int n): par(n+1), sz(n+1, 1){\n        for(int i = 0; i < n; i++)\n\
    \            par[i] = i;\n    }\n    int find(int v){\n        if(v == par[v])\
    \ return v;\n        return par[v] = find(par[v]);\n    }\n    void merge(int\
    \ a, int b){\n        a = find(a);\n        b = find(b);\n        if (a == b)\
    \ return;\n        if(sz[a] < sz[b]) swap(a, b);\n        par[b] = a;\n      \
    \  sz[a] += sz[b];\n    }\n};\n#line 5 \"DataStructure/Union_find.test.cpp\"\n\
    \nvoid solve(){\n    int n, q; cin >> n >> q;\n    Dsu g(n+1);\n    while (q--)\
    \ {\n        int tv, u, v; cin >> tv >> u >> v;\n        if (tv == 0) g.merge(u,\
    \ v);\n        else if (g.find(u) == g.find(v))\n            cout << \"1\\n\"\
    ;\n        else cout << \"0\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../template.h\"\n#include \"DSU/Dsu.h\"\n\nvoid solve(){\n    int n, q; cin\
    \ >> n >> q;\n    Dsu g(n+1);\n    while (q--) {\n        int tv, u, v; cin >>\
    \ tv >> u >> v;\n        if (tv == 0) g.merge(u, v);\n        else if (g.find(u)\
    \ == g.find(v))\n            cout << \"1\\n\";\n        else cout << \"0\\n\"\
    ;\n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/DSU/Dsu.h
  isVerificationFile: true
  path: DataStructure/Union_find.test.cpp
  requiredBy: []
  timestamp: '2025-05-02 20:30:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Union_find.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Union_find.test.cpp
- /verify/DataStructure/Union_find.test.cpp.html
title: DataStructure/Union_find.test.cpp
---
