---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Z_Function.h
    title: String/Z_Function.h
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"String/Z_Algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"String/Z_Function.h\"\n\nvector<int> Z_function(const string\
    \ &s) {\n\tint n = s.size();\n\tvector<int> z(n);\n\tz[0] = (int)s.size();\n\t\
    int l = 0, r = 0;\n\tfor (int i = 1; i < n; i++) {\n\t\tif (i <= r) {\n\t\t\t\
    z[i] = min(r-i+1, z[i-l]);\n\t\t}\n\t\twhile (i + z[i] < n && s[z[i]] == s[i +\
    \ z[i]]) {\n\t\t\tz[i]++;\n\t\t}\n\t\tif (i + z[i] - 1 > r) {\n\t\t\tl = i;\n\t\
    \t\tr = i + z[i] - 1;\n\t\t}\n\t}\n\treturn z;\n}\n#line 5 \"String/Z_Algorithm.test.cpp\"\
    \n\nvoid solve() {\n\tstring s; cin >> s;\n\tvector<int> ans = Z_function(s);\n\
    \tfor (int x : ans) cout << x << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../template.h\"\n#include \"Z_Function.h\"\n\nvoid solve() {\n\tstring s;\
    \ cin >> s;\n\tvector<int> ans = Z_function(s);\n\tfor (int x : ans) cout << x\
    \ << \" \";\n}"
  dependsOn:
  - template.h
  - String/Z_Function.h
  isVerificationFile: true
  path: String/Z_Algorithm.test.cpp
  requiredBy: []
  timestamp: '2025-05-29 01:30:55+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: String/Z_Algorithm.test.cpp
layout: document
redirect_from:
- /verify/String/Z_Algorithm.test.cpp
- /verify/String/Z_Algorithm.test.cpp.html
title: String/Z_Algorithm.test.cpp
---
