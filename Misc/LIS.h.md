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
    links:
    - https://hnoj.edu.vn/contest/hnoi2023v1/all
    - https://marisaoj.com/problem/276
    - https://oj.vnoi.info/problem/lis
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Misc/LIS.h\"\n\nconst int N = 2e5 + 6;\nvector<vector<int>>\
    \ adj;\nvector<int> a, ans;\nset<int> s[N];\n\n// AC: https://oj.vnoi.info/problem/lis\n\
    int LIS(vector<int> &a) {\n    multiset<int> s;\n    for (int x : a) {\n     \
    \   auto it = s.lower_bound(x);\n        if (it != s.end()) {\n            s.erase(it);\n\
    \        }\n        s.insert(x);\n    }\n    return s.size();\n}\n\nint __LIS(vector<int>\
    \ &a) {\n    vector<int> v;\n    for (int x : a) {\n        auto it = lower_bound(all(v),\
    \ x);\n        if (it != v.end()) {\n            (*it) = min((*it), x);\n    \
    \    } else {\n            v.push_back(x);\n        }\n    }\n    return v.size();\n\
    }\n\n// LIS on tree\n// AC: https://marisaoj.com/problem/276\n// AC: https://hnoj.edu.vn/contest/hnoi2023v1/all\n\
    void dfs(int u, int par) {\n    for (int v : adj[u]) {\n        if (v == par)\
    \ continue;\n        dfs(v, u);\n        if (s[u].size() < s[v].size()) {\n  \
    \          swap(s[u], s[v]);\n        }\n        for (auto it : s[v]) {\n    \
    \        s[u].insert(it);\n        }\n    }\n    auto it = s[u].lower_bound(a[u]);\n\
    \    if (it != s[u].end()) {\n        s[u].erase(it);\n    }\n    s[u].insert(a[u]);\n\
    \    ans[u] = s[u].size();\n}\n"
  code: "#include \"../template.h\"\n\nconst int N = 2e5 + 6;\nvector<vector<int>>\
    \ adj;\nvector<int> a, ans;\nset<int> s[N];\n\n// AC: https://oj.vnoi.info/problem/lis\n\
    int LIS(vector<int> &a) {\n    multiset<int> s;\n    for (int x : a) {\n     \
    \   auto it = s.lower_bound(x);\n        if (it != s.end()) {\n            s.erase(it);\n\
    \        }\n        s.insert(x);\n    }\n    return s.size();\n}\n\nint __LIS(vector<int>\
    \ &a) {\n    vector<int> v;\n    for (int x : a) {\n        auto it = lower_bound(all(v),\
    \ x);\n        if (it != v.end()) {\n            (*it) = min((*it), x);\n    \
    \    } else {\n            v.push_back(x);\n        }\n    }\n    return v.size();\n\
    }\n\n// LIS on tree\n// AC: https://marisaoj.com/problem/276\n// AC: https://hnoj.edu.vn/contest/hnoi2023v1/all\n\
    void dfs(int u, int par) {\n    for (int v : adj[u]) {\n        if (v == par)\
    \ continue;\n        dfs(v, u);\n        if (s[u].size() < s[v].size()) {\n  \
    \          swap(s[u], s[v]);\n        }\n        for (auto it : s[v]) {\n    \
    \        s[u].insert(it);\n        }\n    }\n    auto it = s[u].lower_bound(a[u]);\n\
    \    if (it != s[u].end()) {\n        s[u].erase(it);\n    }\n    s[u].insert(a[u]);\n\
    \    ans[u] = s[u].size();\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/LIS.h
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/LIS.h
layout: document
redirect_from:
- /library/Misc/LIS.h
- /library/Misc/LIS.h.html
title: Misc/LIS.h
---
