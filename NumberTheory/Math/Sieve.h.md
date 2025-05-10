---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Sieve.h\"\n\nvector<int> sieve(int n) {\n\
    \tvector<int> nt(n+1, 1);\n\tnt[0] = nt[1] = 0;\n\tfor (int i = 2; i * i <= n;\
    \ i++) {\n\t\tif (!nt[i]) continue;\n\t\tfor (int j = i * i; j <= n; j += i)\n\
    \t\t\tnt[j] = 0;\n\t}\n\treturn nt;\n}\n\nvoid segmentSieve(int l, int r){\n \
    \   bool prime[r-l+1];\n    memset(prime, true, sizeof(prime));\n    for(int i\
    \ = 2; i <= sqrt(r); i++){\n        for(int j = max(i*i, (l+i-1)/i*i); j <= r;\
    \ j+=i)\n            prime[j-l] = false;\n    }\n    if(l <= 1)\n        prime[1-l]\
    \ = false;\n    // for(int i = l; i <= r; i++)\n    //     if(prime[i-l])\n  \
    \  //         cout << i << '\\n';\n    // cout << '\\n';\n}\n"
  code: "#include \"../../template.h\"\n\nvector<int> sieve(int n) {\n\tvector<int>\
    \ nt(n+1, 1);\n\tnt[0] = nt[1] = 0;\n\tfor (int i = 2; i * i <= n; i++) {\n\t\t\
    if (!nt[i]) continue;\n\t\tfor (int j = i * i; j <= n; j += i)\n\t\t\tnt[j] =\
    \ 0;\n\t}\n\treturn nt;\n}\n\nvoid segmentSieve(int l, int r){\n    bool prime[r-l+1];\n\
    \    memset(prime, true, sizeof(prime));\n    for(int i = 2; i <= sqrt(r); i++){\n\
    \        for(int j = max(i*i, (l+i-1)/i*i); j <= r; j+=i)\n            prime[j-l]\
    \ = false;\n    }\n    if(l <= 1)\n        prime[1-l] = false;\n    // for(int\
    \ i = l; i <= r; i++)\n    //     if(prime[i-l])\n    //         cout << i <<\
    \ '\\n';\n    // cout << '\\n';\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Sieve.h
  requiredBy: []
  timestamp: '2025-05-10 21:29:43+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/Math/Sieve.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Sieve.h
- /library/NumberTheory/Math/Sieve.h.html
title: NumberTheory/Math/Sieve.h
---
