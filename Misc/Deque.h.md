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
    \ 0;\n}\n#line 2 \"Misc/Deque.h\"\n\nvector<int> maxRange(const vector<int>& a,\
    \ int k) {\n    deque<int> dq;\n    vector<int> res;\n    for(size_t i = 0; i\
    \ < a.size(); i++) {\n        while(!dq.empty() && a[dq.back()] <= a[i]) {\n \
    \           dq.pop_back();\n        }\n        dq.push_back(i);\n        if(dq.front()\
    \ + k <= i) dq.pop_front();\n        if(i >= k-1) res.push_back(a[dq.front()]);\n\
    \    }\n    return res;\n}\n\nvector<int> minRange(const vector<int>& a, int k)\
    \ {\n    deque<int> dq;\n    vector<int> res;\n    for(size_t i = 0; i < a.size();\
    \ i++) {\n        while(!dq.empty() && a[dq.back()] >= a[i]) {\n            dq.pop_back();\n\
    \        }\n        dq.push_back(i);\n        if(dq.front() + k <= i) dq.pop_front();\n\
    \        if(i >= k-1) res.push_back(a[dq.front()]);\n    }\n    return res;\n\
    }\n"
  code: "#include \"../template.h\"\n\nvector<int> maxRange(const vector<int>& a,\
    \ int k) {\n    deque<int> dq;\n    vector<int> res;\n    for(size_t i = 0; i\
    \ < a.size(); i++) {\n        while(!dq.empty() && a[dq.back()] <= a[i]) {\n \
    \           dq.pop_back();\n        }\n        dq.push_back(i);\n        if(dq.front()\
    \ + k <= i) dq.pop_front();\n        if(i >= k-1) res.push_back(a[dq.front()]);\n\
    \    }\n    return res;\n}\n\nvector<int> minRange(const vector<int>& a, int k)\
    \ {\n    deque<int> dq;\n    vector<int> res;\n    for(size_t i = 0; i < a.size();\
    \ i++) {\n        while(!dq.empty() && a[dq.back()] >= a[i]) {\n            dq.pop_back();\n\
    \        }\n        dq.push_back(i);\n        if(dq.front() + k <= i) dq.pop_front();\n\
    \        if(i >= k-1) res.push_back(a[dq.front()]);\n    }\n    return res;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/Deque.h
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Deque.h
layout: document
redirect_from:
- /library/Misc/Deque.h
- /library/Misc/Deque.h.html
title: Misc/Deque.h
---
