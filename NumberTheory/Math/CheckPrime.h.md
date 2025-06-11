---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Counting_primes.test.cpp
    title: NumberTheory/Counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Enumerate_primes.test.cpp
    title: NumberTheory/Enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/91632
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"NumberTheory/Math/CheckPrime.h\"\n\n\nbool BruteForce(ll n)\
    \ {\n    if (n == 2 || n == 3) return true;\n    if (n <= 1 || n % 2 == 0 || n\
    \ % 3 == 0) return false;\n    for (ll i = 5; i * i <= n; i += 6)\n        if\
    \ (n % i == 0 || n % (i+2) == 0)\n            return false;\n    return true;\n\
    }\n\n// https://codeforces.com/blog/entry/91632\nll Meissel(ll n) {\n    vector<ll>\
    \ v;\n    for (ll i = 1; i*i <= n; i++) {\n        v.push_back(i);\n        v.push_back(n\
    \ / i);\n    }\n    sort(all(v));\n    unique(v);\n    ll sq = sqrt(n);\n    auto\
    \ geti = [&](ll x) {\n        if (x <= sq) return x-1;\n        return (int)v.size()\
    \ - n / x;\n    };\n    vector<ll> dp = v;\n    ll a = 0;\n    for (ll p = 2;\
    \ p*p <= n; p++) {\n        if (dp[geti(p)] == dp[geti(p-1)]) continue;\n    \
    \    a++;\n        for (int i = (int)v.size()-1; i >= 0; i--) {\n            if\
    \ (v[i] < p * p) break;\n            dp[i] -= dp[geti(v[i] / p)] - a;\n      \
    \  }\n    }\n    return dp[geti(n)] - 1;\n}\n"
  code: "#include \"../../template.h\"\n\n\nbool BruteForce(ll n) {\n    if (n ==\
    \ 2 || n == 3) return true;\n    if (n <= 1 || n % 2 == 0 || n % 3 == 0) return\
    \ false;\n    for (ll i = 5; i * i <= n; i += 6)\n        if (n % i == 0 || n\
    \ % (i+2) == 0)\n            return false;\n    return true;\n}\n\n// https://codeforces.com/blog/entry/91632\n\
    ll Meissel(ll n) {\n    vector<ll> v;\n    for (ll i = 1; i*i <= n; i++) {\n \
    \       v.push_back(i);\n        v.push_back(n / i);\n    }\n    sort(all(v));\n\
    \    unique(v);\n    ll sq = sqrt(n);\n    auto geti = [&](ll x) {\n        if\
    \ (x <= sq) return x-1;\n        return (int)v.size() - n / x;\n    };\n    vector<ll>\
    \ dp = v;\n    ll a = 0;\n    for (ll p = 2; p*p <= n; p++) {\n        if (dp[geti(p)]\
    \ == dp[geti(p-1)]) continue;\n        a++;\n        for (int i = (int)v.size()-1;\
    \ i >= 0; i--) {\n            if (v[i] < p * p) break;\n            dp[i] -= dp[geti(v[i]\
    \ / p)] - a;\n        }\n    }\n    return dp[geti(n)] - 1;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/CheckPrime.h
  requiredBy: []
  timestamp: '2025-05-25 00:26:18+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Counting_primes.test.cpp
  - NumberTheory/Enumerate_primes.test.cpp
documentation_of: NumberTheory/Math/CheckPrime.h
layout: document
redirect_from:
- /library/NumberTheory/Math/CheckPrime.h
- /library/NumberTheory/Math/CheckPrime.h.html
title: NumberTheory/Math/CheckPrime.h
---
