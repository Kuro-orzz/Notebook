---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cp-algorithms.com/algebra/factorial-divisors.html
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Misc/Formula.h\"\n\n\n// https://cp-algorithms.com/algebra/factorial-divisors.html\n\
    // Legendre's formula\n// only for case k is prime\n// n/k + n/(k^2) + n/(k^3)\
    \ + ...\n// return largest x that n! % k^x = 0\n// O(logk (n))\nint fact_pow(int\
    \ n, int k) {\n    int res = 0;\n    while (n) {\n        n /= k;\n        res\
    \ += n;\n    }\n    return res;\n}\n"
  code: "#include \"../template.h\"\n\n\n// https://cp-algorithms.com/algebra/factorial-divisors.html\n\
    // Legendre's formula\n// only for case k is prime\n// n/k + n/(k^2) + n/(k^3)\
    \ + ...\n// return largest x that n! % k^x = 0\n// O(logk (n))\nint fact_pow(int\
    \ n, int k) {\n    int res = 0;\n    while (n) {\n        n /= k;\n        res\
    \ += n;\n    }\n    return res;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/Formula.h
  requiredBy: []
  timestamp: '2025-07-06 11:39:53+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Formula.h
layout: document
redirect_from:
- /library/Misc/Formula.h
- /library/Misc/Formula.h.html
title: Misc/Formula.h
---
