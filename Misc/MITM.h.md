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
    \ 0;\n}\n#line 2 \"Misc/MITM.h\"\n\n\n\nvector<ll> L, R;\n \nvoid MITM(int i,\
    \ ll sum, int end) {\n    if (i >= end) R.push_back(sum);\n    else {\n      \
    \  MITM(i+1, sum, end);\n        MITM(i+1, sum + a[i], end);\n    }\n}\n\n// MITM(0,\
    \ 0, n/2);\n// L = R;\n// R.clear();\n// MITM(n/2, 0, n);\n"
  code: "#include \"../template.h\"\n\n\n\nvector<ll> L, R;\n \nvoid MITM(int i, ll\
    \ sum, int end) {\n    if (i >= end) R.push_back(sum);\n    else {\n        MITM(i+1,\
    \ sum, end);\n        MITM(i+1, sum + a[i], end);\n    }\n}\n\n// MITM(0, 0, n/2);\n\
    // L = R;\n// R.clear();\n// MITM(n/2, 0, n);"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/MITM.h
  requiredBy: []
  timestamp: '2025-10-06 23:30:53+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/MITM.h
layout: document
redirect_from:
- /library/Misc/MITM.h
- /library/Misc/MITM.h.html
title: Misc/MITM.h
---
