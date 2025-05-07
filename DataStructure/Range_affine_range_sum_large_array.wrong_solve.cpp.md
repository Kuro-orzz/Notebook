---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree/Affline.h
    title: DataStructure/SegTree/Affline.h
  - icon: ':warning:'
    path: Misc/Compress.h
    title: Misc/Compress.h
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
    - https://judge.yosupo.jp/problem/range_affine_range_sum_large_array
  bundledCode: "#line 1 \"DataStructure/Range_affine_range_sum_large_array.wrong_solve.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum_large_array\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Misc/Compress.h\"\n\ntemplate <typename T>\nstruct Compress\
    \ {\n\tint cnt = 1;\n\tmap<T, int> compressed;\n\tvector<T> decompress;\n\n\t\
    Compress(const vector<T> &a) {\n\t\tdecompress.push_back(T(0));\n\t\tvector<T>\
    \ b = a;\n\t\tsort(all(b));\n        unique(b);\n\t\tfor (T x : b) {\n\t\t\tcompressed[x]\
    \ = cnt++;\n\t\t\tdecompress.push_back(x);\n\t\t}\n\t}\n};\n#line 2 \"DataStructure/SegTree/Affline.h\"\
    \n\ntemplate <typename T>\nstruct AfflineSegTree {\n    vector<T> st;\n    vector<pll>\
    \ lazy;\n\n    AfflineSegTree() {}\n    AfflineSegTree(int n): st(n*4), lazy(n*4)\
    \ {}\n\n    void build(int id, int l, int r, const vector<ll> &a) {\n        lazy[id]\
    \ = {1, 0};\n        if (l == r) {\n            st[id] = a[l] % mod;\n       \
    \     return;\n        }\n        int m = (l + r) >> 1;\n        build(id*2, l,\
    \ m, a);\n        build(id*2+1, m+1, r, a);\n        st[id] = (st[id*2] + st[id*2+1])\
    \ % mod;\n    }\n\n    void push(int id, int l, int r) {\n        if (lazy[id]\
    \ == make_pair(1ll*1, 1ll*0)) return;\n        int m = (l + r) >> 1;\n       \
    \ apply(id*2, l, m, lazy[id]);\n        apply(id*2+1, m+1, r, lazy[id]);\n   \
    \     lazy[id] = {1, 0};\n    }\n\n    void apply(int id, int l, int r, pll val)\
    \ {\n        int len = r-l+1;\n        st[id] = (st[id] * val.fi % mod + val.se\
    \ * len % mod) % mod;\n        lazy[id].fi = lazy[id].fi * val.fi % mod;\n   \
    \     lazy[id].se = (lazy[id].se * val.fi % mod + val.se) % mod;\n    }\n\n  \
    \  void update(int id, int l, int r, int u, int v, pll val) {\n        if (v <\
    \ l || u > r)\n            return;\n        if (u <= l && v >= r) {\n        \
    \    apply(id, l, r, val);\n            return;\n        }\n        push(id, l,\
    \ r);\n        int mid = (l + r) >> 1;\n        update(id*2, l, mid, u, v, val);\n\
    \        update(id*2+1, mid+1, r, u, v, val);\n        st[id] = (st[id*2] + st[id*2+1])\
    \ % mod;\n    }\n\n    T getSumMod(int id, int l, int r, int u, int v) {\n   \
    \     if (l > v || r < u) return 0;\n        if (l >= u && r <= v) return st[id];\n\
    \        int mid = (l + r) >> 1;\n        push(id, l, r);\n        T t1 = getSumMod(id*2,\
    \ l, mid, u, v) % mod;\n        T t2 = getSumMod(id*2+1, mid+1, r, u, v) % mod;\n\
    \        return (t1 + t2) % mod;\n    }\n};\n#line 6 \"DataStructure/Range_affine_range_sum_large_array.wrong_solve.cpp\"\
    \n\nstruct Query {\n\tll tv, l, r, b, c;\n};\n\nvoid solve() {\n\tint n, q; cin\
    \ >> n >> q;\n\tvector<Query> a;\n\tfor (int i = 0; i < q; i++) {\n\t\tQuery x;\n\
    \t\tcin >> x.tv >> x.l >> x.r;\n\t\tif (x.tv == 0) cin >> x.b >> x.c;\n\t\tx.l++;\n\
    \t\ta.push_back(x);\n\t}\n\tvector<ll> v;\n\tfor (Query it : a) {\n\t\tv.push_back(it.l);\n\
    \t\tv.push_back(it.r);\n\t\tv.push_back(it.r+1);\n\t}\n\tCompress<ll> query(v);\n\
    \tn = (int)query.decompress.size()-1;\n\tAfflineSegTree<ll> st(n, query.decompress);\n\
    \tfor (int i = 0; i < q; i++) {\n\t\tint l = query.compressed[a[i].l];\n\t\tint\
    \ r = query.compressed[a[i].r]-1;\n\t\tif (a[i].tv == 0) {\n\t\t\tst.update(1,\
    \ 1, n, l, r, make_pair(a[i].b, a[i].c));\n\t\t} else if (a[i].tv == 1) {\n\t\t\
    \tcout << st.getSumMod(1, 1, n, l, r) << '\\n';\n\t\t}\n\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum_large_array\"\
    \n\n#include \"../template.h\"\n#include \"../Misc/Compress.h\"\n#include \"SegTree/Affline.h\"\
    \n\nstruct Query {\n\tll tv, l, r, b, c;\n};\n\nvoid solve() {\n\tint n, q; cin\
    \ >> n >> q;\n\tvector<Query> a;\n\tfor (int i = 0; i < q; i++) {\n\t\tQuery x;\n\
    \t\tcin >> x.tv >> x.l >> x.r;\n\t\tif (x.tv == 0) cin >> x.b >> x.c;\n\t\tx.l++;\n\
    \t\ta.push_back(x);\n\t}\n\tvector<ll> v;\n\tfor (Query it : a) {\n\t\tv.push_back(it.l);\n\
    \t\tv.push_back(it.r);\n\t\tv.push_back(it.r+1);\n\t}\n\tCompress<ll> query(v);\n\
    \tn = (int)query.decompress.size()-1;\n\tAfflineSegTree<ll> st(n, query.decompress);\n\
    \tfor (int i = 0; i < q; i++) {\n\t\tint l = query.compressed[a[i].l];\n\t\tint\
    \ r = query.compressed[a[i].r]-1;\n\t\tif (a[i].tv == 0) {\n\t\t\tst.update(1,\
    \ 1, n, l, r, make_pair(a[i].b, a[i].c));\n\t\t} else if (a[i].tv == 1) {\n\t\t\
    \tcout << st.getSumMod(1, 1, n, l, r) << '\\n';\n\t\t}\n\n\t}\n}"
  dependsOn:
  - template.h
  - Misc/Compress.h
  - DataStructure/SegTree/Affline.h
  isVerificationFile: false
  path: DataStructure/Range_affine_range_sum_large_array.wrong_solve.cpp
  requiredBy: []
  timestamp: '2025-05-07 22:18:34+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Range_affine_range_sum_large_array.wrong_solve.cpp
layout: document
redirect_from:
- /library/DataStructure/Range_affine_range_sum_large_array.wrong_solve.cpp
- /library/DataStructure/Range_affine_range_sum_large_array.wrong_solve.cpp.html
title: DataStructure/Range_affine_range_sum_large_array.wrong_solve.cpp
---
