---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h
    title: DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/438/D
  bundledCode: "#line 1 \"DataStructure/SegTree/SegTreeBeats/test1.cpp\"\n// https://codeforces.com/problemset/problem/438/D\n\
    \n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n \n\
    #define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h\"\n\n\n\
    struct Node {\n\tll Max, sum;\n\n\tNode() {}\n\n\tNode(int val) {\n\t\tMax = val;\n\
    \t\tsum = val;\n\t}\n\n\tNode operator+(const Node &b) {\n\t\tNode res;\n\t\t\
    res.Max = max(Max, b.Max);\n\t\tres.sum = sum + b.sum;\n\t\treturn res;\n\t}\n\
    };\n\n// range mod, sum query\n// point assign query\nclass SegTreeBeats {\npublic:\n\
    \tvector<Node> tree;\n\n\tSegTreeBeats(int n): tree(4*n) {}\n\n\tvoid build(int\
    \ id, int l, int r, int u, int v, int val) {\n\t\tif (l > v || r < u) return;\n\
    \t\tif (u <= l && r <= v) {\n\t\t\ttree[id] = Node(val);\n\t\t\treturn;\n\t\t\
    }\n\t\tint mid = (l + r) >> 1;\n\t\tbuild(id*2, l, mid, u, v, val);\n\t\tbuild(id*2+1,\
    \ mid+1, r, u, v, val);\n\t\ttree[id] = tree[id*2] + tree[id*2+1];\n\t}\t\n\n\t\
    void updateMod(int id, int l, int r, int u, int v, int x) {\n\t\tif (l > v ||\
    \ r < u) return;\n\t\tif (tree[id].Max < x) return;\n\t\tif (l == r) {\n\t\t\t\
    tree[id].Max %= x;\n\t\t\ttree[id].sum = tree[id].Max;\n\t\t\treturn;\n\t\t}\n\
    \t\tint mid = (l + r) >> 1;\n\t\tupdateMod(id*2, l, mid, u, v, x);\n\t\tupdateMod(id*2+1,\
    \ mid+1, r, u, v, x);\n\t\ttree[id] = tree[id*2] + tree[id*2+1];\n\t}\n\n\tll\
    \ getSum(int id, int l, int r, int u, int v) {\n\t\tif (l > v || r < u) return\
    \ 0;\n\t\tif (u <= l && r <= v) return tree[id].sum;\n\t\tint mid = (l + r) >>\
    \ 1;\n\t\tll t1 = getSum(id*2, l, mid, u, v);\n\t\tll t2 = getSum(id*2+1, mid+1,\
    \ r, u, v);\n\t\treturn t1 + t2;\n\t}\n};\n#line 5 \"DataStructure/SegTree/SegTreeBeats/test1.cpp\"\
    \n\nvoid solve() {\n\tint n, m; cin >> n >> m;\n\tSegTreeBeats st(n);\n\tfor (int\
    \ i = 1; i <= n; i++) {\n\t\tint x; cin >> x;\n\t\tst.build(1, 1, n, i, i, x);\n\
    \t}\n\twhile (m--) {\n\t\tint type; cin >> type;\n\t\tif (type == 1) {\n\t\t\t\
    int l, r; cin >> l >> r;\n\t\t\tcout << st.getSum(1, 1, n, l, r) << '\\n';\n\t\
    \t} else if (type == 2) {\n\t\t\tint l, r, x; cin >> l >> r >> x;\n\t\t\tst.updateMod(1,\
    \ 1, n, l, r, x);\n\t\t} else if (type == 3) {\n\t\t\tint k, x; cin >> k >> x;\n\
    \t\t\tst.build(1, 1, n, k, k, x);\n\t\t}\n\t}\n}\n"
  code: "// https://codeforces.com/problemset/problem/438/D\n\n#include \"../../../template.h\"\
    \n#include \"SegTreeBeats1.h\"\n\nvoid solve() {\n\tint n, m; cin >> n >> m;\n\
    \tSegTreeBeats st(n);\n\tfor (int i = 1; i <= n; i++) {\n\t\tint x; cin >> x;\n\
    \t\tst.build(1, 1, n, i, i, x);\n\t}\n\twhile (m--) {\n\t\tint type; cin >> type;\n\
    \t\tif (type == 1) {\n\t\t\tint l, r; cin >> l >> r;\n\t\t\tcout << st.getSum(1,\
    \ 1, n, l, r) << '\\n';\n\t\t} else if (type == 2) {\n\t\t\tint l, r, x; cin >>\
    \ l >> r >> x;\n\t\t\tst.updateMod(1, 1, n, l, r, x);\n\t\t} else if (type ==\
    \ 3) {\n\t\t\tint k, x; cin >> k >> x;\n\t\t\tst.build(1, 1, n, k, k, x);\n\t\t\
    }\n\t}\n}"
  dependsOn:
  - template.h
  - DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h
  isVerificationFile: false
  path: DataStructure/SegTree/SegTreeBeats/test1.cpp
  requiredBy: []
  timestamp: '2025-05-07 22:18:34+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegTree/SegTreeBeats/test1.cpp
layout: document
redirect_from:
- /library/DataStructure/SegTree/SegTreeBeats/test1.cpp
- /library/DataStructure/SegTree/SegTreeBeats/test1.cpp.html
title: DataStructure/SegTree/SegTreeBeats/test1.cpp
---
