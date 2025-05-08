---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Primality_test.test.cpp
    title: NumberTheory/Primality_test.test.cpp
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
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Prime.h\"\n\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\nusing u128 = __uint128_t;\n\nbool primeCheck(ll n) {\n\tif\
    \ (n == 2 || n == 3) return true;\n\tif (n <= 1 || n % 2 == 0 || n % 3 == 0) return\
    \ false;\n\tfor (ll i = 5; i * i <= n; i += 6)\n\t\tif (n % i == 0 || n % (i+2)\
    \ == 0)\n\t\t\treturn false;\n\treturn true;\n}\n\n// list of divisors\nvector<int>\
    \ primeFactorization(ll n) {\n\tvector<int> res;\n\tfor (ll i = 2; i * i <= n;\
    \ i++) {\n\t\twhile(n % i == 0) {\n\t\t\tn /= i;\n\t\t\tres.push_back(i);\n\t\t\
    }\n\t}\n\tif (n > 1) res.push_back(n);\n\treturn res;\n}\n\nll binMul(ll a, ll\
    \ b, ll M) {\n\ta = a % M;\n\tll res = 0;\n\twhile (b) {\n\t\tif (b & 1) res =\
    \ (res + a) % M;\n\t\ta = a * 2 % M;\n\t\tb /= 2;\n\t}\n\treturn res;\n}\n\nll\
    \ binPow(ll a, ll b, ll M) {\n\ta %= M;\n\tll res = 1;\n\twhile (b) {\n\t\tif\
    \ (b & 1) res = (u128)res * a % M;\n\t\ta = (u128)a * a % M;\n\t\tb /= 2;\n\t\
    }\n\treturn res;\n}\n\n// Fermat's little theorem\nbool isPrime(ll n) {\n\tif\
    \ (n < 7) return n == 2 || n == 3 || n == 5;\n\tfor (int i = 0; i < 5; i++) {\n\
    \t\tll a = rand() % (n-3) + 2;\n\t\tif (binPow(a, n-1, n) != 1) \n\t\t\treturn\
    \ false;\n\t}\n\treturn true;\n}\n\nbool test(ll a, ll n, ll k, ll m) {\n\tll\
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
    \t\tif (!test(a, n, k, m)) return false;\n\t}\n\treturn true;\n}\n\nvector<int>\
    \ sieve(int n) {\n\tvector<int> nt(n+1, 1);\n\tnt[0] = nt[1] = 0;\n\tfor (int\
    \ i = 2; i * i <= n; i++) {\n\t\tif (!nt[i]) continue;\n\t\tfor (int j = i * i;\
    \ j <= n; j += i)\n\t\t\tnt[j] = 0;\n\t}\n\treturn nt;\n}\n"
  code: "#include \"../../template.h\"\n\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    using u128 = __uint128_t;\n\nbool primeCheck(ll n) {\n\tif (n == 2 || n == 3)\
    \ return true;\n\tif (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;\n\tfor\
    \ (ll i = 5; i * i <= n; i += 6)\n\t\tif (n % i == 0 || n % (i+2) == 0)\n\t\t\t\
    return false;\n\treturn true;\n}\n\n// list of divisors\nvector<int> primeFactorization(ll\
    \ n) {\n\tvector<int> res;\n\tfor (ll i = 2; i * i <= n; i++) {\n\t\twhile(n %\
    \ i == 0) {\n\t\t\tn /= i;\n\t\t\tres.push_back(i);\n\t\t}\n\t}\n\tif (n > 1)\
    \ res.push_back(n);\n\treturn res;\n}\n\nll binMul(ll a, ll b, ll M) {\n\ta =\
    \ a % M;\n\tll res = 0;\n\twhile (b) {\n\t\tif (b & 1) res = (res + a) % M;\n\t\
    \ta = a * 2 % M;\n\t\tb /= 2;\n\t}\n\treturn res;\n}\n\nll binPow(ll a, ll b,\
    \ ll M) {\n\ta %= M;\n\tll res = 1;\n\twhile (b) {\n\t\tif (b & 1) res = (u128)res\
    \ * a % M;\n\t\ta = (u128)a * a % M;\n\t\tb /= 2;\n\t}\n\treturn res;\n}\n\n//\
    \ Fermat's little theorem\nbool isPrime(ll n) {\n\tif (n < 7) return n == 2 ||\
    \ n == 3 || n == 5;\n\tfor (int i = 0; i < 5; i++) {\n\t\tll a = rand() % (n-3)\
    \ + 2;\n\t\tif (binPow(a, n-1, n) != 1) \n\t\t\treturn false;\n\t}\n\treturn true;\n\
    }\n\nbool test(ll a, ll n, ll k, ll m) {\n\tll mod = binPow(a, m, n);\n\tif (mod\
    \ == 1 || mod == n - 1) return true;\n\tfor (int l = 1; l < k; l++) {\n\t\tmod\
    \ = (u128)mod * mod % n;\n\t\tif (mod == n - 1) return true;\n\t}\n\treturn false;\n\
    }\n\n// Miller rabin\nbool MillerRabin0(ll n) {\n\tif (n == 2) return true;\n\t\
    if (n < 2 || n % 2 == 0) return false;\n\tll k = 0, m = n - 1;\n\twhile(m % 2\
    \ == 0) {\n\t\tm /= 2;\n\t\tk++;\n\t}\n\tfor (int i = 0; i < 5; i++) {\n\t\tll\
    \ a = rand() % (n - 3) + 2;\n\t\tif (!test(a, n, k, m)) return false;\n\t}\n\t\
    return true;\n}\n\n// Miller Rabin deterministic version\nbool MillerRabin(ll\
    \ n) {\n\tif (n <= 1) return false;\n\tll k = 0, m = n-1;\n\twhile (m % 2 == 0)\
    \ {\n\t\tm /= 2;\n\t\tk++;\n\t}\n\tfor (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23,\
    \ 29, 31, 37}) {\n\t\tif (n == a) return true;\n\t\tif (!test(a, n, k, m)) return\
    \ false;\n\t}\n\treturn true;\n}\n\nvector<int> sieve(int n) {\n\tvector<int>\
    \ nt(n+1, 1);\n\tnt[0] = nt[1] = 0;\n\tfor (int i = 2; i * i <= n; i++) {\n\t\t\
    if (!nt[i]) continue;\n\t\tfor (int j = i * i; j <= n; j += i)\n\t\t\tnt[j] =\
    \ 0;\n\t}\n\treturn nt;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Prime.h
  requiredBy: []
  timestamp: '2025-05-08 23:54:53+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Primality_test.test.cpp
documentation_of: NumberTheory/Math/Prime.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Prime.h
- /library/NumberTheory/Math/Prime.h.html
title: NumberTheory/Math/Prime.h
---
