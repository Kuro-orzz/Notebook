---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/SegTree/SegTreeBeats2.h
    title: DataStructure/SegTree/SegTreeBeats2.h
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
  bundledCode: "#line 1 \"DataStructure/Problem/SegTreeBeats2.cpp\"\n// https://codeforces.com/group/1rv4rhCsHp/contest/327313/problem/B\n\
    \n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n \n\
    #define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/SegTreeBeats2.h\"\n\n\nstruct Node {\n\
    \    ll max1, max2, cntMax, sum, lazy;\n\n    Node() {}\n\n    Node(int val) {\n\
    \        max1 = val;\n        max2 = -1;\n        cntMax = 1;\n        sum = val;\n\
    \        lazy = -1;\n    }\n\n    Node operator+(const Node &b) {\n        Node\
    \ res;\n        res.max1 = max(max1, b.max1);\n        res.max2 = max(max2, b.max2);\n\
    \        if (res.max1 != max1) res.max2 = max(res.max2, max1);\n        if (res.max1\
    \ != b.max1) res.max2 = max(res.max2, b.max1); \n        res.cntMax = 0;\n   \
    \     if (res.max1 == max1) res.cntMax += cntMax;\n        if (res.max1 == b.max1)\
    \ res.cntMax += b.cntMax;\n        res.sum = sum + b.sum;\n        res.lazy =\
    \ -1;\n        return res;\n    }\n\n    void setMin(int val) {\n        if (val\
    \ > max1) return;\n        sum -= (max1 - val) * cntMax;\n        max1 = val;\n\
    \        lazy = val;\n    }\n};\n\n// range chmin, sum\nclass SegTreeBeats {\n\
    public:\n    vector<Node> tree;\n\n    SegTreeBeats(int n): tree(4*n) {}\n\n \
    \   void build(int id, int l, int r, int u, int v, int val) {\n        if (l >\
    \ v || r < u) return;\n        if (u <= l && r <= v) {\n            tree[id] =\
    \ Node(val);\n            return;\n        }\n        int mid = (l + r) >> 1;\n\
    \        build(id*2, l, mid, u, v, val);\n        build(id*2+1, mid+1, r, u, v,\
    \ val);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }   \n\n    void push(int\
    \ id) {\n        if (tree[id].lazy < 0) return;\n        tree[id*2].setMin(tree[id].lazy);\n\
    \        tree[id*2+1].setMin(tree[id].lazy);\n        tree[id].lazy = -1;\n  \
    \  }\n\n    void updateChmin(int id, int l, int r, int u, int v, int x) {\n  \
    \      if (l > v || r < u) return;\n        if (tree[id].max1 <= x) return;\n\
    \        if (u <= l && r <= v && tree[id].max2 < x) {\n            tree[id].setMin(x);\n\
    \            return;\n        }\n        push(id);\n        int mid = (l + r)\
    \ >> 1;\n        updateChmin(id*2, l, mid, u, v, x);\n        updateChmin(id*2+1,\
    \ mid+1, r, u, v, x);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\n\n\
    \    ll getSum(int id, int l, int r, int u, int v) {\n        if (l > v || r <\
    \ u) return 0;\n        if (u <= l && r <= v) return tree[id].sum;\n        push(id);\n\
    \        int mid = (l + r) >> 1;\n        ll t1 = getSum(id*2, l, mid, u, v);\n\
    \        ll t2 = getSum(id*2+1, mid+1, r, u, v);\n        return t1 + t2;\n  \
    \  }\n};\n#line 5 \"DataStructure/Problem/SegTreeBeats2.cpp\"\n\nvoid solve()\
    \ {\n    int n; cin >> n;\n    SegTreeBeats st(n+1);\n    for (int i = 1; i <=\
    \ n; i++) {\n        int x; cin >> x;\n        st.build(1, 1, n, i, i, x);\n \
    \   }\n    int q; cin >> q;\n    while (q--) {\n        int type; cin >> type;\n\
    \        if (type == 1) {\n            int l, r, x; cin >> l >> r >> x;\n    \
    \        st.updateChmin(1, 1, n, l, r, x);\n        } else if (type == 2) {\n\
    \            int l, r; cin >> l >> r;\n            cout << st.getSum(1, 1, n,\
    \ l, r) << '\\n';\n        }\n    }\n}\n"
  code: "// https://codeforces.com/group/1rv4rhCsHp/contest/327313/problem/B\n\n#include\
    \ \"../../template.h\"\n#include \"../SegTree/SegTreeBeats2.h\"\n\nvoid solve()\
    \ {\n    int n; cin >> n;\n    SegTreeBeats st(n+1);\n    for (int i = 1; i <=\
    \ n; i++) {\n        int x; cin >> x;\n        st.build(1, 1, n, i, i, x);\n \
    \   }\n    int q; cin >> q;\n    while (q--) {\n        int type; cin >> type;\n\
    \        if (type == 1) {\n            int l, r, x; cin >> l >> r >> x;\n    \
    \        st.updateChmin(1, 1, n, l, r, x);\n        } else if (type == 2) {\n\
    \            int l, r; cin >> l >> r;\n            cout << st.getSum(1, 1, n,\
    \ l, r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/SegTree/SegTreeBeats2.h
  isVerificationFile: false
  path: DataStructure/Problem/SegTreeBeats2.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Problem/SegTreeBeats2.cpp
layout: document
redirect_from:
- /library/DataStructure/Problem/SegTreeBeats2.cpp
- /library/DataStructure/Problem/SegTreeBeats2.cpp.html
title: DataStructure/Problem/SegTreeBeats2.cpp
---
