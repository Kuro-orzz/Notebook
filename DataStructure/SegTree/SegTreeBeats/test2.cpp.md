---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/SegTree/SegTreeBeats/SegTreeBeats2.h
    title: DataStructure/SegTree/SegTreeBeats/SegTreeBeats2.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/group/1rv4rhCsHp/contest/327313/problem/B
  bundledCode: "#line 1 \"DataStructure/SegTree/SegTreeBeats/test2.cpp\"\n// https://codeforces.com/group/1rv4rhCsHp/contest/327313/problem/B\n\
    \n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n \n\
    #define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\
    #define vi vector<int>\n#define pii pair<int, int>\n#define pll pair<ll, ll>\n\
    #define fi first\n#define se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\
    \nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/SegTreeBeats/SegTreeBeats2.h\"\n\n\n\
    struct Node {\n\tll max1, max2, cntMax, sum, lazy;\n\n\tNode() {}\n\n\tNode(int\
    \ val) {\n\t\tmax1 = val;\n\t\tmax2 = -1;\n\t\tcntMax = 1;\n\t\tsum = val;\n\t\
    \tlazy = -1;\n\t}\n\n\tNode operator+(const Node &b) {\n\t\tNode res;\n\t\tres.max1\
    \ = max(max1, b.max1);\n\t\tres.max2 = max(max2, b.max2);\n\t\tif (res.max1 !=\
    \ max1) res.max2 = max(res.max2, max1);\n\t\tif (res.max1 != b.max1) res.max2\
    \ = max(res.max2, b.max1); \n\t\tres.cntMax = 0;\n\t\tif (res.max1 == max1) res.cntMax\
    \ += cntMax;\n\t\tif (res.max1 == b.max1) res.cntMax += b.cntMax;\n\t\tres.sum\
    \ = sum + b.sum;\n\t\tres.lazy = -1;\n\t\treturn res;\n\t}\n\n\tvoid setMin(int\
    \ val) {\n\t\tif (val > max1) return;\n\t\tsum -= (max1 - val) * cntMax;\n\t\t\
    max1 = val;\n\t\tlazy = val;\n\t}\n};\n\n// range chmin, sum\nclass SegTreeBeats\
    \ {\npublic:\n\tvector<Node> tree;\n\n\tSegTreeBeats(int n): tree(4*n) {}\n\n\t\
    void build(int id, int l, int r, int u, int v, int val) {\n\t\tif (l > v || r\
    \ < u) return;\n\t\tif (u <= l && r <= v) {\n\t\t\ttree[id] = Node(val);\n\t\t\
    \treturn;\n\t\t}\n\t\tint mid = (l + r) >> 1;\n\t\tbuild(id*2, l, mid, u, v, val);\n\
    \t\tbuild(id*2+1, mid+1, r, u, v, val);\n\t\ttree[id] = tree[id*2] + tree[id*2+1];\n\
    \t}\t\n\n\tvoid push(int id) {\n\t\tif (tree[id].lazy < 0) return;\n\t\ttree[id*2].setMin(tree[id].lazy);\n\
    \t\ttree[id*2+1].setMin(tree[id].lazy);\n\t\ttree[id].lazy = -1;\n\t}\n\n\tvoid\
    \ updateChmin(int id, int l, int r, int u, int v, int x) {\n\t\tif (l > v || r\
    \ < u) return;\n\t\tif (tree[id].max1 <= x) return;\n\t\tif (u <= l && r <= v\
    \ && tree[id].max2 < x) {\n\t\t\ttree[id].setMin(x);\n\t\t\treturn;\n\t\t}\n\t\
    \tpush(id);\n\t\tint mid = (l + r) >> 1;\n\t\tupdateChmin(id*2, l, mid, u, v,\
    \ x);\n\t\tupdateChmin(id*2+1, mid+1, r, u, v, x);\n\t\ttree[id] = tree[id*2]\
    \ + tree[id*2+1];\n\t}\n\n\tll getSum(int id, int l, int r, int u, int v) {\n\t\
    \tif (l > v || r < u) return 0;\n\t\tif (u <= l && r <= v) return tree[id].sum;\n\
    \t\tpush(id);\n\t\tint mid = (l + r) >> 1;\n\t\tll t1 = getSum(id*2, l, mid, u,\
    \ v);\n\t\tll t2 = getSum(id*2+1, mid+1, r, u, v);\n\t\treturn t1 + t2;\n\t}\n\
    };\n#line 5 \"DataStructure/SegTree/SegTreeBeats/test2.cpp\"\n\nvoid solve() {\n\
    \tint n; cin >> n;\n\tSegTreeBeats st(n+1);\n\tfor (int i = 1; i <= n; i++) {\n\
    \t\tint x; cin >> x;\n\t\tst.build(1, 1, n, i, i, x);\n\t}\n\tint q; cin >> q;\n\
    \twhile (q--) {\n\t\tint type; cin >> type;\n\t\tif (type == 1) {\n\t\t\tint l,\
    \ r, x; cin >> l >> r >> x;\n\t\t\tst.updateChmin(1, 1, n, l, r, x);\n\t\t} else\
    \ if (type == 2) {\n\t\t\tint l, r; cin >> l >> r;\n\t\t\tcout << st.getSum(1,\
    \ 1, n, l, r) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "// https://codeforces.com/group/1rv4rhCsHp/contest/327313/problem/B\n\n#include\
    \ \"../../../template.h\"\n#include \"SegTreeBeats2.h\"\n\nvoid solve() {\n\t\
    int n; cin >> n;\n\tSegTreeBeats st(n+1);\n\tfor (int i = 1; i <= n; i++) {\n\t\
    \tint x; cin >> x;\n\t\tst.build(1, 1, n, i, i, x);\n\t}\n\tint q; cin >> q;\n\
    \twhile (q--) {\n\t\tint type; cin >> type;\n\t\tif (type == 1) {\n\t\t\tint l,\
    \ r, x; cin >> l >> r >> x;\n\t\t\tst.updateChmin(1, 1, n, l, r, x);\n\t\t} else\
    \ if (type == 2) {\n\t\t\tint l, r; cin >> l >> r;\n\t\t\tcout << st.getSum(1,\
    \ 1, n, l, r) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - template.h
  - DataStructure/SegTree/SegTreeBeats/SegTreeBeats2.h
  isVerificationFile: false
  path: DataStructure/SegTree/SegTreeBeats/test2.cpp
  requiredBy: []
  timestamp: '2025-05-06 22:27:53+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegTree/SegTreeBeats/test2.cpp
layout: document
redirect_from:
- /library/DataStructure/SegTree/SegTreeBeats/test2.cpp
- /library/DataStructure/SegTree/SegTreeBeats/test2.cpp.html
title: DataStructure/SegTree/SegTreeBeats/test2.cpp
---
