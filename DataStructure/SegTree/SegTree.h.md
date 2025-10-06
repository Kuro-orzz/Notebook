---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Yosupo/Point_add_range_sum.test.cpp
    title: DataStructure/Yosupo/Point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/SegTree.h\"\n\ntemplate <typename T>\n\
    struct SegTree {\n    int n;\n    vector<T> tree;\n\n    SegTree() {}\n    SegTree(int\
    \ _n): n(_n), tree(_n*4) {}\n\n    void update(int pos, T val) {\n        update(1,\
    \ 1, n, pos, val);\n    }\n\n    T getSum(int u, int v) {\n        return getSum(1,\
    \ 1, n, u, v);\n    }\n\n    void update(int id, int l, int r, int pos, T val)\
    \ {\n        if (pos < l || pos > r) return;\n        if (l == r) {\n        \
    \    tree[id] += val;\n            return;\n        }\n        int mid = (l +\
    \ r) >> 1;\n        update(id*2, l, mid, pos, val);\n        update(id*2+1, mid+1,\
    \ r, pos, val);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\n\n    T\
    \ getSum(int id, int l, int r, int u, int v) {\n        if (l > v || r < u) return\
    \ 0;\n        if (l >= u && r <= v) return tree[id];\n        int mid = (l + r)\
    \ >> 1;\n        T t1 = getSum(id*2, l, mid, u, v);\n        T t2 = getSum(id*2+1,\
    \ mid+1, r, u, v);\n        return t1 + t2;\n    }\n};\n"
  code: "#include \"../../template.h\"\n\ntemplate <typename T>\nstruct SegTree {\n\
    \    int n;\n    vector<T> tree;\n\n    SegTree() {}\n    SegTree(int _n): n(_n),\
    \ tree(_n*4) {}\n\n    void update(int pos, T val) {\n        update(1, 1, n,\
    \ pos, val);\n    }\n\n    T getSum(int u, int v) {\n        return getSum(1,\
    \ 1, n, u, v);\n    }\n\n    void update(int id, int l, int r, int pos, T val)\
    \ {\n        if (pos < l || pos > r) return;\n        if (l == r) {\n        \
    \    tree[id] += val;\n            return;\n        }\n        int mid = (l +\
    \ r) >> 1;\n        update(id*2, l, mid, pos, val);\n        update(id*2+1, mid+1,\
    \ r, pos, val);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\n\n    T\
    \ getSum(int id, int l, int r, int u, int v) {\n        if (l > v || r < u) return\
    \ 0;\n        if (l >= u && r <= v) return tree[id];\n        int mid = (l + r)\
    \ >> 1;\n        T t1 = getSum(id*2, l, mid, u, v);\n        T t2 = getSum(id*2+1,\
    \ mid+1, r, u, v);\n        return t1 + t2;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/SegTree.h
  requiredBy: []
  timestamp: '2025-05-20 14:35:59+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/Yosupo/Point_add_range_sum.test.cpp
documentation_of: DataStructure/SegTree/SegTree.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/SegTree.h
- /library/DataStructure/SegTree/SegTree.h.html
title: DataStructure/SegTree/SegTree.h
---
