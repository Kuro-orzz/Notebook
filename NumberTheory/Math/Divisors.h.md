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
    path: NumberTheory/Math/Sieve.h
    title: NumberTheory/Math/Sieve.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/gym/100753
    - https://usaco.guide/problems/cses-1082-sum-of-divisors/solution
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
    \ __uint128_t;\n\nll binMul(ll a, ll b, ll M) {\n\ta = a % M;\n\tll res = 0;\n\
    \twhile (b) {\n\t\tif (b & 1) res = (res + a) % M;\n\t\ta = a * 2 % M;\n\t\tb\
    \ /= 2;\n\t}\n\treturn res;\n}\n\nll binPow(ll a, ll b, ll M) {\n\ta %= M;\n\t\
    ll res = 1;\n\twhile (b) {\n\t\tif (b & 1) res = (u128)res * a % M;\n\t\ta = (u128)a\
    \ * a % M;\n\t\tb /= 2;\n\t}\n\treturn res;\n}\n#line 3 \"NumberTheory/Math/MillerRabin.h\"\
    \n\nbool test(ll a, ll n, ll k, ll m) {\n\tll mod = binPow(a, m, n);\n\tif (mod\
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
    \ false;\n\t}\n\treturn true;\n}\n#line 2 \"NumberTheory/Math/Sieve.h\"\n\nvector<int>\
    \ sieve(int n) {\n\tvector<int> nt(n+1, 1);\n\tnt[0] = nt[1] = 0;\n\tfor (int\
    \ i = 2; i * i <= n; i++) {\n\t\tif (!nt[i]) continue;\n\t\tfor (int j = i * i;\
    \ j <= n; j += i)\n\t\t\tnt[j] = 0;\n\t}\n\treturn nt;\n}\n\nvector<int> segmentSieve(int\
    \ l, int r){\n\tvector<int> prime(r-l+1, 1);\n\tfor(ll p = 2; p*p <= r; p++){\n\
    \t\tll lim = max(p*p, (l+p-1)/p*p);\n\t\tfor(ll j = lim; j <= r; j += p)\n\t\t\
    \tif (j-l >= 0) prime[j-l] = 0;\n\t}\n\tif (l == 0) prime[0] = 0;\n\tif (l ==\
    \ 0 && r > l) prime[1] = 0;\n\tif (l == 1) prime[1-l] = 0;\n\treturn prime;\n\
    }\n\nvector<int> listPrime(int l, int r) {\n\tvector<int> prime = segmentSieve(l,\
    \ r);\n\tvector<int> listPi;\n\tfor (int i = l; i <= r; i++) {\n\t\tif (prime[i-l])\
    \ listPi.push_back(i);\n\t}\n\treturn listPi;\n}\n#line 4 \"NumberTheory/Math/Divisors.h\"\
    \n\nusing u128 = __uint128_t;\n\n// sum of all divisor [1, n]\n// https://usaco.guide/problems/cses-1082-sum-of-divisors/solution\n\
    ll sum_of_divisor(ll n) {\n    ll res = 0, i = 1;\n    while (i <= n) {\n    \
    \    ll l = i;          \n        ll r = n / (n / i);\n        ll val = n / l;\n\
    \        ll csc = (u128)(r - l + 1) * (l + r) / 2 % MOD;\n        res = (res +\
    \ csc * val) % MOD;\n        i = r + 1;\n    }\n    return res;\n}\n\n// count\
    \ number of divisor up to n <= 1e18\n// AC: https://codeforces.com/gym/100753\
    \ (Probblem F)\nint count_divisor(ll n) {\n    if (n == 1) return 1;\n    vector<int>\
    \ prime = listPrime(1, 1e6+5);\n    int ans = 1;\n    for (int p : prime) {\n\
    \        if (p * p * p > n) break;\n        int cnt = 0;\n        while (n % p\
    \ == 0) {\n            n /= p;\n            cnt++;\n        }\n        ans *=\
    \ cnt + 1;\n    }\n    auto isSqrt = [&](ll n)->bool {\n        ll c = sqrt(n);\n\
    \        return c * c == n;\n    };\n    if (n == 1) return ans;\n    if (MillerRabin(n))\
    \ ans *= 2;\n    else if (isSqrt(n)) ans *= 3;\n    else ans *= 4;\n    return\
    \ ans;\n}\n"
  code: "#include \"../../template.h\"\n#include \"MillerRabin.h\"\n#include \"Sieve.h\"\
    \n\nusing u128 = __uint128_t;\n\n// sum of all divisor [1, n]\n// https://usaco.guide/problems/cses-1082-sum-of-divisors/solution\n\
    ll sum_of_divisor(ll n) {\n    ll res = 0, i = 1;\n    while (i <= n) {\n    \
    \    ll l = i;          \n        ll r = n / (n / i);\n        ll val = n / l;\n\
    \        ll csc = (u128)(r - l + 1) * (l + r) / 2 % MOD;\n        res = (res +\
    \ csc * val) % MOD;\n        i = r + 1;\n    }\n    return res;\n}\n\n// count\
    \ number of divisor up to n <= 1e18\n// AC: https://codeforces.com/gym/100753\
    \ (Probblem F)\nint count_divisor(ll n) {\n    if (n == 1) return 1;\n    vector<int>\
    \ prime = listPrime(1, 1e6+5);\n    int ans = 1;\n    for (int p : prime) {\n\
    \        if (p * p * p > n) break;\n        int cnt = 0;\n        while (n % p\
    \ == 0) {\n            n /= p;\n            cnt++;\n        }\n        ans *=\
    \ cnt + 1;\n    }\n    auto isSqrt = [&](ll n)->bool {\n        ll c = sqrt(n);\n\
    \        return c * c == n;\n    };\n    if (n == 1) return ans;\n    if (MillerRabin(n))\
    \ ans *= 2;\n    else if (isSqrt(n)) ans *= 3;\n    else ans *= 4;\n    return\
    \ ans;\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/MillerRabin.h
  - NumberTheory/Math/Binary_exponentiation.h
  - NumberTheory/Math/Sieve.h
  isVerificationFile: false
  path: NumberTheory/Math/Divisors.h
  requiredBy: []
  timestamp: '2025-06-10 22:27:06+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/Math/Divisors.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Divisors.h
- /library/NumberTheory/Math/Divisors.h.html
title: NumberTheory/Math/Divisors.h
---
