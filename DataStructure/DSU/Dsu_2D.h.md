---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/Aizu/test_dsu_2d.cpp
    title: DataStructure/Aizu/test_dsu_2d.cpp
  - icon: ':warning:'
    path: DataStructure/Aizu/test_dsu_2d_2.cpp
    title: DataStructure/Aizu/test_dsu_2d_2.cpp
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
    \ 0;\n}\n#line 2 \"DataStructure/DSU/Dsu_2D.h\"\n\ntemplate <typename T>\nstruct\
    \ Dsu_2D {\n    int n, m;\n    vector<vector<pii>> par;\n    vector<vector<int>>\
    \ sz;\n\n    Dsu_2D() {}\n    Dsu_2D(int _n, int _m): n(_n), m(_m) {\n       \
    \ par.resize(n+1, vector<pii>(m+1));\n        sz.resize(n+1, vector<int>(m+1,\
    \ 1));\n        for (int i = 0; i <= n; i++) {\n            for (int j = 0; j\
    \ <= m; j++) {\n                par[i][j] = {i, j};\n            }\n        }\n\
    \    }\n\n    pii find(pii v) {\n        if (v == par[v.fi][v.se]) {\n       \
    \     return v;\n        }\n        return par[v.fi][v.se] = find(par[v.fi][v.se]);\n\
    \    }\n\n    void merge(pii a, pii b) {\n        a = find(a);\n        b = find(b);\n\
    \        if (a == b) return;\n        if (sz[a.fi][a.se] < sz[b.fi][b.se]) {\n\
    \            swap(a, b);\n        }\n        par[b.fi][b.se] = a;\n        sz[a.fi][a.se]\
    \ += sz[b.fi][b.se];\n    }\n\n    bool same_component(pii u, pii v) {\n     \
    \   return find(u) == find(v);\n    }\n\n    int component_size(pii u) {\n   \
    \     u = find(u);\n        return sz[u.fi][u.se];\n    }\n\n    int max_component()\
    \ {\n        int res = 0;\n        for (int i = 0; i < n; i++) {\n           \
    \ for (int j = 0; j < m; j++) {\n                res = max(res, sz[i][j]);\n \
    \           }\n        }\n        return res;\n    }\n\n    bool isValid(int n,\
    \ int m, pii u) {\n        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se <\
    \ m;\n    }\n\n    /*----------- Paint cell and check maximum component ---------*/\n\
    \    int Try_all_cell (vector<vector<T>> &a) {\n        int dx[4] = {-1, 0, 0,\
    \ 1};\n        int dy[4] = {0, -1, 1, 0};\n        int ans = max_component();\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                if (a[i][j]) continue;\n                int t = 1;\n    \
    \            set<pii> s;\n                for (int k = 0; k < 4; k++) {\n    \
    \                pii u = {i + dx[k], j + dy[k]};\n                    if (isValid(n,\
    \ m, u) && a[u.fi][u.se]) {\n                        pii v = find(u);\n      \
    \                  if (s.count(v)) continue;\n                        t += sz[v.fi][v.se];\n\
    \                        s.insert(v);\n                    }\n               \
    \ }\n                ans = max(ans, t);\n            }\n        }\n        return\
    \ ans;\n    }\n    /*------------------------------------------------------------*/\n\
    \n    /*-------------------- Paint all row or col ------------------*/\n    int\
    \ Try_Row(int k, vector<vector<T>> &a) {\n        int dx[2] = {-1, 1};\n     \
    \   int dy[2] = {0, 0};\n        int res = 0;\n        set<pii> s;\n        for\
    \ (int i = 0; i < m; i++) {\n            if (a[k][i] == '.') res++;\n        \
    \    if (a[k][i] == '#') {\n                pii x = find({k, i});\n          \
    \      if (s.find(x) == s.end()) {\n                    res += sz[x.fi][x.se];\n\
    \                    s.insert({x.fi, x.se});\n                }\n            }\
    \ \n            for (int j = 0; j < 2; j++) {\n                pii u = {k + dx[j],\
    \ i + dy[j]};\n                if (isValid(n, m, u) && a[u.fi][u.se] == '#') {\n\
    \                    pii v = find(u);\n                    if (s.find(v) == s.end())\
    \ {\n                        s.insert(v);\n                        res += sz[v.fi][v.se];\n\
    \                    }   \n                }\n            }\n        }\n     \
    \   return res;\n    }\n\n    int Try_Col(int k, vector<vector<T>> &a) {\n   \
    \     int dx[2] = {0, 0};\n        int dy[2] = {-1, 1};\n        int res = 0;\n\
    \        set<pii> s;\n        for (int i = 0; i < n; i++) {\n            if (a[i][k]\
    \ == '.') res++;\n            if (a[i][k] == '#') {\n                pii x = find({i,\
    \ k});\n                if (s.find(x) == s.end()) {\n                    res +=\
    \ sz[x.fi][x.se];\n                    s.insert({x.fi, x.se});\n             \
    \   }\n            } \n            for (int j = 0; j < 2; j++) {\n           \
    \     pii u = {i+dx[j], k+dy[j]};\n                if (isValid(n, m, u) && a[u.fi][u.se]\
    \ == '#') {\n                    pii v = find(u);\n                    if (s.find(v)\
    \ == s.end()) {\n                        s.insert(v);\n                      \
    \  res += sz[v.fi][v.se];\n                    }   \n                }\n     \
    \       }\n        }\n        return res;\n    }\n    /*------------------------------------------------------------*/\n\
    };\n"
  code: "#include \"../../template.h\"\n\ntemplate <typename T>\nstruct Dsu_2D {\n\
    \    int n, m;\n    vector<vector<pii>> par;\n    vector<vector<int>> sz;\n\n\
    \    Dsu_2D() {}\n    Dsu_2D(int _n, int _m): n(_n), m(_m) {\n        par.resize(n+1,\
    \ vector<pii>(m+1));\n        sz.resize(n+1, vector<int>(m+1, 1));\n        for\
    \ (int i = 0; i <= n; i++) {\n            for (int j = 0; j <= m; j++) {\n   \
    \             par[i][j] = {i, j};\n            }\n        }\n    }\n\n    pii\
    \ find(pii v) {\n        if (v == par[v.fi][v.se]) {\n            return v;\n\
    \        }\n        return par[v.fi][v.se] = find(par[v.fi][v.se]);\n    }\n\n\
    \    void merge(pii a, pii b) {\n        a = find(a);\n        b = find(b);\n\
    \        if (a == b) return;\n        if (sz[a.fi][a.se] < sz[b.fi][b.se]) {\n\
    \            swap(a, b);\n        }\n        par[b.fi][b.se] = a;\n        sz[a.fi][a.se]\
    \ += sz[b.fi][b.se];\n    }\n\n    bool same_component(pii u, pii v) {\n     \
    \   return find(u) == find(v);\n    }\n\n    int component_size(pii u) {\n   \
    \     u = find(u);\n        return sz[u.fi][u.se];\n    }\n\n    int max_component()\
    \ {\n        int res = 0;\n        for (int i = 0; i < n; i++) {\n           \
    \ for (int j = 0; j < m; j++) {\n                res = max(res, sz[i][j]);\n \
    \           }\n        }\n        return res;\n    }\n\n    bool isValid(int n,\
    \ int m, pii u) {\n        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se <\
    \ m;\n    }\n\n    /*----------- Paint cell and check maximum component ---------*/\n\
    \    int Try_all_cell (vector<vector<T>> &a) {\n        int dx[4] = {-1, 0, 0,\
    \ 1};\n        int dy[4] = {0, -1, 1, 0};\n        int ans = max_component();\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                if (a[i][j]) continue;\n                int t = 1;\n    \
    \            set<pii> s;\n                for (int k = 0; k < 4; k++) {\n    \
    \                pii u = {i + dx[k], j + dy[k]};\n                    if (isValid(n,\
    \ m, u) && a[u.fi][u.se]) {\n                        pii v = find(u);\n      \
    \                  if (s.count(v)) continue;\n                        t += sz[v.fi][v.se];\n\
    \                        s.insert(v);\n                    }\n               \
    \ }\n                ans = max(ans, t);\n            }\n        }\n        return\
    \ ans;\n    }\n    /*------------------------------------------------------------*/\n\
    \n    /*-------------------- Paint all row or col ------------------*/\n    int\
    \ Try_Row(int k, vector<vector<T>> &a) {\n        int dx[2] = {-1, 1};\n     \
    \   int dy[2] = {0, 0};\n        int res = 0;\n        set<pii> s;\n        for\
    \ (int i = 0; i < m; i++) {\n            if (a[k][i] == '.') res++;\n        \
    \    if (a[k][i] == '#') {\n                pii x = find({k, i});\n          \
    \      if (s.find(x) == s.end()) {\n                    res += sz[x.fi][x.se];\n\
    \                    s.insert({x.fi, x.se});\n                }\n            }\
    \ \n            for (int j = 0; j < 2; j++) {\n                pii u = {k + dx[j],\
    \ i + dy[j]};\n                if (isValid(n, m, u) && a[u.fi][u.se] == '#') {\n\
    \                    pii v = find(u);\n                    if (s.find(v) == s.end())\
    \ {\n                        s.insert(v);\n                        res += sz[v.fi][v.se];\n\
    \                    }   \n                }\n            }\n        }\n     \
    \   return res;\n    }\n\n    int Try_Col(int k, vector<vector<T>> &a) {\n   \
    \     int dx[2] = {0, 0};\n        int dy[2] = {-1, 1};\n        int res = 0;\n\
    \        set<pii> s;\n        for (int i = 0; i < n; i++) {\n            if (a[i][k]\
    \ == '.') res++;\n            if (a[i][k] == '#') {\n                pii x = find({i,\
    \ k});\n                if (s.find(x) == s.end()) {\n                    res +=\
    \ sz[x.fi][x.se];\n                    s.insert({x.fi, x.se});\n             \
    \   }\n            } \n            for (int j = 0; j < 2; j++) {\n           \
    \     pii u = {i+dx[j], k+dy[j]};\n                if (isValid(n, m, u) && a[u.fi][u.se]\
    \ == '#') {\n                    pii v = find(u);\n                    if (s.find(v)\
    \ == s.end()) {\n                        s.insert(v);\n                      \
    \  res += sz[v.fi][v.se];\n                    }   \n                }\n     \
    \       }\n        }\n        return res;\n    }\n    /*------------------------------------------------------------*/\n\
    };"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/DSU/Dsu_2D.h
  requiredBy:
  - DataStructure/Aizu/test_dsu_2d.cpp
  - DataStructure/Aizu/test_dsu_2d_2.cpp
  timestamp: '2025-05-31 00:13:26+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/DSU/Dsu_2D.h
layout: document
redirect_from:
- /library/DataStructure/DSU/Dsu_2D.h
- /library/DataStructure/DSU/Dsu_2D.h.html
title: DataStructure/DSU/Dsu_2D.h
---
