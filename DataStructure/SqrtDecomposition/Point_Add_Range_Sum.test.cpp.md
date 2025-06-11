---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SqrtDecomposition/Sqrt.h
    title: DataStructure/SqrtDecomposition/Sqrt.h
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n \n\
    #define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SqrtDecomposition/Sqrt.h\"\n\nclass SimpleSqrt\
    \ {\npublic:\n    int n, block_sz;\n    vector<ll> a, block;\n\n    SimpleSqrt()\
    \ {}\n\n    SimpleSqrt(int _n): n(_n), a(_n, 0) {\n        block_sz = sqrt(_n);\n\
    \        block.resize(n / block_sz + 1);\n    }\n\n    SimpleSqrt(int _n, vector<ll>\
    \ &arr): n(_n), a(arr) {\n        block_sz = sqrt(n);\n        block.resize(n\
    \ / block_sz + 1);\n        int cnt = -1;\n        for(int i = 0; i < n; i++)\
    \ {\n            if(i % block_sz == 0) cnt++;\n            block[cnt] += arr[i];\n\
    \        }\n    }\n\n    ll query(int l, int r) {\n        ll sum = 0;\n     \
    \   for(int i = l; i <= r;) {\n            if(i % block_sz == 0 && i+block_sz-1\
    \ <= r) {\n                sum += block[i/block_sz];\n                i += block_sz;\n\
    \            } else {\n                sum += a[i];\n                i++;\n  \
    \          }\n        }\n        return sum;\n    }\n\n    void add(int pos, int\
    \ val) {\n        int idx = pos / block_sz;\n        block[idx] += val;\n    \
    \    a[pos] += val;\n    }\n};\n#line 5 \"DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp\"\
    \n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    vector<ll> a(n);\n    for\
    \ (int i = 0; i < n; i++) cin >> a[i];\n    SimpleSqrt Sqrt(n, a);\n    while\
    \ (q--) {\n        int tv; cin >> tv;\n        if (tv == 0) {\n            int\
    \ pos, val; cin >> pos >> val;\n            Sqrt.add(pos, val);\n        } else\
    \ {\n            int l, r; cin >> l >> r;\n            cout << Sqrt.query(l, r-1)\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../template.h\"\n#include \"Sqrt.h\"\n\nvoid solve() {\n    int\
    \ n, q; cin >> n >> q;\n    vector<ll> a(n);\n    for (int i = 0; i < n; i++)\
    \ cin >> a[i];\n    SimpleSqrt Sqrt(n, a);\n    while (q--) {\n        int tv;\
    \ cin >> tv;\n        if (tv == 0) {\n            int pos, val; cin >> pos >>\
    \ val;\n            Sqrt.add(pos, val);\n        } else {\n            int l,\
    \ r; cin >> l >> r;\n            cout << Sqrt.query(l, r-1) << '\\n';\n      \
    \  }\n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/SqrtDecomposition/Sqrt.h
  isVerificationFile: true
  path: DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
- /verify/DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp.html
title: DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
---
