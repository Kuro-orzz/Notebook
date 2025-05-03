---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Static_range_sum.test.cpp
    title: DataStructure/Static_range_sum.test.cpp
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
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"DataStructure/Fenwick/Fenwick.h\"\
    \n\ntemplate <typename T>\nstruct Fenwick{\n    int n;\n    vector<T> fen;\n\n\
    \    Fenwick(int _n): n(_n), fen(_n+1) {}\n\n    void update(int pos, int val)\
    \ {\n        for (; pos <= n; pos += pos & -pos) {\n            fen[pos] += val;\n\
    \        }\n    }\n\n    T get(int pos) {\n        T ans = 0;\n        for (;\
    \ pos > 0; pos -= pos & -pos) {\n            ans += fen[pos];\n        }\n   \
    \     return ans;\n    }\n\n    T get(int l, int r) {\n        if (l == r) return\
    \ 0;\n        return get(r) - get(l);\n    }\n\n    void update_range(int l, int\
    \ r, T val){\n        update(l, val);\n        update(r+1, -val);\n    }\n\n \
    \   void reset() {\n        fill(all(fen), T(0));\n    }\n};\n"
  code: "#include \"../../template.h\"\n\ntemplate <typename T>\nstruct Fenwick{\n\
    \    int n;\n    vector<T> fen;\n\n    Fenwick(int _n): n(_n), fen(_n+1) {}\n\n\
    \    void update(int pos, int val) {\n        for (; pos <= n; pos += pos & -pos)\
    \ {\n            fen[pos] += val;\n        }\n    }\n\n    T get(int pos) {\n\
    \        T ans = 0;\n        for (; pos > 0; pos -= pos & -pos) {\n          \
    \  ans += fen[pos];\n        }\n        return ans;\n    }\n\n    T get(int l,\
    \ int r) {\n        if (l == r) return 0;\n        return get(r) - get(l);\n \
    \   }\n\n    void update_range(int l, int r, T val){\n        update(l, val);\n\
    \        update(r+1, -val);\n    }\n\n    void reset() {\n        fill(all(fen),\
    \ T(0));\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/Fenwick/Fenwick.h
  requiredBy: []
  timestamp: '2025-05-02 22:25:58+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/Static_range_sum.test.cpp
documentation_of: DataStructure/Fenwick/Fenwick.h
layout: document
redirect_from:
- /library/DataStructure/Fenwick/Fenwick.h
- /library/DataStructure/Fenwick/Fenwick.h.html
title: DataStructure/Fenwick/Fenwick.h
---
