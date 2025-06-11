---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/SegTree/SegTreeBeats/test1.cpp
    title: DataStructure/SegTree/SegTreeBeats/test1.cpp
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
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h\"\n\n\n\
    struct Node {\n    ll Max, sum;\n\n    Node() {}\n\n    Node(int val) {\n    \
    \    Max = val;\n        sum = val;\n    }\n\n    Node operator+(const Node &b)\
    \ {\n        Node res;\n        res.Max = max(Max, b.Max);\n        res.sum =\
    \ sum + b.sum;\n        return res;\n    }\n};\n\n// range mod, sum query\n//\
    \ point assign query\nclass SegTreeBeats {\npublic:\n    vector<Node> tree;\n\n\
    \    SegTreeBeats(int n): tree(4*n) {}\n\n    void build(int id, int l, int r,\
    \ int u, int v, int val) {\n        if (l > v || r < u) return;\n        if (u\
    \ <= l && r <= v) {\n            tree[id] = Node(val);\n            return;\n\
    \        }\n        int mid = (l + r) >> 1;\n        build(id*2, l, mid, u, v,\
    \ val);\n        build(id*2+1, mid+1, r, u, v, val);\n        tree[id] = tree[id*2]\
    \ + tree[id*2+1];\n    }   \n\n    void updateMod(int id, int l, int r, int u,\
    \ int v, int x) {\n        if (l > v || r < u) return;\n        if (tree[id].Max\
    \ < x) return;\n        if (l == r) {\n            tree[id].Max %= x;\n      \
    \      tree[id].sum = tree[id].Max;\n            return;\n        }\n        int\
    \ mid = (l + r) >> 1;\n        updateMod(id*2, l, mid, u, v, x);\n        updateMod(id*2+1,\
    \ mid+1, r, u, v, x);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\n\n\
    \    ll getSum(int id, int l, int r, int u, int v) {\n        if (l > v || r <\
    \ u) return 0;\n        if (u <= l && r <= v) return tree[id].sum;\n        int\
    \ mid = (l + r) >> 1;\n        ll t1 = getSum(id*2, l, mid, u, v);\n        ll\
    \ t2 = getSum(id*2+1, mid+1, r, u, v);\n        return t1 + t2;\n    }\n};\n"
  code: "#include \"../../../template.h\"\n\n\nstruct Node {\n    ll Max, sum;\n\n\
    \    Node() {}\n\n    Node(int val) {\n        Max = val;\n        sum = val;\n\
    \    }\n\n    Node operator+(const Node &b) {\n        Node res;\n        res.Max\
    \ = max(Max, b.Max);\n        res.sum = sum + b.sum;\n        return res;\n  \
    \  }\n};\n\n// range mod, sum query\n// point assign query\nclass SegTreeBeats\
    \ {\npublic:\n    vector<Node> tree;\n\n    SegTreeBeats(int n): tree(4*n) {}\n\
    \n    void build(int id, int l, int r, int u, int v, int val) {\n        if (l\
    \ > v || r < u) return;\n        if (u <= l && r <= v) {\n            tree[id]\
    \ = Node(val);\n            return;\n        }\n        int mid = (l + r) >> 1;\n\
    \        build(id*2, l, mid, u, v, val);\n        build(id*2+1, mid+1, r, u, v,\
    \ val);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }   \n\n    void updateMod(int\
    \ id, int l, int r, int u, int v, int x) {\n        if (l > v || r < u) return;\n\
    \        if (tree[id].Max < x) return;\n        if (l == r) {\n            tree[id].Max\
    \ %= x;\n            tree[id].sum = tree[id].Max;\n            return;\n     \
    \   }\n        int mid = (l + r) >> 1;\n        updateMod(id*2, l, mid, u, v,\
    \ x);\n        updateMod(id*2+1, mid+1, r, u, v, x);\n        tree[id] = tree[id*2]\
    \ + tree[id*2+1];\n    }\n\n    ll getSum(int id, int l, int r, int u, int v)\
    \ {\n        if (l > v || r < u) return 0;\n        if (u <= l && r <= v) return\
    \ tree[id].sum;\n        int mid = (l + r) >> 1;\n        ll t1 = getSum(id*2,\
    \ l, mid, u, v);\n        ll t2 = getSum(id*2+1, mid+1, r, u, v);\n        return\
    \ t1 + t2;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h
  requiredBy:
  - DataStructure/SegTree/SegTreeBeats/test1.cpp
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h
- /library/DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h.html
title: DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h
---
