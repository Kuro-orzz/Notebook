---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DSU/Weighted_Dsu.h
    title: DataStructure/DSU/Weighted_Dsu.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"DataStructure/Aizu/aizu_dsl_1_b_weighted_dsu.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/DSU/Weighted_Dsu.h\"\n\nstruct WeightedDsu {\n\
    \    vector<int> par, sz;\n    vector<ll> diff;\n\n    WeightedDsu() {}\n    WeightedDsu(int\
    \ n): par(n+1), sz(n+1, 1), diff(n+1) {\n        iota(all(par), 0);\n    }\n\n\
    \    int find(int v) {\n        if (v == par[v]) return v;\n        int p = par[v];\n\
    \        int root = find(p);\n        diff[v] += diff[p];\n        return par[v]\
    \ = root;\n    }\n\n    // diff[v] - diff[u] = x\n    void merge(int u, int v,\
    \ int x) {\n        int pu = find(u);\n        int pv = find(v);\n        if (pu\
    \ == pv) return;\n        if(sz[pu] < sz[pv]) {\n            swap(u, v);\n   \
    \         swap(pu, pv);\n            x = -x;\n        }\n        par[pv] = pu;\n\
    \        sz[pu] += sz[pv];\n        diff[pv] = diff[u] - diff[v] + x;\n    }\n\
    \n    // diff[v] - diff[u]\n    int getDiff(int u, int v) {\n        int pu =\
    \ find(u);\n        int pv = find(v);\n        if (pu != pv) return INT_MAX;\n\
    \        return diff[v] - diff[u];\n    }\n};\n#line 5 \"DataStructure/Aizu/aizu_dsl_1_b_weighted_dsu.test.cpp\"\
    \n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    WeightedDsu g(n);\n    while\
    \ (q--) {\n        int type; cin >> type;\n        if (type == 0) {\n        \
    \    int x, y, z; cin >> x >> y >> z;\n            g.merge(x, y, z);\n       \
    \ } else if (type == 1) {\n            int x, y; cin >> x >> y;\n            int\
    \ res = g.getDiff(x, y);\n            if (res != INT_MAX) {\n                cout\
    \ << res << '\\n';\n            } else {\n                cout << \"?\\n\";\n\
    \            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#include \"../../template.h\"\n#include \"../DSU/Weighted_Dsu.h\"\n\nvoid\
    \ solve() {\n    int n, q; cin >> n >> q;\n    WeightedDsu g(n);\n    while (q--)\
    \ {\n        int type; cin >> type;\n        if (type == 0) {\n            int\
    \ x, y, z; cin >> x >> y >> z;\n            g.merge(x, y, z);\n        } else\
    \ if (type == 1) {\n            int x, y; cin >> x >> y;\n            int res\
    \ = g.getDiff(x, y);\n            if (res != INT_MAX) {\n                cout\
    \ << res << '\\n';\n            } else {\n                cout << \"?\\n\";\n\
    \            }\n        }\n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/DSU/Weighted_Dsu.h
  isVerificationFile: true
  path: DataStructure/Aizu/aizu_dsl_1_b_weighted_dsu.test.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Aizu/aizu_dsl_1_b_weighted_dsu.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Aizu/aizu_dsl_1_b_weighted_dsu.test.cpp
- /verify/DataStructure/Aizu/aizu_dsl_1_b_weighted_dsu.test.cpp.html
title: DataStructure/Aizu/aizu_dsl_1_b_weighted_dsu.test.cpp
---
