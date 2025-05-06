---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree/SegTreeBeats/SegTreeBeats3.h
    title: DataStructure/SegTree/SegTreeBeats/SegTreeBeats3.h
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"DataStructure/Range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    \ \n#define vi vector<int>\n#define pii pair<int, int>\n#define fi first\n#define\
    \ se second\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"DataStructure/SegTree/SegTreeBeats/SegTreeBeats3.h\"\
    \n\n\nstruct Node {\n\tll max1, max2, cntMax, min1, min2, cntMin, sum, lazy, sz;\n\
    \n\tNode() {\n\t\tmax1 = max2 = -1e18;\n\t\tmin1 = min2 = 1e18;\n\t\tcntMax =\
    \ cntMin = 0;\n\t\tsum = lazy = sz = 0;\n\t}\n\n\tNode(ll val) {\n\t\tmax1 = min1\
    \ = val;\n\t\tmax2 = -1e18;\n\t\tmin2 = 1e18;\n\t\tcntMax = cntMin = 1;\n\t\t\
    sum = val;\n\t\tlazy = 0;\n\t\tsz = 1;\n\t}\n\n\tNode operator+(const Node &b)\
    \ {\n\t\tNode res;\n\n\t\tres.max1 = max(max1, b.max1);\n\t\tres.max2 = max(max2,\
    \ b.max2);\n\t\tif (res.max1 != max1) res.max2 = max(res.max2, max1);\n\t\tif\
    \ (res.max1 != b.max1) res.max2 = max(res.max2, b.max1); \n\t\tres.cntMax = 0;\n\
    \t\tif (res.max1 == max1) res.cntMax += cntMax;\n\t\tif (res.max1 == b.max1) res.cntMax\
    \ += b.cntMax;\n\n\t\tres.min1 = min(min1, b.min1);\n\t\tres.min2 = min(min2,\
    \ b.min2);\n\t\tif (res.min1 != min1) res.min2 = min(res.min2, min1);\n\t\tif\
    \ (res.min1 != b.min1) res.min2 = min(res.min2, b.min1);\n\t\tres.cntMin = 0;\n\
    \t\tif (res.min1 == min1) res.cntMin += cntMin;\n\t\tif (res.min1 == b.min1) res.cntMin\
    \ += b.cntMin;\n\n\t\tres.sum = sum + b.sum;\n\t\tres.lazy = 0;\n\t\tres.sz =\
    \ sz + b.sz;\n\n\t\treturn res;\n\t}\n\n\tvoid setMin(ll x) {\n\t\tif (x >= max1)\
    \ return;\n\t\tsum -= (max1 - x) * cntMax;\n\t\tmax1 = x;\n\t\tmin1 = min(min1,\
    \ x);\n\t\tif (min2 != 1e18) min2 = min(min2, x);\n\t}\n\n\tvoid setMax(ll x)\
    \ {\n\t\tif (x <= min1) return;\n\t\tsum += (x-min1) * cntMin;\n\t\tmin1 = x;\n\
    \t\tmax1 = max(max1, x);\n\t\tif (max2 != -1e18) max2 = max(max2, x);\n\t}\n\n\
    \tvoid add(ll x) {\n\t\tmax1 += x;\n\t\tmin1 += x;\n\t\tif (max2 != -1e18) max2\
    \ += x;\n\t\tif (min2 != 1e18) min2 += x;\n\t\tsum += x * sz;\n\t\tlazy += x;\n\
    \t}\n};\n\n// range chmin, chmax, update range, sum\nclass SegTreeBeats {\npublic:\n\
    \tvector<Node> tree;\n\n\tSegTreeBeats(int n): tree(4*n+6) {}\n\n\tvoid build(int\
    \ id, int l, int r, int pos, ll val) {\n\t\tif (pos < l || pos > r) return;\n\t\
    \tif (l == r) {\n\t\t\ttree[id] = Node(val);\n\t\t\treturn;\n\t\t}\n\t\tint mid\
    \ = (l + r) >> 1;\n\t\tbuild(id*2, l, mid, pos, val);\n\t\tbuild(id*2+1, mid+1,\
    \ r, pos, val);\n\t\ttree[id] = tree[id*2] + tree[id*2+1];\n\t}\t\n\n\tvoid push(int\
    \ id) {\n\t\ttree[id*2].add(tree[id].lazy);\n\t\ttree[id*2+1].add(tree[id].lazy);\n\
    \t\ttree[id].lazy = 0;\n\t\t\n\t\ttree[id*2].setMax(tree[id].min1);\n\t\ttree[id*2+1].setMax(tree[id].min1);\n\
    \n\t\ttree[id*2].setMin(tree[id].max1);\n\t\ttree[id*2+1].setMin(tree[id].max1);\n\
    \t}\n\n\tvoid updateChmax(int id, int l, int r, int u, int v, ll x) {\n\t\tif\
    \ (l > v || r < u) return;\n\t\tif (tree[id].min1 >= x) return;\n\t\tif (u <=\
    \ l && r <= v && tree[id].min2 > x) {\n\t\t\ttree[id].setMax(x);\n\t\t\treturn;\n\
    \t\t}\n\t\tpush(id);\n\t\tint mid = (l + r) >> 1;\n\t\tupdateChmax(id*2, l, mid,\
    \ u, v, x);\n\t\tupdateChmax(id*2+1, mid+1, r, u, v, x);\n\t\ttree[id] = tree[id*2]\
    \ + tree[id*2+1];\n\t}\n\t\n\tvoid updateChmin(int id, int l, int r, int u, int\
    \ v, ll x) {\n\t\tif (l > v || r < u) return;\n\t\tif (tree[id].max1 <= x) return;\n\
    \t\tif (u <= l && r <= v && tree[id].max2 < x) {\n\t\t\ttree[id].setMin(x);\n\t\
    \t\treturn;\n\t\t}\n\t\tpush(id);\n\t\tint mid = (l + r) >> 1;\n\t\tupdateChmin(id*2,\
    \ l, mid, u, v, x);\n\t\tupdateChmin(id*2+1, mid+1, r, u, v, x);\n\t\ttree[id]\
    \ = tree[id*2] + tree[id*2+1];\n\t}\n\n\tvoid updateRange(int id, int l, int r,\
    \ int u, int v, ll x) {\n\t\tif (l > v || r < u) return;\n\t\tif (u <= l && r\
    \ <= v) {\n\t\t\ttree[id].add(x);\n\t\t\treturn;\n\t\t}\n\t\tpush(id);\n\t\tint\
    \ mid = (l + r) >> 1;\n\t\tupdateRange(id*2, l, mid, u, v, x);\n\t\tupdateRange(id*2+1,\
    \ mid+1, r, u, v, x);\n\t\ttree[id] = tree[id*2] + tree[id*2+1];\n\t}\n\n\tll\
    \ getSum(int id, int l, int r, int u, int v) {\n\t\tif (l > v || r < u) return\
    \ 0;\n\t\tif (u <= l && r <= v) return tree[id].sum;\n\t\tpush(id);\n\t\tint mid\
    \ = (l + r) >> 1;\n\t\tll t1 = getSum(id*2, l, mid, u, v);\n\t\tll t2 = getSum(id*2+1,\
    \ mid+1, r, u, v);\n\t\treturn t1 + t2;\n\t}\n};\n#line 5 \"DataStructure/Range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\nvoid solve() {\n\tint n, q; cin >> n >> q;\n\tSegTreeBeats st(n);\n\tfor (int\
    \ i = 1; i <= n; i++) {\n\t\tll x; cin >> x;\n\t\tst.build(1, 1, n, i, x);\n\t\
    }\n\twhile (q--) {\n\t\tint type, l, r; cin >> type >> l >> r;\n\t\tif (type ==\
    \ 0) {\n\t\t\tll b; cin >> b;\n\t\t\tst.updateChmin(1, 1, n, l+1, r, b);\n\t\t\
    } else if (type == 1) {\n\t\t\tll b; cin >> b;\n\t\t\tst.updateChmax(1, 1, n,\
    \ l+1, r, b);\n\t\t} else if (type == 2) {\n\t\t\tll b; cin >> b;\n\t\t\tst.updateRange(1,\
    \ 1, n, l+1, r, b);\n\t\t} else if (type == 3) {\n\t\t\tcout << st.getSum(1, 1,\
    \ n, l+1, r) << '\\n';\n\t\t}\t\t\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include \"../template.h\"\n#include \"SegTree/SegTreeBeats/SegTreeBeats3.h\"\
    \n\nvoid solve() {\n\tint n, q; cin >> n >> q;\n\tSegTreeBeats st(n);\n\tfor (int\
    \ i = 1; i <= n; i++) {\n\t\tll x; cin >> x;\n\t\tst.build(1, 1, n, i, x);\n\t\
    }\n\twhile (q--) {\n\t\tint type, l, r; cin >> type >> l >> r;\n\t\tif (type ==\
    \ 0) {\n\t\t\tll b; cin >> b;\n\t\t\tst.updateChmin(1, 1, n, l+1, r, b);\n\t\t\
    } else if (type == 1) {\n\t\t\tll b; cin >> b;\n\t\t\tst.updateChmax(1, 1, n,\
    \ l+1, r, b);\n\t\t} else if (type == 2) {\n\t\t\tll b; cin >> b;\n\t\t\tst.updateRange(1,\
    \ 1, n, l+1, r, b);\n\t\t} else if (type == 3) {\n\t\t\tcout << st.getSum(1, 1,\
    \ n, l+1, r) << '\\n';\n\t\t}\t\t\n\t}\n}"
  dependsOn:
  - template.h
  - DataStructure/SegTree/SegTreeBeats/SegTreeBeats3.h
  isVerificationFile: true
  path: DataStructure/Range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-05-06 20:15:37+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Range_chmin_chmax_add_range_sum.test.cpp
- /verify/DataStructure/Range_chmin_chmax_add_range_sum.test.cpp.html
title: DataStructure/Range_chmin_chmax_add_range_sum.test.cpp
---
