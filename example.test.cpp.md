---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"example.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define ll long long\n#define\
    \ MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define fi first\n#define se second\n\nstruct Dsu{\n\
    \    vector<int> par, sz;\n    Dsu(int n): par(n+1), sz(n+1, 1){\n        for(int\
    \ i = 0; i < n; i++)\n            par[i] = i;\n    }\n    int find(int v){\n \
    \       if(v == par[v]) return v;\n        return par[v] = find(par[v]);\n   \
    \ }\n    void merge(int a, int b){\n        a = find(a);\n        b = find(b);\n\
    \        if (a == b) return;\n        if(sz[a] < sz[b]) swap(a, b);\n        par[b]\
    \ = a;\n        sz[a] += sz[b];\n    }\n};\n\nvoid solve(){\n    int n, q; cin\
    \ >> n >> q;\n    Dsu g(n+1);\n    while (q--) {\n        int tv, u, v; cin >>\
    \ tv >> u >> v;\n        if (tv == 0) g.merge(u, v);\n        else if (g.find(u)\
    \ == g.find(v))\n            cout << \"1\\n\";\n        else cout << \"0\\n\"\
    ;\n    }\n}\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define ll long long\n#define MOD (ll)(1e9+7)\n#define\
    \ all(x) (x).begin(),(x).end()\n\n#define vi vector<int>\n#define pii pair<int,\
    \ int>\n#define fi first\n#define se second\n\nstruct Dsu{\n    vector<int> par,\
    \ sz;\n    Dsu(int n): par(n+1), sz(n+1, 1){\n        for(int i = 0; i < n; i++)\n\
    \            par[i] = i;\n    }\n    int find(int v){\n        if(v == par[v])\
    \ return v;\n        return par[v] = find(par[v]);\n    }\n    void merge(int\
    \ a, int b){\n        a = find(a);\n        b = find(b);\n        if (a == b)\
    \ return;\n        if(sz[a] < sz[b]) swap(a, b);\n        par[b] = a;\n      \
    \  sz[a] += sz[b];\n    }\n};\n\nvoid solve(){\n    int n, q; cin >> n >> q;\n\
    \    Dsu g(n+1);\n    while (q--) {\n        int tv, u, v; cin >> tv >> u >> v;\n\
    \        if (tv == 0) g.merge(u, v);\n        else if (g.find(u) == g.find(v))\n\
    \            cout << \"1\\n\";\n        else cout << \"0\\n\";\n    }\n}\n\nint\
    \ main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: example.test.cpp
  requiredBy: []
  timestamp: '2025-05-02 15:00:33+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: example.test.cpp
layout: document
redirect_from:
- /verify/example.test.cpp
- /verify/example.test.cpp.html
title: example.test.cpp
---
