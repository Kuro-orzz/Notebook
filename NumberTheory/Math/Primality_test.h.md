---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
  - icon: ':question:'
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
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Binary_exponentiation.h\"\n\nusing u128 =\
    \ __uint128_t;\n\nll binMul(ll a, ll b, ll M) {\n    a = a % M;\n    ll res =\
    \ 0;\n    while (b) {\n        if (b & 1) res = (res + a) % M;\n        a = a\
    \ * 2 % M;\n        b /= 2;\n    }\n    return res;\n}\n\nll binPow(ll a, ll b,\
    \ ll M) {\n    a %= M;\n    ll res = 1;\n    while (b) {\n        if (b & 1) res\
    \ = (u128)res * a % M;\n        a = (u128)a * a % M;\n        b /= 2;\n    }\n\
    \    return res;\n}\n#line 3 \"NumberTheory/Math/Primality_test.h\"\n\n// Fermat's\
    \ little theorem\nbool isPrime(ll n) {\n    if (n < 7) return n == 2 || n == 3\
    \ || n == 5;\n    for (int i = 0; i < 5; i++) {\n        ll a = rand() % (n-3)\
    \ + 2;\n        if (binPow(a, n-1, n) != 1) \n            return false;\n    }\n\
    \    return true;\n}\n"
  code: "#include \"../../template.h\"\n#include \"Binary_exponentiation.h\"\n\n//\
    \ Fermat's little theorem\nbool isPrime(ll n) {\n    if (n < 7) return n == 2\
    \ || n == 3 || n == 5;\n    for (int i = 0; i < 5; i++) {\n        ll a = rand()\
    \ % (n-3) + 2;\n        if (binPow(a, n-1, n) != 1) \n            return false;\n\
    \    }\n    return true;\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/Binary_exponentiation.h
  isVerificationFile: false
  path: NumberTheory/Math/Primality_test.h
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/Math/Primality_test.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Primality_test.h
- /library/NumberTheory/Math/Primality_test.h.html
title: NumberTheory/Math/Primality_test.h
---
