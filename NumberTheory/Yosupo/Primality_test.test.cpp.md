---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
  - icon: ':x:'
    path: NumberTheory/Math/MillerRabin.h
    title: NumberTheory/Math/MillerRabin.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"NumberTheory/Yosupo/Primality_test.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/primality_test\"\n\n#line 2 \"template.h\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n\
    #define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64\
    \ ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n#define pii\
    \ pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define se second\n\
    \nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"NumberTheory/Math/Binary_exponentiation.h\"\
    \n\nusing u128 = __uint128_t;\nusing i128 = __int128;\n\nll binMul(ll a, ll b,\
    \ ll M) {\n    a = a % M;\n    ll res = 0;\n    while (b) {\n        if (b & 1)\
    \ res = (res + a) % M;\n        a = a * 2 % M;\n        b /= 2;\n    }\n    return\
    \ res;\n}\n\nll binPow(ll a, ll b, ll M) {\n    a %= M;\n    ll res = 1;\n   \
    \ while (b) {\n        if (b & 1) res = (i128)res * a % M;\n        a = (i128)a\
    \ * a % M;\n        b /= 2;\n    }\n    return res;\n}\n#line 3 \"NumberTheory/Math/MillerRabin.h\"\
    \n\nbool test(ll a, ll n, ll k, ll m) {\n    ll mod = binPow(a, m, n);\n    if\
    \ (mod == 1 || mod == n - 1) return true;\n    for (int l = 1; l < k; l++) {\n\
    \        mod = (u128)mod * mod % n;\n        if (mod == n - 1) return true;\n\
    \    }\n    return false;\n}\n\n// Miller rabin\nbool MillerRabin0(ll n) {\n \
    \   if (n == 2) return true;\n    if (n < 2 || n % 2 == 0) return false;\n   \
    \ ll k = 0, m = n - 1;\n    while(m % 2 == 0) {\n        m /= 2;\n        k++;\n\
    \    }\n    for (int i = 0; i < 5; i++) {\n        ll a = rand() % (n - 3) + 2;\n\
    \        if (!test(a, n, k, m)) return false;\n    }\n    return true;\n}\n\n\
    // Miller Rabin deterministic version\nbool MillerRabin(ll n) {\n    if (n <=\
    \ 1) return false;\n    ll k = 0, m = n-1;\n    while (m % 2 == 0) {\n       \
    \ m /= 2;\n        k++;\n    }\n    for (int a : {2, 3, 5, 7, 11, 13, 17, 19,\
    \ 23, 29, 31, 37}) {\n        if (n == a) return true;\n        if (!test(a, n,\
    \ k, m)) return false;\n    }\n    return true;\n}\n#line 5 \"NumberTheory/Yosupo/Primality_test.test.cpp\"\
    \n\nvoid solve() {\n    int q; cin >> q;\n    while (q--) {\n        ll n; cin\
    \ >> n;\n        if (MillerRabin(n)) cout << \"Yes\\n\";\n        else cout <<\
    \ \"No\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ \"../../template.h\"\n#include \"../Math/MillerRabin.h\"\n\nvoid solve() {\n\
    \    int q; cin >> q;\n    while (q--) {\n        ll n; cin >> n;\n        if\
    \ (MillerRabin(n)) cout << \"Yes\\n\";\n        else cout << \"No\\n\";\n    }\n\
    }"
  dependsOn:
  - template.h
  - NumberTheory/Math/MillerRabin.h
  - NumberTheory/Math/Binary_exponentiation.h
  isVerificationFile: true
  path: NumberTheory/Yosupo/Primality_test.test.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: NumberTheory/Yosupo/Primality_test.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Yosupo/Primality_test.test.cpp
- /verify/NumberTheory/Yosupo/Primality_test.test.cpp.html
title: NumberTheory/Yosupo/Primality_test.test.cpp
---
