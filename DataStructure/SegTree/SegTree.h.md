---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Point_add_range_sum.test.cpp
    title: DataStructure/Point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\
    #define vi vector<int>\n#define pii pair<int, int>\n#define pll pair<ll, ll>\n\
    #define fi first\n#define se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\
    \nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/SegTree.h\"\n\ntemplate <typename T>\n\
    struct SegTree {\n\tvector<T> sum;\n\n\tSegTree() {}\n\tSegTree(int n): sum(n*4)\
    \ {}\n\n\tvoid update(int id, int l, int r, int pos, T val) {\n\t\tif (pos < l\
    \ || pos > r) return;\n\t\tif (l == r) {\n\t\t\tsum[id] += val;\n\t\t\treturn;\n\
    \t\t}\n\t\tint mid = (l + r) >> 1;\n\t\tupdate(id*2, l, mid, pos, val);\n\t\t\
    update(id*2+1, mid+1, r, pos, val);\n\t\tsum[id] = sum[id*2] + sum[id*2+1];\n\t\
    }\n\n\tT getSum(int id, int l, int r, int u, int v) {\n\t\tif (l > v || r < u)\
    \ return 0;\n\t\tif (l >= u && r <= v) return sum[id];\n\t\tint mid = (l + r)\
    \ >> 1;\n\t\tT t1 = getSum(id*2, l, mid, u, v);\n\t\tT t2 = getSum(id*2+1, mid+1,\
    \ r, u, v);\n\t\treturn t1 + t2;\n\t}\n};\n"
  code: "#include \"../../template.h\"\n\ntemplate <typename T>\nstruct SegTree {\n\
    \tvector<T> sum;\n\n\tSegTree() {}\n\tSegTree(int n): sum(n*4) {}\n\n\tvoid update(int\
    \ id, int l, int r, int pos, T val) {\n\t\tif (pos < l || pos > r) return;\n\t\
    \tif (l == r) {\n\t\t\tsum[id] += val;\n\t\t\treturn;\n\t\t}\n\t\tint mid = (l\
    \ + r) >> 1;\n\t\tupdate(id*2, l, mid, pos, val);\n\t\tupdate(id*2+1, mid+1, r,\
    \ pos, val);\n\t\tsum[id] = sum[id*2] + sum[id*2+1];\n\t}\n\n\tT getSum(int id,\
    \ int l, int r, int u, int v) {\n\t\tif (l > v || r < u) return 0;\n\t\tif (l\
    \ >= u && r <= v) return sum[id];\n\t\tint mid = (l + r) >> 1;\n\t\tT t1 = getSum(id*2,\
    \ l, mid, u, v);\n\t\tT t2 = getSum(id*2+1, mid+1, r, u, v);\n\t\treturn t1 +\
    \ t2;\n\t}\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/SegTree.h
  requiredBy: []
  timestamp: '2025-05-06 22:27:53+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/Point_add_range_sum.test.cpp
documentation_of: DataStructure/SegTree/SegTree.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/SegTree.h
- /library/DataStructure/SegTree/SegTree.h.html
title: DataStructure/SegTree/SegTree.h
---
