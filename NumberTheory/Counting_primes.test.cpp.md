---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/CheckPrime.h
    title: NumberTheory/Math/CheckPrime.h
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
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"NumberTheory/Counting_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#line 2 \"template.h\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n\
    #define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64\
    \ ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n#define pii\
    \ pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define se second\n\
    \nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"NumberTheory/Math/CheckPrime.h\"\
    \n\n\nbool BruteForce(ll n) {\n\tif (n == 2 || n == 3) return true;\n\tif (n <=\
    \ 1 || n % 2 == 0 || n % 3 == 0) return false;\n\tfor (ll i = 5; i * i <= n; i\
    \ += 6)\n\t\tif (n % i == 0 || n % (i+2) == 0)\n\t\t\treturn false;\n\treturn\
    \ true;\n}\n\n// https://codeforces.com/blog/entry/91632\nll Meissel(ll n) {\n\
    \    vector<ll> v;\n    for (ll i = 1; i*i <= n; i++) {\n        v.push_back(i);\n\
    \        v.push_back(n / i);\n    }\n    sort(all(v));\n    unique(v);\n    ll\
    \ sq = sqrt(n);\n    auto geti = [&](ll x) {\n        if (x <= sq) return x-1;\n\
    \        return (int)v.size() - n / x;\n    };\n    vector<ll> dp = v;\n    ll\
    \ a = 0;\n    for (ll p = 2; p*p <= n; p++) {\n        if (dp[geti(p)] == dp[geti(p-1)])\
    \ continue;\n        a++;\n        for (int i = (int)v.size()-1; i >= 0; i--)\
    \ {\n            if (v[i] < p * p) break;\n            dp[i] -= dp[geti(v[i] /\
    \ p)] - a;\n        }\n    }\n    return dp[geti(n)] - 1;\n}\n#line 5 \"NumberTheory/Counting_primes.test.cpp\"\
    \n\nvoid solve() {\n\tll n; cin >> n;\n\tcout << Meissel(n);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include\
    \ \"../template.h\"\n#include \"Math/CheckPrime.h\"\n\nvoid solve() {\n\tll n;\
    \ cin >> n;\n\tcout << Meissel(n);\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/CheckPrime.h
  isVerificationFile: true
  path: NumberTheory/Counting_primes.test.cpp
  requiredBy: []
  timestamp: '2025-05-12 18:52:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Counting_primes.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Counting_primes.test.cpp
- /verify/NumberTheory/Counting_primes.test.cpp.html
title: NumberTheory/Counting_primes.test.cpp
---
