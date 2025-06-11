---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: String/KMP/test_kmp.cpp
    title: String/KMP/test_kmp.cpp
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
    \ 0;\n}\n#line 2 \"String/KMP/Kmp.h\"\n\nvector<int> lps(const string &s) {\n\
    \    int n = s.size();\n    vector<int> pi(n);\n    for (int i = 1; i < n; i++)\
    \ {\n        int j = pi[i-1];\n        while (j > 0 && s[i] != s[j]) {\n     \
    \       j = pi[j - 1];\n        }\n        if (s[i] == s[j]) j++;\n        pi[i]\
    \ = j;\n    }\n    return pi;\n}\n\nvector<int> __KMP(const string &s, const string\
    \ &t) {\n    int n = s.size(), m = t.size();\n    if (n == 0) return {};\n   \
    \ vector<int> pi = lps(s);\n    int j = 0;\n    vector<int> ans(m);\n    for (int\
    \ i = 0; i < m; i++) {\n        while (j > 0 && t[i] != s[j]) {\n            j\
    \ = pi[j - 1];\n        }\n        if (t[i] == s[j]) j++;\n        ans[i] = j;\n\
    \        if (j == n) {\n            j = pi[j - 1];\n        }\n    }\n    return\
    \ ans;\n}\n"
  code: "#include \"../../template.h\"\n\nvector<int> lps(const string &s) {\n   \
    \ int n = s.size();\n    vector<int> pi(n);\n    for (int i = 1; i < n; i++) {\n\
    \        int j = pi[i-1];\n        while (j > 0 && s[i] != s[j]) {\n         \
    \   j = pi[j - 1];\n        }\n        if (s[i] == s[j]) j++;\n        pi[i] =\
    \ j;\n    }\n    return pi;\n}\n\nvector<int> __KMP(const string &s, const string\
    \ &t) {\n    int n = s.size(), m = t.size();\n    if (n == 0) return {};\n   \
    \ vector<int> pi = lps(s);\n    int j = 0;\n    vector<int> ans(m);\n    for (int\
    \ i = 0; i < m; i++) {\n        while (j > 0 && t[i] != s[j]) {\n            j\
    \ = pi[j - 1];\n        }\n        if (t[i] == s[j]) j++;\n        ans[i] = j;\n\
    \        if (j == n) {\n            j = pi[j - 1];\n        }\n    }\n    return\
    \ ans;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/KMP/Kmp.h
  requiredBy:
  - String/KMP/test_kmp.cpp
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/KMP/Kmp.h
layout: document
redirect_from:
- /library/String/KMP/Kmp.h
- /library/String/KMP/Kmp.h.html
title: String/KMP/Kmp.h
---
