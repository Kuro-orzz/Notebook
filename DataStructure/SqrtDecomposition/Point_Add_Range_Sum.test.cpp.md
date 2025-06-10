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
    \ {\npublic:\n\tint n, block_sz;\n\tvector<ll> a, block;\n\n\tSimpleSqrt() {}\n\
    \n\tSimpleSqrt(int _n): n(_n), a(_n, 0) {\n\t\tblock_sz = sqrt(_n);\n\t\tblock.resize(n\
    \ / block_sz + 1);\n\t}\n\n\tSimpleSqrt(int _n, vector<ll> &arr): n(_n), a(arr)\
    \ {\n\t\tblock_sz = sqrt(n);\n\t\tblock.resize(n / block_sz + 1);\n\t\tint cnt\
    \ = -1;\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tif(i % block_sz == 0) cnt++;\n\
    \t\t\tblock[cnt] += arr[i];\n\t\t}\n\t}\n\n\tll query(int l, int r) {\n\t    ll\
    \ sum = 0;\n\t    for(int i = l; i <= r;) {\n\t        if(i % block_sz == 0 &&\
    \ i+block_sz-1 <= r) {\n\t            sum += block[i/block_sz];\n\t          \
    \  i += block_sz;\n\t        } else {\n\t            sum += a[i];\n\t        \
    \    i++;\n\t        }\n\t    }\n\t    return sum;\n\t}\n\n\tvoid add(int pos,\
    \ int val) {\n\t\tint idx = pos / block_sz;\n\t\tblock[idx] += val;\n\t\ta[pos]\
    \ += val;\n\t}\n};\n#line 5 \"DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp\"\
    \n\nvoid solve() {\n\tint n, q; cin >> n >> q;\n\tvector<ll> a(n);\n\tfor (int\
    \ i = 0; i < n; i++) cin >> a[i];\n\tSimpleSqrt Sqrt(n, a);\n\twhile (q--) {\n\
    \t\tint tv; cin >> tv;\n\t\tif (tv == 0) {\n\t\t\tint pos, val; cin >> pos >>\
    \ val;\n\t\t\tSqrt.add(pos, val);\n\t\t} else {\n\t\t\tint l, r; cin >> l >> r;\n\
    \t\t\tcout << Sqrt.query(l, r-1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../template.h\"\n#include \"Sqrt.h\"\n\nvoid solve() {\n\tint\
    \ n, q; cin >> n >> q;\n\tvector<ll> a(n);\n\tfor (int i = 0; i < n; i++) cin\
    \ >> a[i];\n\tSimpleSqrt Sqrt(n, a);\n\twhile (q--) {\n\t\tint tv; cin >> tv;\n\
    \t\tif (tv == 0) {\n\t\t\tint pos, val; cin >> pos >> val;\n\t\t\tSqrt.add(pos,\
    \ val);\n\t\t} else {\n\t\t\tint l, r; cin >> l >> r;\n\t\t\tcout << Sqrt.query(l,\
    \ r-1) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - template.h
  - DataStructure/SqrtDecomposition/Sqrt.h
  isVerificationFile: true
  path: DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2025-06-10 22:27:06+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
- /verify/DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp.html
title: DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
---
