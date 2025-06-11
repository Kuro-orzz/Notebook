---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: NumberTheory/Math/Factorization.h
    title: NumberTheory/Math/Factorization.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"NumberTheory/Math/test/aizu_ntl_1_a_prime_factor.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
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
    \ if (n > 1) factor.push_back(n);\n    return factor;\n}\n#line 5 \"NumberTheory/Math/test/aizu_ntl_1_a_prime_factor.test.cpp\"\
    \n\nvoid solve() {\n    int n; cin >> n;\n    vector<ll> v = primeFactor(n);\n\
    \    cout << n << \": \";\n    for (int i = 0; i < (int)v.size() - 1; i++) {\n\
    \        cout << v[i] << \" \";\n    }\n    cout << v.back() << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#include \"../../../template.h\"\n#include \"../Factorization.h\"\n\nvoid\
    \ solve() {\n    int n; cin >> n;\n    vector<ll> v = primeFactor(n);\n    cout\
    \ << n << \": \";\n    for (int i = 0; i < (int)v.size() - 1; i++) {\n       \
    \ cout << v[i] << \" \";\n    }\n    cout << v.back() << '\\n';\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/Factorization.h
  isVerificationFile: true
  path: NumberTheory/Math/test/aizu_ntl_1_a_prime_factor.test.cpp
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: NumberTheory/Math/test/aizu_ntl_1_a_prime_factor.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Math/test/aizu_ntl_1_a_prime_factor.test.cpp
- /verify/NumberTheory/Math/test/aizu_ntl_1_a_prime_factor.test.cpp.html
title: NumberTheory/Math/test/aizu_ntl_1_a_prime_factor.test.cpp
---
