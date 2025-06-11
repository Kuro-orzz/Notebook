---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree/SegTree.h
    title: DataStructure/SegTree/SegTree.h
  - icon: ':question:'
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
  bundledCode: "#line 1 \"DataStructure/Point_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 2 \"template.h\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n\
    #define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64\
    \ ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n#define pii\
    \ pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define se second\n\
    \nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"DataStructure/SegTree/SegTree.h\"\
    \n\ntemplate <typename T>\nstruct SegTree {\n    int n;\n    vector<T> tree;\n\
    \n    SegTree() {}\n    SegTree(int _n): n(_n), tree(_n*4) {}\n\n    void update(int\
    \ pos, T val) {\n        update(1, 1, n, pos, val);\n    }\n\n    T getSum(int\
    \ u, int v) {\n        return getSum(1, 1, n, u, v);\n    }\n\n    void update(int\
    \ id, int l, int r, int pos, T val) {\n        if (pos < l || pos > r) return;\n\
    \        if (l == r) {\n            tree[id] += val;\n            return;\n  \
    \      }\n        int mid = (l + r) >> 1;\n        update(id*2, l, mid, pos, val);\n\
    \        update(id*2+1, mid+1, r, pos, val);\n        tree[id] = tree[id*2] +\
    \ tree[id*2+1];\n    }\n\n    T getSum(int id, int l, int r, int u, int v) {\n\
    \        if (l > v || r < u) return 0;\n        if (l >= u && r <= v) return tree[id];\n\
    \        int mid = (l + r) >> 1;\n        T t1 = getSum(id*2, l, mid, u, v);\n\
    \        T t2 = getSum(id*2+1, mid+1, r, u, v);\n        return t1 + t2;\n   \
    \ }\n};\n#line 5 \"DataStructure/Point_add_range_sum.test.cpp\"\n\nvoid solve()\
    \ {\n    int n, q; cin >> n >> q;\n    SegTree<ll> segTree(n);\n    for (int i\
    \ = 1; i <= n; i++) {\n        int x; cin >> x;\n        segTree.update(1, 1,\
    \ n, i, x);\n    }\n    while (q--) {\n        int tv; cin >> tv;\n        if\
    \ (tv == 0) {\n            int pos, val; cin >> pos >> val;\n            segTree.update(1,\
    \ 1, n, pos+1, val);\n        } else {\n            int l, r; cin >> l >> r;\n\
    \            cout << segTree.getSum(1, 1, n, l+1, r) << '\\n';\n        }\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../template.h\"\n#include \"SegTree/SegTree.h\"\n\nvoid solve() {\n\
    \    int n, q; cin >> n >> q;\n    SegTree<ll> segTree(n);\n    for (int i = 1;\
    \ i <= n; i++) {\n        int x; cin >> x;\n        segTree.update(1, 1, n, i,\
    \ x);\n    }\n    while (q--) {\n        int tv; cin >> tv;\n        if (tv ==\
    \ 0) {\n            int pos, val; cin >> pos >> val;\n            segTree.update(1,\
    \ 1, n, pos+1, val);\n        } else {\n            int l, r; cin >> l >> r;\n\
    \            cout << segTree.getSum(1, 1, n, l+1, r) << '\\n';\n        }\n  \
    \  }\n}"
  dependsOn:
  - template.h
  - DataStructure/SegTree/SegTree.h
  isVerificationFile: true
  path: DataStructure/Point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Point_add_range_sum.test.cpp
- /verify/DataStructure/Point_add_range_sum.test.cpp.html
title: DataStructure/Point_add_range_sum.test.cpp
---
