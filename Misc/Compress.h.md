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
    \ 0;\n}\n#line 2 \"Misc/Compress.h\"\n\ntemplate <typename T>\nstruct Compress\
    \ {\n    int cnt = 1;\n    map<T, int> compressed;\n    vector<T> decompress;\n\
    \n    Compress(const vector<T> &a) {\n        decompress.push_back(T(0));\n  \
    \      vector<T> b = a;\n        sort(all(b));\n        unique(b);\n        for\
    \ (T x : b) {\n            compressed[x] = cnt++;\n            decompress.push_back(x);\n\
    \        }\n    }\n};\n"
  code: "#include \"../template.h\"\n\ntemplate <typename T>\nstruct Compress {\n\
    \    int cnt = 1;\n    map<T, int> compressed;\n    vector<T> decompress;\n\n\
    \    Compress(const vector<T> &a) {\n        decompress.push_back(T(0));\n   \
    \     vector<T> b = a;\n        sort(all(b));\n        unique(b);\n        for\
    \ (T x : b) {\n            compressed[x] = cnt++;\n            decompress.push_back(x);\n\
    \        }\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/Compress.h
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Compress.h
layout: document
redirect_from:
- /library/Misc/Compress.h
- /library/Misc/Compress.h.html
title: Misc/Compress.h
---
