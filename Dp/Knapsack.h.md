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
    \ 0;\n}\n#line 2 \"Dp/Knapsack.h\"\n\n// 1 <= N <= 100, 1 <= W <= 1e5\n// 1 <=\
    \ wi <= W, 1 <= vi <= 1e9\nvoid knapsack01() {\n    int n, W; cin >> n >> W;\n\
    \    vector<int> w(n+1), v(n+1);\n    for (int i = 1; i <= n; i++) {\n       \
    \ cin >> w[i] >> v[i];\n    }\n    vector<vector<ll>> dp(n+1, vector<ll>(W+1));\n\
    \    for (int i = 1; i <= n; i++) {\n        for (int j = 1; j <= W; j++) {\n\
    \            dp[i][j] = dp[i-1][j];\n            if (j-w[i] < 0) continue;\n \
    \           dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);\n        }\n   \
    \ }\n    cout << dp[n][W];\n}\n\n// 1 <= N <= 100, 1 <= W <= 1e9\n// 1 <= wi <=\
    \ W, 1 <= vi <= 1e3\nvoid knapsack02() {\n    int n, W; cin >> n >> W;\n    vector<int>\
    \ w(n+1), v(n+1);\n    for (int i = 1; i <= n; i++) {\n        cin >> w[i] >>\
    \ v[i];\n    }\n    vector<vector<ll>> dp(n+1, vector<ll>(1e5+1, 1e18));\n   \
    \ for (int i = 0; i <= n; i++) {\n        dp[i][0] = 0;\n    }\n    for (int i\
    \ = 1; i <= n; i++) {\n        for (int j = 0; j <= 1e5; j++) {\n            dp[i][j]\
    \ = dp[i-1][j];\n            if (j-v[i] < 0) continue;\n            if (dp[i-1][j-v[i]]\
    \ + w[i] <= W) {\n                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]);\n\
    \            }\n        }\n    }\n    for (int i = 1e5; i >= 0; i--) {\n     \
    \   if (dp[n][i] <= W) {\n            cout << i;\n            return;\n      \
    \  }\n    }\n}\n"
  code: "#include \"../template.h\"\n\n// 1 <= N <= 100, 1 <= W <= 1e5\n// 1 <= wi\
    \ <= W, 1 <= vi <= 1e9\nvoid knapsack01() {\n    int n, W; cin >> n >> W;\n  \
    \  vector<int> w(n+1), v(n+1);\n    for (int i = 1; i <= n; i++) {\n        cin\
    \ >> w[i] >> v[i];\n    }\n    vector<vector<ll>> dp(n+1, vector<ll>(W+1));\n\
    \    for (int i = 1; i <= n; i++) {\n        for (int j = 1; j <= W; j++) {\n\
    \            dp[i][j] = dp[i-1][j];\n            if (j-w[i] < 0) continue;\n \
    \           dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);\n        }\n   \
    \ }\n    cout << dp[n][W];\n}\n\n// 1 <= N <= 100, 1 <= W <= 1e9\n// 1 <= wi <=\
    \ W, 1 <= vi <= 1e3\nvoid knapsack02() {\n    int n, W; cin >> n >> W;\n    vector<int>\
    \ w(n+1), v(n+1);\n    for (int i = 1; i <= n; i++) {\n        cin >> w[i] >>\
    \ v[i];\n    }\n    vector<vector<ll>> dp(n+1, vector<ll>(1e5+1, 1e18));\n   \
    \ for (int i = 0; i <= n; i++) {\n        dp[i][0] = 0;\n    }\n    for (int i\
    \ = 1; i <= n; i++) {\n        for (int j = 0; j <= 1e5; j++) {\n            dp[i][j]\
    \ = dp[i-1][j];\n            if (j-v[i] < 0) continue;\n            if (dp[i-1][j-v[i]]\
    \ + w[i] <= W) {\n                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]);\n\
    \            }\n        }\n    }\n    for (int i = 1e5; i >= 0; i--) {\n     \
    \   if (dp[n][i] <= W) {\n            cout << i;\n            return;\n      \
    \  }\n    }\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Dp/Knapsack.h
  requiredBy: []
  timestamp: '2025-10-06 23:30:53+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dp/Knapsack.h
layout: document
redirect_from:
- /library/Dp/Knapsack.h
- /library/Dp/Knapsack.h.html
title: Dp/Knapsack.h
---
