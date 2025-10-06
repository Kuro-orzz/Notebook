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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"DataStructure/Yosupo/Associative_array.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n#line 2 \"\
    template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define ll\
    \ long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n#define\
    \ INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n#define\
    \ pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define se second\n\
    \nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 4 \"DataStructure/Yosupo/Associative_array.test.cpp\"\
    \n\nvoid solve(){\n    unordered_map<ll, ll> mp;\n    int q; cin >> q;\n    while\
    \ (q--) {\n        int tv; cin >> tv;\n        if (tv == 0) {\n            ll\
    \ k, v; cin >> k >> v;\n            mp[k] = v;\n        }\n        else {\n  \
    \          ll k; cin >> k;\n            cout << mp[k] << '\\n';\n        }\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include \"../../template.h\"\n\nvoid solve(){\n    unordered_map<ll, ll> mp;\n\
    \    int q; cin >> q;\n    while (q--) {\n        int tv; cin >> tv;\n       \
    \ if (tv == 0) {\n            ll k, v; cin >> k >> v;\n            mp[k] = v;\n\
    \        }\n        else {\n            ll k; cin >> k;\n            cout << mp[k]\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  isVerificationFile: true
  path: DataStructure/Yosupo/Associative_array.test.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Yosupo/Associative_array.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Yosupo/Associative_array.test.cpp
- /verify/DataStructure/Yosupo/Associative_array.test.cpp.html
title: DataStructure/Yosupo/Associative_array.test.cpp
---
