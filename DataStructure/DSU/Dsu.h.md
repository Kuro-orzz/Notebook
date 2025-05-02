---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Union_find.test.cpp
    title: DataStructure/Union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    \ \n#define vi vector<int>\n#define pii pair<int, int>\n#define fi first\n#define\
    \ se second\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"DataStructure/DSU/Dsu.h\"\n\
    \nstruct Dsu{\n    vector<int> par, sz;\n    Dsu(int n): par(n+1), sz(n+1, 1){\n\
    \        for(int i = 0; i < n; i++)\n            par[i] = i;\n    }\n    int find(int\
    \ v){\n        if(v == par[v]) return v;\n        return par[v] = find(par[v]);\n\
    \    }\n    void merge(int a, int b){\n        a = find(a);\n        b = find(b);\n\
    \        if (a == b) return;\n        if(sz[a] < sz[b]) swap(a, b);\n        par[b]\
    \ = a;\n        sz[a] += sz[b];\n    }\n};\n"
  code: "#include \"../../template.h\"\n\nstruct Dsu{\n    vector<int> par, sz;\n\
    \    Dsu(int n): par(n+1), sz(n+1, 1){\n        for(int i = 0; i < n; i++)\n \
    \           par[i] = i;\n    }\n    int find(int v){\n        if(v == par[v])\
    \ return v;\n        return par[v] = find(par[v]);\n    }\n    void merge(int\
    \ a, int b){\n        a = find(a);\n        b = find(b);\n        if (a == b)\
    \ return;\n        if(sz[a] < sz[b]) swap(a, b);\n        par[b] = a;\n      \
    \  sz[a] += sz[b];\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/DSU/Dsu.h
  requiredBy: []
  timestamp: '2025-05-02 20:27:32+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/Union_find.test.cpp
documentation_of: DataStructure/DSU/Dsu.h
layout: document
redirect_from:
- /library/DataStructure/DSU/Dsu.h
- /library/DataStructure/DSU/Dsu.h.html
title: DataStructure/DSU/Dsu.h
---
