---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/SegTree/PersistentSegTree/test1.cpp
    title: DataStructure/SegTree/PersistentSegTree/test1.cpp
  - icon: ':warning:'
    path: DataStructure/SegTree/PersistentSegTree/test2.cpp
    title: DataStructure/SegTree/PersistentSegTree/test2.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1737/
    - https://www.spoj.com/problems/PSEGTREE/
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/PersistentSegTree/PersistentSegTree.h\"\
    \n\n// Tested:\n// - AC: https://cses.fi/problemset/task/1737/\n// - AC: https://www.spoj.com/problems/PSEGTREE/\n\
    \nstruct Node {\n\tNode *left, *right;\n\tll sum;\n\tNode() {}\n\tNode(ll _sum):\
    \ left(NULL), right(NULL), sum(_sum) {}\n\tNode(Node *l, Node *r, ll _sum): left(l),\
    \ right(r), sum(_sum) {}\n\t~Node() {\n\t\tdelete left;\n\t\tdelete right;\n\t\
    }\n};\n\nclass PersistentSegTree {\npublic:\n\tvector<Node*> ver;\n\n\tPersistentSegTree()\
    \ {}\n\tPersistentSegTree(int n): ver(n+1) {}\n\n\tvoid build(Node *cur, int l,\
    \ int r, const vector<int> &a) {\n\t\tif (l == r) {\n\t\t\tcur->sum = a[l];\n\t\
    \t\treturn;\n\t\t}\n\t\tint mid = (l + r) >> 1;\n\t\tcur->left = new Node(NULL,\
    \ NULL, 0);\n\t\tcur->right = new Node(NULL, NULL, 0);\n\t\tbuild(cur->left, l,\
    \ mid, a);\n\t\tbuild(cur->right, mid+1, r, a);\n\t\tcur->sum = cur->left->sum\
    \ + cur->right->sum;\n\t}\n\n\tvoid update(Node *prev, Node *cur, int l, int r,\
    \ int pos, ll x) {\n\t\tif (l == r) {\n\t\t\tcur->sum = x;\n\t\t\treturn;\n\t\t\
    }\n\t\tint mid = (l + r) >> 1;\n\t\tif (pos <= mid) {\n\t\t\tcur->right = prev->right;\n\
    \t\t\tcur->left = new Node(NULL, NULL, 0);\n\t\t\tupdate(prev->left, cur->left,\
    \ l, mid, pos, x);\n\t\t} else {\n\t\t\tcur->left = prev->left;\n\t\t\tcur->right\
    \ = new Node(NULL, NULL, 0);\n\t\t\tupdate(prev->right, cur->right, mid+1, r,\
    \ pos, x);\n\t\t}\n\t\tcur->sum = cur->left->sum + cur->right->sum;\n\t}\n\n\t\
    ll getSum(Node *cur, int l, int r, int u, int v) {\n\t\tif (l > v || r < u) return\
    \ 0;\n\t\tif (u <= l && r <= v) return cur->sum;\n\t\tint mid = (l + r) >> 1;\n\
    \t\treturn getSum(cur->left, l, mid, u, v) + getSum(cur->right, mid+1, r, u, v);\n\
    \t}\n};\n"
  code: "#include \"../../../template.h\"\n\n// Tested:\n// - AC: https://cses.fi/problemset/task/1737/\n\
    // - AC: https://www.spoj.com/problems/PSEGTREE/\n\nstruct Node {\n\tNode *left,\
    \ *right;\n\tll sum;\n\tNode() {}\n\tNode(ll _sum): left(NULL), right(NULL), sum(_sum)\
    \ {}\n\tNode(Node *l, Node *r, ll _sum): left(l), right(r), sum(_sum) {}\n\t~Node()\
    \ {\n\t\tdelete left;\n\t\tdelete right;\n\t}\n};\n\nclass PersistentSegTree {\n\
    public:\n\tvector<Node*> ver;\n\n\tPersistentSegTree() {}\n\tPersistentSegTree(int\
    \ n): ver(n+1) {}\n\n\tvoid build(Node *cur, int l, int r, const vector<int> &a)\
    \ {\n\t\tif (l == r) {\n\t\t\tcur->sum = a[l];\n\t\t\treturn;\n\t\t}\n\t\tint\
    \ mid = (l + r) >> 1;\n\t\tcur->left = new Node(NULL, NULL, 0);\n\t\tcur->right\
    \ = new Node(NULL, NULL, 0);\n\t\tbuild(cur->left, l, mid, a);\n\t\tbuild(cur->right,\
    \ mid+1, r, a);\n\t\tcur->sum = cur->left->sum + cur->right->sum;\n\t}\n\n\tvoid\
    \ update(Node *prev, Node *cur, int l, int r, int pos, ll x) {\n\t\tif (l == r)\
    \ {\n\t\t\tcur->sum = x;\n\t\t\treturn;\n\t\t}\n\t\tint mid = (l + r) >> 1;\n\t\
    \tif (pos <= mid) {\n\t\t\tcur->right = prev->right;\n\t\t\tcur->left = new Node(NULL,\
    \ NULL, 0);\n\t\t\tupdate(prev->left, cur->left, l, mid, pos, x);\n\t\t} else\
    \ {\n\t\t\tcur->left = prev->left;\n\t\t\tcur->right = new Node(NULL, NULL, 0);\n\
    \t\t\tupdate(prev->right, cur->right, mid+1, r, pos, x);\n\t\t}\n\t\tcur->sum\
    \ = cur->left->sum + cur->right->sum;\n\t}\n\n\tll getSum(Node *cur, int l, int\
    \ r, int u, int v) {\n\t\tif (l > v || r < u) return 0;\n\t\tif (u <= l && r <=\
    \ v) return cur->sum;\n\t\tint mid = (l + r) >> 1;\n\t\treturn getSum(cur->left,\
    \ l, mid, u, v) + getSum(cur->right, mid+1, r, u, v);\n\t}\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/PersistentSegTree/PersistentSegTree.h
  requiredBy:
  - DataStructure/SegTree/PersistentSegTree/test2.cpp
  - DataStructure/SegTree/PersistentSegTree/test1.cpp
  timestamp: '2025-05-25 00:26:18+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegTree/PersistentSegTree/PersistentSegTree.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/PersistentSegTree/PersistentSegTree.h
- /library/DataStructure/SegTree/PersistentSegTree/PersistentSegTree.h.html
title: DataStructure/SegTree/PersistentSegTree/PersistentSegTree.h
---
