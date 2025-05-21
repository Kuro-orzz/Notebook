---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Range_affine_range_sum_large_array.test.cpp
    title: DataStructure/Range_affine_range_sum_large_array.test.cpp
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
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/SparseSegTree.h\"\n\n\nstruct Node {\n\
    \tNode *left = nullptr, *right = nullptr;\n\tll val;\n\tpll lazy = {1, 0};\n\t\
    \n\tNode(): val(0), lazy({1, 0}) {}\n\t\n\tNode operator+(const Node& b) const\
    \ {\n\t\tNode res;\n\t\tres.val = (val + b.val) % mod;\n\t\treturn res;\n\t}\n\
    \n\t~Node() {\n\t\tdelete left;\n\t\tdelete right;\n\t}\n};\n\nclass SparseSegTree\
    \ {\nprivate:\n\tNode *r = new Node();\n\tint n;\n\n\tvoid push(Node *cur, int\
    \ l, int r) {\n\t\tint m = (l + r) >> 1;\n\t\tif (!cur->left) cur->left = new\
    \ Node();\n\t\tif (!cur->right) cur->right = new Node();\n\t\tapply(cur->left,\
    \ l, m, cur->lazy);\n\t\tapply(cur->right, m+1, r, cur->lazy);\n\t\tcur->lazy\
    \ = {1, 0};\n\t}\n\n\tvoid apply(Node *cur, int l, int r, pll x) {\n\t\tll b =\
    \ x.fi, c = x.se;\n\t\tint len = r-l+1;\n\t\tcur->val = (cur->val * b % mod +\
    \ c * len % mod) % mod;\n\t\tcur->lazy.fi = cur->lazy.fi * b % mod;\n\t\tcur->lazy.se\
    \ = (cur->lazy.se * b % mod + c) % mod;\n\t}\n\n\tvoid update(Node *cur, int l,\
    \ int r, int u, int v, pll x) {\n\t\tif (l > v || r < u) return;\n\t\tif (u <=\
    \ l && r <= v) {\n\t\t\tapply(cur, l, r, x);\n\t\t\treturn;\n\t\t}\n\t\tpush(cur,\
    \ l, r);\n\t\tll mid = (l + r) >> 1;\n\t\tupdate(cur->left, l, mid, u, v, x);\n\
    \t\tupdate(cur->right, mid+1, r, u, v, x);\n\t\tcur->val = (cur->left->val + cur->right->val)\
    \ % mod;\n\t}\n\n\tll query(Node *cur, int l, int r, int u, int v) {\n\t\tif (l\
    \ > v || r < u) return 0;\n\t\tif (u <= l && r <= v) return cur->val;\n\t\tpush(cur,\
    \ l, r);\n\t\tint mid = (l + r) >> 1;\n\t\tll t1 = query(cur->left, l, mid, u,\
    \ v) % mod;\n\t\tll t2 = query(cur->right, mid+1, r, u, v) % mod;\n\t\treturn\
    \ (t1 + t2) % mod;\n\t}\n\npublic:\n\tSparseSegTree() {}\n\tSparseSegTree(int\
    \ _n): n(_n) {}\n\n\tvoid update(int u, int v, pll val) { update(r, 1, n, u, v,\
    \ val); }\n\t\n\tll query(int u, int v) { return query(r, 1, n, u, v); }\n};\n"
  code: "#include \"../../template.h\"\n\n\nstruct Node {\n\tNode *left = nullptr,\
    \ *right = nullptr;\n\tll val;\n\tpll lazy = {1, 0};\n\t\n\tNode(): val(0), lazy({1,\
    \ 0}) {}\n\t\n\tNode operator+(const Node& b) const {\n\t\tNode res;\n\t\tres.val\
    \ = (val + b.val) % mod;\n\t\treturn res;\n\t}\n\n\t~Node() {\n\t\tdelete left;\n\
    \t\tdelete right;\n\t}\n};\n\nclass SparseSegTree {\nprivate:\n\tNode *r = new\
    \ Node();\n\tint n;\n\n\tvoid push(Node *cur, int l, int r) {\n\t\tint m = (l\
    \ + r) >> 1;\n\t\tif (!cur->left) cur->left = new Node();\n\t\tif (!cur->right)\
    \ cur->right = new Node();\n\t\tapply(cur->left, l, m, cur->lazy);\n\t\tapply(cur->right,\
    \ m+1, r, cur->lazy);\n\t\tcur->lazy = {1, 0};\n\t}\n\n\tvoid apply(Node *cur,\
    \ int l, int r, pll x) {\n\t\tll b = x.fi, c = x.se;\n\t\tint len = r-l+1;\n\t\
    \tcur->val = (cur->val * b % mod + c * len % mod) % mod;\n\t\tcur->lazy.fi = cur->lazy.fi\
    \ * b % mod;\n\t\tcur->lazy.se = (cur->lazy.se * b % mod + c) % mod;\n\t}\n\n\t\
    void update(Node *cur, int l, int r, int u, int v, pll x) {\n\t\tif (l > v ||\
    \ r < u) return;\n\t\tif (u <= l && r <= v) {\n\t\t\tapply(cur, l, r, x);\n\t\t\
    \treturn;\n\t\t}\n\t\tpush(cur, l, r);\n\t\tll mid = (l + r) >> 1;\n\t\tupdate(cur->left,\
    \ l, mid, u, v, x);\n\t\tupdate(cur->right, mid+1, r, u, v, x);\n\t\tcur->val\
    \ = (cur->left->val + cur->right->val) % mod;\n\t}\n\n\tll query(Node *cur, int\
    \ l, int r, int u, int v) {\n\t\tif (l > v || r < u) return 0;\n\t\tif (u <= l\
    \ && r <= v) return cur->val;\n\t\tpush(cur, l, r);\n\t\tint mid = (l + r) >>\
    \ 1;\n\t\tll t1 = query(cur->left, l, mid, u, v) % mod;\n\t\tll t2 = query(cur->right,\
    \ mid+1, r, u, v) % mod;\n\t\treturn (t1 + t2) % mod;\n\t}\n\npublic:\n\tSparseSegTree()\
    \ {}\n\tSparseSegTree(int _n): n(_n) {}\n\n\tvoid update(int u, int v, pll val)\
    \ { update(r, 1, n, u, v, val); }\n\t\n\tll query(int u, int v) { return query(r,\
    \ 1, n, u, v); }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/SparseSegTree.h
  requiredBy: []
  timestamp: '2025-05-22 01:34:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/Range_affine_range_sum_large_array.test.cpp
documentation_of: DataStructure/SegTree/SparseSegTree.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/SparseSegTree.h
- /library/DataStructure/SegTree/SparseSegTree.h.html
title: DataStructure/SegTree/SparseSegTree.h
---
