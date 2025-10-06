---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: NumberTheory/Aizu/aizu_ntl_1_a_prime_factor.test.cpp
    title: NumberTheory/Aizu/aizu_ntl_1_a_prime_factor.test.cpp
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
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Factorization.h\"\n\n\nvector<ll> primeFactor(ll\
    \ n) {\n    vector<ll> factor;\n    for (int i : {2, 3, 5}) {\n        while (n\
    \ % i == 0) {\n            n /= i;\n            factor.push_back(i);\n       \
    \ }\n    }\n    int inc[] = {4, 2, 4, 2, 4, 6, 2, 6};\n    int j = 0;\n    for\
    \ (ll i = 7; i * i <= n; i += inc[j%8], j++) {\n        while(n % i == 0) {\n\
    \            n /= i;\n            factor.push_back(i);\n        }\n    }\n   \
    \ if (n > 1) factor.push_back(n);\n    return factor;\n}\n"
  code: "#include \"../../template.h\"\n\n\nvector<ll> primeFactor(ll n) {\n    vector<ll>\
    \ factor;\n    for (int i : {2, 3, 5}) {\n        while (n % i == 0) {\n     \
    \       n /= i;\n            factor.push_back(i);\n        }\n    }\n    int inc[]\
    \ = {4, 2, 4, 2, 4, 6, 2, 6};\n    int j = 0;\n    for (ll i = 7; i * i <= n;\
    \ i += inc[j%8], j++) {\n        while(n % i == 0) {\n            n /= i;\n  \
    \          factor.push_back(i);\n        }\n    }\n    if (n > 1) factor.push_back(n);\n\
    \    return factor;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Factorization.h
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - NumberTheory/Aizu/aizu_ntl_1_a_prime_factor.test.cpp
documentation_of: NumberTheory/Math/Factorization.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Factorization.h
- /library/NumberTheory/Math/Factorization.h.html
title: NumberTheory/Math/Factorization.h
---
