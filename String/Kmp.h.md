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
    \ 0;\n}\n#line 2 \"String/Kmp.h\"\n\nvector<int> lps(const string &s) {\n\tint\
    \ n = s.size();\n\tvector<int> pi(n);\n\tfor (int i = 1; i < n; i++) {\n\t\tint\
    \ j = pi[i-1];\n\t\twhile (j > 0 && s[i] != s[j]) {\n\t\t\tj = pi[j - 1];\n\t\t\
    }\n\t\tif (s[i] == s[j]) j++;\n\t\tpi[i] = j;\n\t}\n\treturn pi;\n}\n\nvector<int>\
    \ __KMP(const string &s, const string &t) {\n\tint n = s.size(), m = t.size();\n\
    \tif (n == 0) return {};\n\tvector<int> pi = lps(s);\n\tint j = 0;\n\tvector<int>\
    \ ans(m);\n\tfor (int i = 0; i < m; i++) {\n\t\twhile (j > 0 && t[i] != s[j])\
    \ {\n\t\t\tj = pi[j - 1];\n\t\t}\n\t\tif (t[i] == s[j]) j++;\n\t\tans[i] = j;\n\
    \t\tif (j == n) {\n\t\t\tj = pi[j - 1];\n\t\t}\n\t}\n\treturn ans;\n}\n"
  code: "#include \"../template.h\"\n\nvector<int> lps(const string &s) {\n\tint n\
    \ = s.size();\n\tvector<int> pi(n);\n\tfor (int i = 1; i < n; i++) {\n\t\tint\
    \ j = pi[i-1];\n\t\twhile (j > 0 && s[i] != s[j]) {\n\t\t\tj = pi[j - 1];\n\t\t\
    }\n\t\tif (s[i] == s[j]) j++;\n\t\tpi[i] = j;\n\t}\n\treturn pi;\n}\n\nvector<int>\
    \ __KMP(const string &s, const string &t) {\n\tint n = s.size(), m = t.size();\n\
    \tif (n == 0) return {};\n\tvector<int> pi = lps(s);\n\tint j = 0;\n\tvector<int>\
    \ ans(m);\n\tfor (int i = 0; i < m; i++) {\n\t\twhile (j > 0 && t[i] != s[j])\
    \ {\n\t\t\tj = pi[j - 1];\n\t\t}\n\t\tif (t[i] == s[j]) j++;\n\t\tans[i] = j;\n\
    \t\tif (j == n) {\n\t\t\tj = pi[j - 1];\n\t\t}\n\t}\n\treturn ans;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/Kmp.h
  requiredBy: []
  timestamp: '2025-05-30 02:37:12+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Kmp.h
layout: document
redirect_from:
- /library/String/Kmp.h
- /library/String/Kmp.h.html
title: String/Kmp.h
---
