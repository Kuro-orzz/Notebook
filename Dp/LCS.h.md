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
    \ 0;\n}\n#line 2 \"Dp/LCS.h\"\n\n\n// Longest common substring with trace\n\n\
    struct Trace {\n    int i, j;\n    char c;\n    Trace(int _i = 0, int _j = 0,\
    \ char _c = '\\0'): i(_i), j(_j), c(_c) {}\n};\n\nvoid solve() {\n    string s1,\
    \ s2; cin >> s1 >> s2;\n    s1 = \"#\" + s1;\n    s2 = \"#\" + s2;\n    int n\
    \ = s1.size(), m = s2.size();\n    int dp[n][m];\n    Trace par[n][m] = {};\n\
    \    memset(dp, 0, sizeof dp);\n    for (int i = 1; i < n; i++) {\n        for\
    \ (int j = 1; j < m; j++) {\n            if (s1[i] == s2[j]) {\n             \
    \   dp[i][j] = dp[i-1][j-1] + 1;\n                par[i][j] = Trace(i-1, j-1,\
    \ s1[i]);\n            } else {\n                if (dp[i][j-1] >= dp[i-1][j])\
    \ {\n                    dp[i][j] = dp[i][j-1];\n                    par[i][j]\
    \ = Trace(i, j-1);\n                } else {\n                    dp[i][j] = dp[i-1][j];\n\
    \                    par[i][j] = Trace(i-1, j);\n                }\n         \
    \   }\n        }\n    }\n    Trace cur = par[n-1][m-1];\n    string ans = \"\"\
    ;\n    while (1) {\n        if (cur.c != '\\0') ans += cur.c;\n        if (!cur.i\
    \ && !cur.j) break;\n        cur = par[cur.i][cur.j];\n    }\n    reverse(all(ans));\n\
    \    cout << ans;\n}\n"
  code: "#include \"../template.h\"\n\n\n// Longest common substring with trace\n\n\
    struct Trace {\n    int i, j;\n    char c;\n    Trace(int _i = 0, int _j = 0,\
    \ char _c = '\\0'): i(_i), j(_j), c(_c) {}\n};\n\nvoid solve() {\n    string s1,\
    \ s2; cin >> s1 >> s2;\n    s1 = \"#\" + s1;\n    s2 = \"#\" + s2;\n    int n\
    \ = s1.size(), m = s2.size();\n    int dp[n][m];\n    Trace par[n][m] = {};\n\
    \    memset(dp, 0, sizeof dp);\n    for (int i = 1; i < n; i++) {\n        for\
    \ (int j = 1; j < m; j++) {\n            if (s1[i] == s2[j]) {\n             \
    \   dp[i][j] = dp[i-1][j-1] + 1;\n                par[i][j] = Trace(i-1, j-1,\
    \ s1[i]);\n            } else {\n                if (dp[i][j-1] >= dp[i-1][j])\
    \ {\n                    dp[i][j] = dp[i][j-1];\n                    par[i][j]\
    \ = Trace(i, j-1);\n                } else {\n                    dp[i][j] = dp[i-1][j];\n\
    \                    par[i][j] = Trace(i-1, j);\n                }\n         \
    \   }\n        }\n    }\n    Trace cur = par[n-1][m-1];\n    string ans = \"\"\
    ;\n    while (1) {\n        if (cur.c != '\\0') ans += cur.c;\n        if (!cur.i\
    \ && !cur.j) break;\n        cur = par[cur.i][cur.j];\n    }\n    reverse(all(ans));\n\
    \    cout << ans;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Dp/LCS.h
  requiredBy: []
  timestamp: '2025-10-06 23:30:53+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dp/LCS.h
layout: document
redirect_from:
- /library/Dp/LCS.h
- /library/Dp/LCS.h.html
title: Dp/LCS.h
---
