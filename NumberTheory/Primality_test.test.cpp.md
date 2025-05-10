---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/MillerRabin.h
    title: NumberTheory/Math/MillerRabin.h
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
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"NumberTheory/Primality_test.test.cpp\"\n#define PROBLEM\
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
    \n\nusing u128 = __uint128_t;\n\nll binMul(ll a, ll b, ll M) {\n\ta = a % M;\n\
    \tll res = 0;\n\twhile (b) {\n\t\tif (b & 1) res = (res + a) % M;\n\t\ta = a *\
    \ 2 % M;\n\t\tb /= 2;\n\t}\n\treturn res;\n}\n\nll binPow(ll a, ll b, ll M) {\n\
    \ta %= M;\n\tll res = 1;\n\twhile (b) {\n\t\tif (b & 1) res = (u128)res * a %\
    \ M;\n\t\ta = (u128)a * a % M;\n\t\tb /= 2;\n\t}\n\treturn res;\n}\n#line 3 \"\
    NumberTheory/Math/MillerRabin.h\"\n\nbool test(ll a, ll n, ll k, ll m) {\n\tll\
    \ mod = binPow(a, m, n);\n\tif (mod == 1 || mod == n - 1) return true;\n\tfor\
    \ (int l = 1; l < k; l++) {\n\t\tmod = (u128)mod * mod % n;\n\t\tif (mod == n\
    \ - 1) return true;\n\t}\n\treturn false;\n}\n\n// Miller rabin\nbool MillerRabin0(ll\
    \ n) {\n\tif (n == 2) return true;\n\tif (n < 2 || n % 2 == 0) return false;\n\
    \tll k = 0, m = n - 1;\n\twhile(m % 2 == 0) {\n\t\tm /= 2;\n\t\tk++;\n\t}\n\t\
    for (int i = 0; i < 5; i++) {\n\t\tll a = rand() % (n - 3) + 2;\n\t\tif (!test(a,\
    \ n, k, m)) return false;\n\t}\n\treturn true;\n}\n\n// Miller Rabin deterministic\
    \ version\nbool MillerRabin(ll n) {\n\tif (n <= 1) return false;\n\tll k = 0,\
    \ m = n-1;\n\twhile (m % 2 == 0) {\n\t\tm /= 2;\n\t\tk++;\n\t}\n\tfor (int a :\
    \ {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n\t\tif (n == a) return true;\n\
    \t\tif (!test(a, n, k, m)) return false;\n\t}\n\treturn true;\n}\n#line 5 \"NumberTheory/Primality_test.test.cpp\"\
    \n\nvoid solve() {\n\tint q; cin >> q;\n\twhile (q--) {\n\t\tll n; cin >> n;\n\
    \t\tif (MillerRabin(n)) cout << \"Yes\\n\";\n\t\telse cout << \"No\\n\";\n\t}\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ \"../template.h\"\n#include \"Math/MillerRabin.h\"\n\nvoid solve() {\n\tint\
    \ q; cin >> q;\n\twhile (q--) {\n\t\tll n; cin >> n;\n\t\tif (MillerRabin(n))\
    \ cout << \"Yes\\n\";\n\t\telse cout << \"No\\n\";\n\t}\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/MillerRabin.h
  - NumberTheory/Math/Binary_exponentiation.h
  isVerificationFile: true
  path: NumberTheory/Primality_test.test.cpp
  requiredBy: []
  timestamp: '2025-05-10 21:29:43+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Primality_test.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Primality_test.test.cpp
- /verify/NumberTheory/Primality_test.test.cpp.html
title: NumberTheory/Primality_test.test.cpp
---
