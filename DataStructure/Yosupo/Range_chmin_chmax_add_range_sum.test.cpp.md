---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree/SegTreeBeats3.h
    title: DataStructure/SegTree/SegTreeBeats3.h
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"DataStructure/Yosupo/Range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/SegTreeBeats3.h\"\n\n\nstruct Node {\n\
    \    ll max1, max2, cntMax, min1, min2, cntMin, sum, lazy, sz;\n\n    Node() {\n\
    \        max1 = max2 = -inf;\n        min1 = min2 = inf;\n        cntMax = cntMin\
    \ = 0;\n        sum = lazy = sz = 0;\n    }\n\n    Node(ll val) {\n        max1\
    \ = min1 = val;\n        max2 = -inf;\n        min2 = inf;\n        cntMax = cntMin\
    \ = 1;\n        sum = val;\n        lazy = 0;\n        sz = 1;\n    }\n\n    Node\
    \ operator+(const Node &b) {\n        Node res;\n\n        res.max1 = max(max1,\
    \ b.max1);\n        res.max2 = max(max2, b.max2);\n        if (res.max1 != max1)\
    \ res.max2 = max(res.max2, max1);\n        if (res.max1 != b.max1) res.max2 =\
    \ max(res.max2, b.max1); \n        res.cntMax = 0;\n        if (res.max1 == max1)\
    \ res.cntMax += cntMax;\n        if (res.max1 == b.max1) res.cntMax += b.cntMax;\n\
    \n        res.min1 = min(min1, b.min1);\n        res.min2 = min(min2, b.min2);\n\
    \        if (res.min1 != min1) res.min2 = min(res.min2, min1);\n        if (res.min1\
    \ != b.min1) res.min2 = min(res.min2, b.min1);\n        res.cntMin = 0;\n    \
    \    if (res.min1 == min1) res.cntMin += cntMin;\n        if (res.min1 == b.min1)\
    \ res.cntMin += b.cntMin;\n\n        res.sum = sum + b.sum;\n        res.lazy\
    \ = 0;\n        res.sz = sz + b.sz;\n\n        return res;\n    }\n\n    void\
    \ setMin(ll x) {\n        if (x >= max1) return;\n        sum -= (max1 - x) *\
    \ cntMax;\n        max1 = x;\n        min1 = min(min1, x);\n        if (min2 !=\
    \ inf) min2 = min(min2, x);\n    }\n\n    void setMax(ll x) {\n        if (x <=\
    \ min1) return;\n        sum += (x-min1) * cntMin;\n        min1 = x;\n      \
    \  max1 = max(max1, x);\n        if (max2 != -inf) max2 = max(max2, x);\n    }\n\
    \n    void add(ll x) {\n        max1 += x;\n        min1 += x;\n        if (max2\
    \ != -inf) max2 += x;\n        if (min2 != inf) min2 += x;\n        sum += x *\
    \ sz;\n        lazy += x;\n    }\n};\n\n// range chmin, chmax, update range, sum\n\
    class SegTreeBeats {\npublic:\n    vector<Node> tree;\n\n    SegTreeBeats(int\
    \ n): tree(4*n+6) {}\n\n    void build(int id, int l, int r, int pos, ll val)\
    \ {\n        if (pos < l || pos > r) return;\n        if (l == r) {\n        \
    \    tree[id] = Node(val);\n            return;\n        }\n        int mid =\
    \ (l + r) >> 1;\n        build(id*2, l, mid, pos, val);\n        build(id*2+1,\
    \ mid+1, r, pos, val);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    } \
    \  \n\n    void push(int id) {\n        tree[id*2].add(tree[id].lazy);\n     \
    \   tree[id*2+1].add(tree[id].lazy);\n        tree[id].lazy = 0;\n\n        tree[id*2].setMax(tree[id].min1);\n\
    \        tree[id*2+1].setMax(tree[id].min1);\n\n        tree[id*2].setMin(tree[id].max1);\n\
    \        tree[id*2+1].setMin(tree[id].max1);\n    }\n\n    void updateChmax(int\
    \ id, int l, int r, int u, int v, ll x) {\n        if (l > v || r < u) return;\n\
    \        if (tree[id].min1 >= x) return;\n        if (u <= l && r <= v && tree[id].min2\
    \ > x) {\n            tree[id].setMax(x);\n            return;\n        }\n  \
    \      push(id);\n        int mid = (l + r) >> 1;\n        updateChmax(id*2, l,\
    \ mid, u, v, x);\n        updateChmax(id*2+1, mid+1, r, u, v, x);\n        tree[id]\
    \ = tree[id*2] + tree[id*2+1];\n    }\n\n    void updateChmin(int id, int l, int\
    \ r, int u, int v, ll x) {\n        if (l > v || r < u) return;\n        if (tree[id].max1\
    \ <= x) return;\n        if (u <= l && r <= v && tree[id].max2 < x) {\n      \
    \      tree[id].setMin(x);\n            return;\n        }\n        push(id);\n\
    \        int mid = (l + r) >> 1;\n        updateChmin(id*2, l, mid, u, v, x);\n\
    \        updateChmin(id*2+1, mid+1, r, u, v, x);\n        tree[id] = tree[id*2]\
    \ + tree[id*2+1];\n    }\n\n    void updateRange(int id, int l, int r, int u,\
    \ int v, ll x) {\n        if (l > v || r < u) return;\n        if (u <= l && r\
    \ <= v) {\n            tree[id].add(x);\n            return;\n        }\n    \
    \    push(id);\n        int mid = (l + r) >> 1;\n        updateRange(id*2, l,\
    \ mid, u, v, x);\n        updateRange(id*2+1, mid+1, r, u, v, x);\n        tree[id]\
    \ = tree[id*2] + tree[id*2+1];\n    }\n\n    ll getSum(int id, int l, int r, int\
    \ u, int v) {\n        if (l > v || r < u) return 0;\n        if (u <= l && r\
    \ <= v) return tree[id].sum;\n        push(id);\n        int mid = (l + r) >>\
    \ 1;\n        ll t1 = getSum(id*2, l, mid, u, v);\n        ll t2 = getSum(id*2+1,\
    \ mid+1, r, u, v);\n        return t1 + t2;\n    }\n};\n#line 5 \"DataStructure/Yosupo/Range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    SegTreeBeats st(n);\n  \
    \  for (int i = 1; i <= n; i++) {\n        ll x; cin >> x;\n        st.build(1,\
    \ 1, n, i, x);\n    }\n    while (q--) {\n        int type, l, r; cin >> type\
    \ >> l >> r;\n        if (type == 0) {\n            ll b; cin >> b;\n        \
    \    st.updateChmin(1, 1, n, l+1, r, b);\n        } else if (type == 1) {\n  \
    \          ll b; cin >> b;\n            st.updateChmax(1, 1, n, l+1, r, b);\n\
    \        } else if (type == 2) {\n            ll b; cin >> b;\n            st.updateRange(1,\
    \ 1, n, l+1, r, b);\n        } else if (type == 3) {\n            cout << st.getSum(1,\
    \ 1, n, l+1, r) << '\\n';\n        }       \n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include \"../../template.h\"\n#include \"../SegTree/SegTreeBeats3.h\"\n\n\
    void solve() {\n    int n, q; cin >> n >> q;\n    SegTreeBeats st(n);\n    for\
    \ (int i = 1; i <= n; i++) {\n        ll x; cin >> x;\n        st.build(1, 1,\
    \ n, i, x);\n    }\n    while (q--) {\n        int type, l, r; cin >> type >>\
    \ l >> r;\n        if (type == 0) {\n            ll b; cin >> b;\n           \
    \ st.updateChmin(1, 1, n, l+1, r, b);\n        } else if (type == 1) {\n     \
    \       ll b; cin >> b;\n            st.updateChmax(1, 1, n, l+1, r, b);\n   \
    \     } else if (type == 2) {\n            ll b; cin >> b;\n            st.updateRange(1,\
    \ 1, n, l+1, r, b);\n        } else if (type == 3) {\n            cout << st.getSum(1,\
    \ 1, n, l+1, r) << '\\n';\n        }       \n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/SegTree/SegTreeBeats3.h
  isVerificationFile: true
  path: DataStructure/Yosupo/Range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Yosupo/Range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Yosupo/Range_chmin_chmax_add_range_sum.test.cpp
- /verify/DataStructure/Yosupo/Range_chmin_chmax_add_range_sum.test.cpp.html
title: DataStructure/Yosupo/Range_chmin_chmax_add_range_sum.test.cpp
---
