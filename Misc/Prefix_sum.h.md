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
    \ 0;\n}\n#line 2 \"Misc/Prefix_sum.h\"\n\nvector<vector<ll>> prefix_2d_init(int\
    \ n, int m, const vector<vector<int>> &a) {\n    vector<vector<ll>> pref(n+1,\
    \ vector<ll>(m+1));\n    for (int i = 1; i <= n; i++) {\n        for (int j =\
    \ 1; j <= m; j++) {\n            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]\
    \ + a[i-1][j-1];\n        }\n    }\n    return pref;\n}\n\nll get(const vector<vector<ll>>\
    \ &pref, int a, int b, int c, int d) {\n    return pref[c][d]-pref[c][b-1]-pref[a-1][d]+pref[a-1][b-1];\n\
    }\n"
  code: "#include \"../template.h\"\n\nvector<vector<ll>> prefix_2d_init(int n, int\
    \ m, const vector<vector<int>> &a) {\n    vector<vector<ll>> pref(n+1, vector<ll>(m+1));\n\
    \    for (int i = 1; i <= n; i++) {\n        for (int j = 1; j <= m; j++) {\n\
    \            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i-1][j-1];\n\
    \        }\n    }\n    return pref;\n}\n\nll get(const vector<vector<ll>> &pref,\
    \ int a, int b, int c, int d) {\n    return pref[c][d]-pref[c][b-1]-pref[a-1][d]+pref[a-1][b-1];\n\
    }"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/Prefix_sum.h
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Prefix_sum.h
layout: document
redirect_from:
- /library/Misc/Prefix_sum.h
- /library/Misc/Prefix_sum.h.html
title: Misc/Prefix_sum.h
---
