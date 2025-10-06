---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: String/Yosupo/Z_Algorithm.test.cpp
    title: String/Yosupo/Z_Algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ 0;\n}\n#line 2 \"String/Z_Function.h\"\n\nvector<int> Z_function(const string\
    \ &s) {\n    int n = s.size();\n    vector<int> z(n);\n    z[0] = (int)s.size();\n\
    \    int l = 0, r = 0;\n    for (int i = 1; i < n; i++) {\n        if (i <= r)\
    \ {\n            z[i] = min(r-i+1, z[i-l]);\n        }\n        while (i + z[i]\
    \ < n && s[z[i]] == s[i + z[i]]) {\n            z[i]++;\n        }\n        if\
    \ (i + z[i] - 1 > r) {\n            l = i;\n            r = i + z[i] - 1;\n  \
    \      }\n    }\n    return z;\n}\n"
  code: "#include \"../template.h\"\n\nvector<int> Z_function(const string &s) {\n\
    \    int n = s.size();\n    vector<int> z(n);\n    z[0] = (int)s.size();\n   \
    \ int l = 0, r = 0;\n    for (int i = 1; i < n; i++) {\n        if (i <= r) {\n\
    \            z[i] = min(r-i+1, z[i-l]);\n        }\n        while (i + z[i] <\
    \ n && s[z[i]] == s[i + z[i]]) {\n            z[i]++;\n        }\n        if (i\
    \ + z[i] - 1 > r) {\n            l = i;\n            r = i + z[i] - 1;\n     \
    \   }\n    }\n    return z;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/Z_Function.h
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - String/Yosupo/Z_Algorithm.test.cpp
documentation_of: String/Z_Function.h
layout: document
redirect_from:
- /library/String/Z_Function.h
- /library/String/Z_Function.h.html
title: String/Z_Function.h
---
