---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \ 0;\n}\n#line 2 \"DataStructure/DSU/Dsu_2D.h\"\n\nstruct Dsu_2D {\n    vector<vector<pii>>\
    \ par;\n    vector<vector<int>> sz;\n\n    Dsu_2D() {}\n    Dsu_2D(int n, int\
    \ m): par(n+1, vector<pii>(m+1)), sz(n+1, vector<int>(m+1, 1)) {\n        for(int\
    \ i = 0; i <= n; i++) {\n            for(int j = 0; j <= m; j++)\n           \
    \     par[i][j] = {i, j};\n        }\n    }\n\n    pii find(pii v) {\n       \
    \ if(v == par[v.fi][v.se])\n            return v;\n        return par[v.fi][v.se]\
    \ = find(par[v.fi][v.se]);\n    }\n\n    void merge(pii a, pii b){\n        a\
    \ = find(a);\n        b = find(b);\n        if (a == b) return;\n        if(sz[a.fi][a.se]\
    \ < sz[b.fi][b.se]) swap(a, b);\n        par[b.fi][b.se] = a;\n        sz[a.fi][a.se]\
    \ += sz[b.fi][b.se];\n    }\n};\n"
  code: "#include \"../../template.h\"\n\nstruct Dsu_2D {\n    vector<vector<pii>>\
    \ par;\n    vector<vector<int>> sz;\n\n    Dsu_2D() {}\n    Dsu_2D(int n, int\
    \ m): par(n+1, vector<pii>(m+1)), sz(n+1, vector<int>(m+1, 1)) {\n        for(int\
    \ i = 0; i <= n; i++) {\n            for(int j = 0; j <= m; j++)\n           \
    \     par[i][j] = {i, j};\n        }\n    }\n\n    pii find(pii v) {\n       \
    \ if(v == par[v.fi][v.se])\n            return v;\n        return par[v.fi][v.se]\
    \ = find(par[v.fi][v.se]);\n    }\n\n    void merge(pii a, pii b){\n        a\
    \ = find(a);\n        b = find(b);\n        if (a == b) return;\n        if(sz[a.fi][a.se]\
    \ < sz[b.fi][b.se]) swap(a, b);\n        par[b.fi][b.se] = a;\n        sz[a.fi][a.se]\
    \ += sz[b.fi][b.se];\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/DSU/Dsu_2D.h
  requiredBy: []
  timestamp: '2025-05-25 00:26:18+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/DSU/Dsu_2D.h
layout: document
redirect_from:
- /library/DataStructure/DSU/Dsu_2D.h
- /library/DataStructure/DSU/Dsu_2D.h.html
title: DataStructure/DSU/Dsu_2D.h
---
