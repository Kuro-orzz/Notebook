---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: DataStructure/Range_affine_range_sum.test.cpp
    title: DataStructure/Range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\
    #define vi vector<int>\n#define pii pair<int, int>\n#define pll pair<ll, ll>\n\
    #define fi first\n#define se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\
    \nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/Affline.h\"\n\ntemplate <typename T>\n\
    struct AfflineSegTree {\n\tvector<T> st;\n    vector<pll> lazy;\n\n    AfflineSegTree()\
    \ {}\n    AfflineSegTree(int n): st(n*4), lazy(n*4) {}\n\n    void push(int id)\
    \ {\n        if (lazy[id] == make_pair(1ll*0, 1ll*0)) return;\n        st[id*2]\
    \ = st[id*2] * lazy[id].fi + lazy[id].se;\n        st[id*2+1] = st[id*2+1] * lazy[id].fi\
    \ + lazy[id].se;\n        setLazy(id*2, lazy[id]);\n        setLazy(id*2+1, lazy[id]);\n\
    \        lazy[id] = {0, 0};\n    }\n\n    void setLazy(int id, pll val) {\n  \
    \      if (lazy[id] == make_pair(1ll*0, 1ll*0)) lazy[id] = val;\n        else\
    \ {\n            lazy[id].fi *= val.fi;\n            lazy[id].se = lazy[id].se*val.fi\
    \ + val.se;\n        }\n    }\n\n    void update(int id, int l, int r, int u,\
    \ int v, pll val) {\n        if (v < l || u > r)\n            return;\n      \
    \  if (u <= l && v >= r) {\n            st[id] = st[id] * val.fi + val.se;\n \
    \           setLazy(id, val);\n            return;\n        }\n        push(id);\n\
    \        int mid = (l + r) >> 1;\n        update(id*2, l, mid, u, v, val);\n \
    \       update(id*2+1, mid+1, r, u, v, val);\n        st[id] = st[id*2] + st[id*2+1];\n\
    \    }\n\n    T getSum(int id, int l, int r, int u, int v) {\n        if (l >\
    \ v || r < u) return 0;\n        if (l >= u && r <= v) return st[id];\n      \
    \  int mid = (l + r) >> 1;\n        push(id);\n        T t1 = getSum(id*2, l,\
    \ mid, u, v);\n        T t2 = getSum(id*2+1, mid+1, r, u, v);\n        return\
    \ t1 + t2;\n    }\n\n    T getSumMod(int id, int l, int r, int u, int v) {\n \
    \       if (l > v || r < u) return 0;\n        if (l >= u && r <= v) return st[id];\n\
    \        int mid = (l + r) >> 1;\n        push(id);\n        T t1 = getSum(id*2,\
    \ l, mid, u, v) % mod;\n        T t2 = getSum(id*2+1, mid+1, r, u, v) % mod;\n\
    \        return (t1 + t2) % mod;\n    }\n};\n"
  code: "#include \"../../template.h\"\n\ntemplate <typename T>\nstruct AfflineSegTree\
    \ {\n\tvector<T> st;\n    vector<pll> lazy;\n\n    AfflineSegTree() {}\n    AfflineSegTree(int\
    \ n): st(n*4), lazy(n*4) {}\n\n    void push(int id) {\n        if (lazy[id] ==\
    \ make_pair(1ll*0, 1ll*0)) return;\n        st[id*2] = st[id*2] * lazy[id].fi\
    \ + lazy[id].se;\n        st[id*2+1] = st[id*2+1] * lazy[id].fi + lazy[id].se;\n\
    \        setLazy(id*2, lazy[id]);\n        setLazy(id*2+1, lazy[id]);\n      \
    \  lazy[id] = {0, 0};\n    }\n\n    void setLazy(int id, pll val) {\n        if\
    \ (lazy[id] == make_pair(1ll*0, 1ll*0)) lazy[id] = val;\n        else {\n    \
    \        lazy[id].fi *= val.fi;\n            lazy[id].se = lazy[id].se*val.fi\
    \ + val.se;\n        }\n    }\n\n    void update(int id, int l, int r, int u,\
    \ int v, pll val) {\n        if (v < l || u > r)\n            return;\n      \
    \  if (u <= l && v >= r) {\n            st[id] = st[id] * val.fi + val.se;\n \
    \           setLazy(id, val);\n            return;\n        }\n        push(id);\n\
    \        int mid = (l + r) >> 1;\n        update(id*2, l, mid, u, v, val);\n \
    \       update(id*2+1, mid+1, r, u, v, val);\n        st[id] = st[id*2] + st[id*2+1];\n\
    \    }\n\n    T getSum(int id, int l, int r, int u, int v) {\n        if (l >\
    \ v || r < u) return 0;\n        if (l >= u && r <= v) return st[id];\n      \
    \  int mid = (l + r) >> 1;\n        push(id);\n        T t1 = getSum(id*2, l,\
    \ mid, u, v);\n        T t2 = getSum(id*2+1, mid+1, r, u, v);\n        return\
    \ t1 + t2;\n    }\n\n    T getSumMod(int id, int l, int r, int u, int v) {\n \
    \       if (l > v || r < u) return 0;\n        if (l >= u && r <= v) return st[id];\n\
    \        int mid = (l + r) >> 1;\n        push(id);\n        T t1 = getSum(id*2,\
    \ l, mid, u, v) % mod;\n        T t2 = getSum(id*2+1, mid+1, r, u, v) % mod;\n\
    \        return (t1 + t2) % mod;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/Affline.h
  requiredBy: []
  timestamp: '2025-05-06 22:27:53+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - DataStructure/Range_affine_range_sum.test.cpp
documentation_of: DataStructure/SegTree/Affline.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/Affline.h
- /library/DataStructure/SegTree/Affline.h.html
title: DataStructure/SegTree/Affline.h
---
