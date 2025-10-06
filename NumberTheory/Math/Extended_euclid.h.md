---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp
    title: NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
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
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Extended_euclid.h\"\n\n\nint extended1(int\
    \ a, int b, int &x, int &y) {\n    if (b == 0) {\n        x = 1, y = 0;\n    \
    \    return a;\n    }\n    int x1, y1;\n    int d = extended1(b, a%b, x1, y1);\n\
    \    x = y1;\n    y = x1-y1*(a/b);\n    return d;\n}\n\n// Iterative version\n\
    int extended2(int a, int b, int &x, int &y) {\n    x = 1, y = 0;\n    int x1 =\
    \ 0, y1 = 1;\n    int a1 = a, b1 = b;\n    while (b1) {\n        int q = a1 /\
    \ b1;\n        tie(x, x1) = make_tuple(x1, x - q * x1);\n        tie(y, y1) =\
    \ make_tuple(y1, y - q * y1);\n        tie(a1, b1) = make_tuple(b1, a1 - q * b1);\n\
    \    }\n    return a1;\n}\n"
  code: "#include \"../../template.h\"\n\n\nint extended1(int a, int b, int &x, int\
    \ &y) {\n    if (b == 0) {\n        x = 1, y = 0;\n        return a;\n    }\n\
    \    int x1, y1;\n    int d = extended1(b, a%b, x1, y1);\n    x = y1;\n    y =\
    \ x1-y1*(a/b);\n    return d;\n}\n\n// Iterative version\nint extended2(int a,\
    \ int b, int &x, int &y) {\n    x = 1, y = 0;\n    int x1 = 0, y1 = 1;\n    int\
    \ a1 = a, b1 = b;\n    while (b1) {\n        int q = a1 / b1;\n        tie(x,\
    \ x1) = make_tuple(x1, x - q * x1);\n        tie(y, y1) = make_tuple(y1, y - q\
    \ * y1);\n        tie(a1, b1) = make_tuple(b1, a1 - q * b1);\n    }\n    return\
    \ a1;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Extended_euclid.h
  requiredBy: []
  timestamp: '2025-06-08 06:31:53+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp
documentation_of: NumberTheory/Math/Extended_euclid.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Extended_euclid.h
- /library/NumberTheory/Math/Extended_euclid.h.html
title: NumberTheory/Math/Extended_euclid.h
---
