---
data:
  _extendedDependsOn:
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
  bundledCode: "#line 1 \"NumberTheory/Aizu/aizu_ntl_1_c_lcm.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C\"\n\n#line\
    \ 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define\
    \ ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 4 \"NumberTheory/Aizu/aizu_ntl_1_c_lcm.test.cpp\"\n\n// lcm support\
    \ C++17 and above only\n// if C++ lower than 17, use x / __gcd(x, y) * y\n\nvoid\
    \ solve() {\n    int n; cin >> n;\n    int a[n];\n    for (int i = 0; i < n; i++)\
    \ {\n        cin >> a[i];\n    }\n    int ans = a[0];\n    for (int i = 1; i <\
    \ n; i++) {\n        ans = lcm(ans, a[i]);\n    }\n    cout << ans << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C\"\
    \n\n#include \"../../template.h\"\n\n// lcm support C++17 and above only\n// if\
    \ C++ lower than 17, use x / __gcd(x, y) * y\n\nvoid solve() {\n    int n; cin\
    \ >> n;\n    int a[n];\n    for (int i = 0; i < n; i++) {\n        cin >> a[i];\n\
    \    }\n    int ans = a[0];\n    for (int i = 1; i < n; i++) {\n        ans =\
    \ lcm(ans, a[i]);\n    }\n    cout << ans << '\\n';\n}"
  dependsOn:
  - template.h
  isVerificationFile: true
  path: NumberTheory/Aizu/aizu_ntl_1_c_lcm.test.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Aizu/aizu_ntl_1_c_lcm.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Aizu/aizu_ntl_1_c_lcm.test.cpp
- /verify/NumberTheory/Aizu/aizu_ntl_1_c_lcm.test.cpp.html
title: NumberTheory/Aizu/aizu_ntl_1_c_lcm.test.cpp
---
