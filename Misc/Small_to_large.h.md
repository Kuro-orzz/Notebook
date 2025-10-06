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
    links:
    - https://oj.vnoi.info/src/6109008
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Misc/Small_to_large.h\"\n\nconst int N = 1e5 + 6;\nvector<vector<int>>\
    \ adj;\nvector<int> color;\nset<int> cnt[N];\nvector<int> ans;\n\n// AC: https://oj.vnoi.info/src/6109008\n\
    void dfs(int u, int par) {\n    cnt[u].insert(color[u]);\n    for (int v : adj[u])\
    \ {\n        if (v == par) continue;\n        dfs(v, u);\n        if (cnt[u].size()\
    \ < cnt[v].size()) {\n            cnt[u].swap(cnt[v]);\n        }\n        for\
    \ (int i : cnt[v]) {\n            cnt[u].insert(i);\n        }\n    }\n    ans[u]\
    \ = cnt[u].size();\n}\n"
  code: "#include \"../template.h\"\n\nconst int N = 1e5 + 6;\nvector<vector<int>>\
    \ adj;\nvector<int> color;\nset<int> cnt[N];\nvector<int> ans;\n\n// AC: https://oj.vnoi.info/src/6109008\n\
    void dfs(int u, int par) {\n    cnt[u].insert(color[u]);\n    for (int v : adj[u])\
    \ {\n        if (v == par) continue;\n        dfs(v, u);\n        if (cnt[u].size()\
    \ < cnt[v].size()) {\n            cnt[u].swap(cnt[v]);\n        }\n        for\
    \ (int i : cnt[v]) {\n            cnt[u].insert(i);\n        }\n    }\n    ans[u]\
    \ = cnt[u].size();\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/Small_to_large.h
  requiredBy: []
  timestamp: '2025-06-07 01:24:49+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Small_to_large.h
layout: document
redirect_from:
- /library/Misc/Small_to_large.h
- /library/Misc/Small_to_large.h.html
title: Misc/Small_to_large.h
---
