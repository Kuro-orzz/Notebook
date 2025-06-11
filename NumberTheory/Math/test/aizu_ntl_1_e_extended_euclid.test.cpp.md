---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Extended_euclid.h
    title: NumberTheory/Math/Extended_euclid.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"NumberTheory/Math/test/aizu_ntl_1_e_extended_euclid.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
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
    \    }\n    return a1;\n}\n#line 5 \"NumberTheory/Math/test/aizu_ntl_1_e_extended_euclid.test.cpp\"\
    \n\nvoid solve() {\n    int a, b; cin >> a >> b;\n    int x, y;\n    int g = extended2(a,\
    \ b, x, y);\n    cout << x << \" \" << y << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include \"../../../template.h\"\n#include \"../Extended_euclid.h\"\n\nvoid\
    \ solve() {\n    int a, b; cin >> a >> b;\n    int x, y;\n    int g = extended2(a,\
    \ b, x, y);\n    cout << x << \" \" << y << '\\n';\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/Extended_euclid.h
  isVerificationFile: true
  path: NumberTheory/Math/test/aizu_ntl_1_e_extended_euclid.test.cpp
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Math/test/aizu_ntl_1_e_extended_euclid.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Math/test/aizu_ntl_1_e_extended_euclid.test.cpp
- /verify/NumberTheory/Math/test/aizu_ntl_1_e_extended_euclid.test.cpp.html
title: NumberTheory/Math/test/aizu_ntl_1_e_extended_euclid.test.cpp
---
