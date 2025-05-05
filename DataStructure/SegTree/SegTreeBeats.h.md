---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/SegTree/test.cpp
    title: DataStructure/SegTree/test.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    \ \n#define vi vector<int>\n#define pii pair<int, int>\n#define fi first\n#define\
    \ se second\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"DataStructure/SegTree/SegTreeBeats.h\"\
    \n\n\nstruct Node {\n\tll Max, sum;\n\n\tNode() {}\n\n\tNode(int val) {\n\t\t\
    Max = val;\n\t\tsum = val;\n\t}\n\n\tNode operator+(const Node &b) {\n\t\tNode\
    \ res;\n\t\tres.Max = max(Max, b.Max);\n\t\tres.sum = sum + b.sum;\n\t\treturn\
    \ res;\n\t}\n};\n\n// range mod, sum query\n// point assign query\nclass SegTreeBeats\
    \ {\npublic:\n\tvector<Node> tree;\n\n\tSegTreeBeats(int n): tree(4*n) {}\n\n\t\
    void build(int id, int l, int r, int u, int v, int val) {\n\t\tif (l > v || r\
    \ < u) return;\n\t\tif (u <= l && r <= v) {\n\t\t\ttree[id] = Node(val);\n\t\t\
    \treturn;\n\t\t}\n\t\tint mid = (l + r) >> 1;\n\t\tbuild(id*2, l, mid, u, v, val);\n\
    \t\tbuild(id*2+1, mid+1, r, u, v, val);\n\t\ttree[id] = tree[id*2] + tree[id*2+1];\n\
    \t}\t\n\n\tvoid updateMod(int id, int l, int r, int u, int v, int x) {\n\t\tif\
    \ (l > v || r < u) return;\n\t\tif (tree[id].Max < x) return;\n\t\tif (l == r)\
    \ {\n\t\t\ttree[id].Max %= x;\n\t\t\ttree[id].sum = tree[id].Max;\n\t\t\treturn;\n\
    \t\t}\n\t\tint mid = (l + r) >> 1;\n\t\tupdateMod(id*2, l, mid, u, v, x);\n\t\t\
    updateMod(id*2+1, mid+1, r, u, v, x);\n\t\ttree[id] = tree[id*2] + tree[id*2+1];\n\
    \t}\n\n\tll getSum(int id, int l, int r, int u, int v) {\n\t\tif (l > v || r <\
    \ u) return 0;\n\t\tif (u <= l && r <= v) return tree[id].sum;\n\t\tint mid =\
    \ (l + r) >> 1;\n\t\tll t1 = getSum(id*2, l, mid, u, v);\n\t\tll t2 = getSum(id*2+1,\
    \ mid+1, r, u, v);\n\t\treturn t1 + t2;\n\t}\n};\n"
  code: "#include \"../../template.h\"\n\n\nstruct Node {\n\tll Max, sum;\n\n\tNode()\
    \ {}\n\n\tNode(int val) {\n\t\tMax = val;\n\t\tsum = val;\n\t}\n\n\tNode operator+(const\
    \ Node &b) {\n\t\tNode res;\n\t\tres.Max = max(Max, b.Max);\n\t\tres.sum = sum\
    \ + b.sum;\n\t\treturn res;\n\t}\n};\n\n// range mod, sum query\n// point assign\
    \ query\nclass SegTreeBeats {\npublic:\n\tvector<Node> tree;\n\n\tSegTreeBeats(int\
    \ n): tree(4*n) {}\n\n\tvoid build(int id, int l, int r, int u, int v, int val)\
    \ {\n\t\tif (l > v || r < u) return;\n\t\tif (u <= l && r <= v) {\n\t\t\ttree[id]\
    \ = Node(val);\n\t\t\treturn;\n\t\t}\n\t\tint mid = (l + r) >> 1;\n\t\tbuild(id*2,\
    \ l, mid, u, v, val);\n\t\tbuild(id*2+1, mid+1, r, u, v, val);\n\t\ttree[id] =\
    \ tree[id*2] + tree[id*2+1];\n\t}\t\n\n\tvoid updateMod(int id, int l, int r,\
    \ int u, int v, int x) {\n\t\tif (l > v || r < u) return;\n\t\tif (tree[id].Max\
    \ < x) return;\n\t\tif (l == r) {\n\t\t\ttree[id].Max %= x;\n\t\t\ttree[id].sum\
    \ = tree[id].Max;\n\t\t\treturn;\n\t\t}\n\t\tint mid = (l + r) >> 1;\n\t\tupdateMod(id*2,\
    \ l, mid, u, v, x);\n\t\tupdateMod(id*2+1, mid+1, r, u, v, x);\n\t\ttree[id] =\
    \ tree[id*2] + tree[id*2+1];\n\t}\n\n\tll getSum(int id, int l, int r, int u,\
    \ int v) {\n\t\tif (l > v || r < u) return 0;\n\t\tif (u <= l && r <= v) return\
    \ tree[id].sum;\n\t\tint mid = (l + r) >> 1;\n\t\tll t1 = getSum(id*2, l, mid,\
    \ u, v);\n\t\tll t2 = getSum(id*2+1, mid+1, r, u, v);\n\t\treturn t1 + t2;\n\t\
    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/SegTreeBeats.h
  requiredBy:
  - DataStructure/SegTree/test.cpp
  timestamp: '2025-05-05 10:27:01+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegTree/SegTreeBeats.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/SegTreeBeats.h
- /library/DataStructure/SegTree/SegTreeBeats.h.html
title: DataStructure/SegTree/SegTreeBeats.h
---
