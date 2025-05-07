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
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/SparseSegTree.h\"\n\n\nstruct Data {\n\
    \tll val = 0;\n\tll sz = 0;\n\tData() {}\n\tData(ll x) {\n\t\tthis->sz = 1;\n\t\
    \tval = x * sz;\n\t}\n\tData(ll x, ll L, ll R) {\n\t\tthis->sz = R-L+1;\n\t\t\
    val = x * sz;\n\t}\n\tvoid upd(Data x) {this->val = x.val * sz;}\n\tstatic Data\
    \ merge(Data a, Data b) {\n\t\tData res;\n\t\tres.val = a.val + b.val;\n\t\tres.sz\
    \ = a.sz + b.sz;\n\t\treturn res;\n\t}\n};\n\nstruct Tree {\n\tTree *left = 0,\
    \ *right = 0;\n\tll l, r;\n\tData d;\n\n\tTree(int L, int R) {l = L, r = R;}\n\
    \t~Tree() {\n\t\tdelete left;\n\t\tdelete right;\n\t}\n\n\tvoid update(int u,\
    \ int v, Data x) {\n\t\tif (l > v || r < u) return;\n\t\tif (u <= l && r <= v)\
    \ {\n\t\t\td.upd(x);\n\t\t\treturn;\n\t\t}\n\t\tll mid = (l + r) >> 1;\n\t\tif\
    \ (u <= mid) {\n\t\t\tif (!left) left = new Tree(l, mid);\n\t\t\tleft->update(u,\
    \ v, x);\n\t\t}\n\t\tif (v >= mid+1){\n\t\t\tif (!right) right = new Tree(mid+1,\
    \ r);\n\t\t\tright->update(u, v, x);\n\t\t}\n\t\tData t1 = left ? left->d : Data(0,\
    \ l, mid);\n\t\tData t2 = right ? right->d : Data(0, mid+1, r);\n\t\td = Data::merge(t1,\
    \ t2);\n\t}\n\n\tData query(int u, int v) {\n\t\tif (l > v || r < u) return {};\n\
    \t\tif (u <= l && r <= v) return d;\n\t\tint mid = (l + r) >> 1;\n\t\tif (left\
    \ && right) return Data::merge(left->query(u, v), right->query(u, v));\n\t\tData\
    \ t1 = left ? left->query(u, v) : Data();\n\t\tData t2 = right ? right->query(u,\
    \ v) : Data();\n\t\treturn Data::merge(t1, t2);\n\t}\n};\n"
  code: "#include \"../../template.h\"\n\n\nstruct Data {\n\tll val = 0;\n\tll sz\
    \ = 0;\n\tData() {}\n\tData(ll x) {\n\t\tthis->sz = 1;\n\t\tval = x * sz;\n\t\
    }\n\tData(ll x, ll L, ll R) {\n\t\tthis->sz = R-L+1;\n\t\tval = x * sz;\n\t}\n\
    \tvoid upd(Data x) {this->val = x.val * sz;}\n\tstatic Data merge(Data a, Data\
    \ b) {\n\t\tData res;\n\t\tres.val = a.val + b.val;\n\t\tres.sz = a.sz + b.sz;\n\
    \t\treturn res;\n\t}\n};\n\nstruct Tree {\n\tTree *left = 0, *right = 0;\n\tll\
    \ l, r;\n\tData d;\n\n\tTree(int L, int R) {l = L, r = R;}\n\t~Tree() {\n\t\t\
    delete left;\n\t\tdelete right;\n\t}\n\n\tvoid update(int u, int v, Data x) {\n\
    \t\tif (l > v || r < u) return;\n\t\tif (u <= l && r <= v) {\n\t\t\td.upd(x);\n\
    \t\t\treturn;\n\t\t}\n\t\tll mid = (l + r) >> 1;\n\t\tif (u <= mid) {\n\t\t\t\
    if (!left) left = new Tree(l, mid);\n\t\t\tleft->update(u, v, x);\n\t\t}\n\t\t\
    if (v >= mid+1){\n\t\t\tif (!right) right = new Tree(mid+1, r);\n\t\t\tright->update(u,\
    \ v, x);\n\t\t}\n\t\tData t1 = left ? left->d : Data(0, l, mid);\n\t\tData t2\
    \ = right ? right->d : Data(0, mid+1, r);\n\t\td = Data::merge(t1, t2);\n\t}\n\
    \n\tData query(int u, int v) {\n\t\tif (l > v || r < u) return {};\n\t\tif (u\
    \ <= l && r <= v) return d;\n\t\tint mid = (l + r) >> 1;\n\t\tif (left && right)\
    \ return Data::merge(left->query(u, v), right->query(u, v));\n\t\tData t1 = left\
    \ ? left->query(u, v) : Data();\n\t\tData t2 = right ? right->query(u, v) : Data();\n\
    \t\treturn Data::merge(t1, t2);\n\t}\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/SparseSegTree.h
  requiredBy: []
  timestamp: '2025-05-08 00:03:32+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegTree/SparseSegTree.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/SparseSegTree.h
- /library/DataStructure/SegTree/SparseSegTree.h.html
title: DataStructure/SegTree/SparseSegTree.h
---
