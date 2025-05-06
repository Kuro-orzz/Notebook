---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree/Affline.h
    title: DataStructure/SegTree/Affline.h
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"DataStructure/Range_affine_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#line\
    \ 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define\
    \ ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\
    #define vi vector<int>\n#define pii pair<int, int>\n#define pll pair<ll, ll>\n\
    #define fi first\n#define se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\
    \nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/Affline.h\"\n\ntemplate <typename T>\n\
    struct AfflineSegTree {\n\tvector<T> st;\n    vector<pll> lazy;\n\n    AfflineSegTree()\
    \ {}\n    AfflineSegTree(int n): st(n*4), lazy(n*4) {}\n\n    void build(int id,\
    \ int l, int r, const vector<ll> &a) {\n        lazy[id] = {1, 0};\n        if\
    \ (l == r) {\n            st[id] = a[l] % mod;\n            return;\n        }\n\
    \        int m = (l + r) >> 1;\n        build(id*2, l, m, a);\n        build(id*2+1,\
    \ m+1, r, a);\n        st[id] = (st[id*2] + st[id*2+1]) % mod;\n    }\n\n    void\
    \ push(int id, int l, int r) {\n        if (lazy[id] == make_pair(1ll*1, 1ll*0))\
    \ return;\n        int m = (l + r) >> 1;\n        st[id*2] = st[id*2] * lazy[id].fi\
    \ % mod + lazy[id].se * (m-l+1) % mod;\n        st[id*2] %= mod;\n        st[id*2+1]\
    \ = st[id*2+1] * lazy[id].fi % mod + lazy[id].se * (r-m) % mod;\n        st[id*2+1]\
    \ %= mod;\n        setLazy(id*2, lazy[id]);\n        setLazy(id*2+1, lazy[id]);\n\
    \        lazy[id] = {1, 0};\n    }\n\n    void setLazy(int id, pll val) {\n  \
    \      lazy[id].fi = lazy[id].fi * val.fi % mod;\n        lazy[id].se = (lazy[id].se\
    \ * val.fi % mod + val.se) % mod;\n    }\n\n    void update(int id, int l, int\
    \ r, int u, int v, pll val) {\n        if (v < l || u > r)\n            return;\n\
    \        if (u <= l && v >= r) {\n            st[id] = (st[id] * val.fi % mod\
    \ + val.se * (r-l+1) % mod) % mod;\n            setLazy(id, val);\n          \
    \  return;\n        }\n        push(id, l, r);\n        int mid = (l + r) >> 1;\n\
    \        update(id*2, l, mid, u, v, val);\n        update(id*2+1, mid+1, r, u,\
    \ v, val);\n        st[id] = (st[id*2] + st[id*2+1]) % mod;\n    }\n\n    T getSumMod(int\
    \ id, int l, int r, int u, int v) {\n        if (l > v || r < u) return 0;\n \
    \       if (l >= u && r <= v) return st[id];\n        int mid = (l + r) >> 1;\n\
    \        push(id, l, r);\n        T t1 = getSumMod(id*2, l, mid, u, v) % mod;\n\
    \        T t2 = getSumMod(id*2+1, mid+1, r, u, v) % mod;\n        return (t1 +\
    \ t2) % mod;\n    }\n};\n#line 5 \"DataStructure/Range_affine_range_sum.test.cpp\"\
    \n\nvoid solve() {\n\tint n, q; cin >> n >> q;\n\tvector<ll> a(n+1);\n\tfor (int\
    \ i = 1; i <= n; i++) {\n\t\tcin >> a[i];\n\t}\n\tAfflineSegTree<ll> st(n);\n\t\
    st.build(1, 1, n, a);\n\twhile (q--) {\n\t\tint tv, l, r; cin >> tv >> l >> r;\n\
    \t\tif (tv == 0) {\n\t\t\tll b, c; cin >> b >> c;\n\t\t\tst.update(1, 1, n, l+1,\
    \ r, make_pair(b, c));\n\t\t} else if (tv == 1) {\n\t\t\tcout << st.getSumMod(1,\
    \ 1, n, l+1, r) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../template.h\"\n#include \"SegTree/Affline.h\"\n\nvoid solve()\
    \ {\n\tint n, q; cin >> n >> q;\n\tvector<ll> a(n+1);\n\tfor (int i = 1; i <=\
    \ n; i++) {\n\t\tcin >> a[i];\n\t}\n\tAfflineSegTree<ll> st(n);\n\tst.build(1,\
    \ 1, n, a);\n\twhile (q--) {\n\t\tint tv, l, r; cin >> tv >> l >> r;\n\t\tif (tv\
    \ == 0) {\n\t\t\tll b, c; cin >> b >> c;\n\t\t\tst.update(1, 1, n, l+1, r, make_pair(b,\
    \ c));\n\t\t} else if (tv == 1) {\n\t\t\tcout << st.getSumMod(1, 1, n, l+1, r)\
    \ << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - template.h
  - DataStructure/SegTree/Affline.h
  isVerificationFile: true
  path: DataStructure/Range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-05-06 22:56:49+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Range_affine_range_sum.test.cpp
- /verify/DataStructure/Range_affine_range_sum.test.cpp.html
title: DataStructure/Range_affine_range_sum.test.cpp
---
