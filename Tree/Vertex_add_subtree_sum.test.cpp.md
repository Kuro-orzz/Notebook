---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick/Fenwick.h
    title: DataStructure/Fenwick/Fenwick.h
  - icon: ':heavy_check_mark:'
    path: Tree/EulerTour/EulerTour.h
    title: Tree/EulerTour/EulerTour.h
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"Tree/Vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line 2 \"template.h\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n\
    #define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64\
    \ ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n#define pii\
    \ pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define se second\n\
    \nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"Tree/EulerTour/EulerTour.h\"\
    \n\nvector<int> EulerTour(vector<int> &st, vector<int> &en, \n\t\t\t\tvector<vector<int>>\
    \ &adj, int root = 0, int type = 0) {\n\tint n = adj.size();\n\tst.assign(n, 0);\n\
    \ten.assign(n, 0);\n\tvector<int> tour;\n\tif (type == 0) tour.reserve(n);\n\t\
    else if (type == 1) tour.reserve(2 * n);\n\tint pos = 0;\n\tfunction<void(int,\
    \ int)> dfs = [&] (int u, int par) {\n\t\ttour.push_back(u);\n\t\tst[u] = ++pos;\n\
    \t\tfor (int v : adj[u]) {\n\t\t\tif (v == par) continue;\n\t\t\tdfs(v, u);\n\t\
    \t}\n\t\tif (type == 1) {\n\t\t\ttour.push_back(u);\n\t\t\tpos++;\n\t\t}\n\t\t\
    en[u] = pos;\n\t};\n\tdfs(root, -1);\n\treturn tour;\n}\n#line 2 \"DataStructure/Fenwick/Fenwick.h\"\
    \n\ntemplate <typename T>\nstruct Fenwick{\n    int n;\n    vector<T> fen;\n\n\
    \    Fenwick() {}\n    Fenwick(int _n): n(_n), fen(_n+1) {}\n\n    void update(int\
    \ pos, T val) {\n        for (; pos <= n; pos += pos & -pos) {\n            fen[pos]\
    \ += val;\n        }\n    }\n\n    T get(int pos) {\n        T ans = 0;\n    \
    \    for (; pos > 0; pos -= pos & -pos) {\n            ans += fen[pos];\n    \
    \    }\n        return ans;\n    }\n\n    T get(int l, int r) {\n        return\
    \ get(r) - get(l - 1);\n    }\n\n    void update_range(int l, int r, T val){\n\
    \        update(l, val);\n        update(r+1, -val);\n    }\n\n    void reset()\
    \ {\n        fill(all(fen), T(0));\n    }\n};\n#line 6 \"Tree/Vertex_add_subtree_sum.test.cpp\"\
    \n\nvoid solve() {\n\tint n, q; cin >> n >> q;\n\tint a[n];\n\tfor (int i = 0;\
    \ i < n; i++) {\n\t\tcin >> a[i];\n\t}\n\tvector<vector<int>> adj(n);\n\tfor (int\
    \ i = 1; i < n; i++) {\n\t\tint x; cin >> x;\n\t\tadj[i].push_back(x);\n\t\tadj[x].push_back(i);\n\
    \t}\n\tvector<int> st, en;\n\tvector<int> tour = EulerTour(st, en, adj);\n\tFenwick<ll>\
    \ BIT((int)tour.size() + 1);\n\tfor (int i = 0; i < n; i++) BIT.update(st[i],\
    \ a[i]);\n\twhile (q--) {\n\t\tint type; cin >> type;\n\t\tif (type == 0) {\n\t\
    \t\tint u, x; cin >> u >> x;\n\t\t\tBIT.update(st[u], x);\n\t\t} else if (type\
    \ == 1) {\n\t\t\tint u; cin >> u;\n\t\t\tcout << BIT.get(st[u], en[u]) << '\\\
    n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../template.h\"\n#include \"EulerTour/EulerTour.h\"\n#include \"\
    ../DataStructure/Fenwick/Fenwick.h\"\n\nvoid solve() {\n\tint n, q; cin >> n >>\
    \ q;\n\tint a[n];\n\tfor (int i = 0; i < n; i++) {\n\t\tcin >> a[i];\n\t}\n\t\
    vector<vector<int>> adj(n);\n\tfor (int i = 1; i < n; i++) {\n\t\tint x; cin >>\
    \ x;\n\t\tadj[i].push_back(x);\n\t\tadj[x].push_back(i);\n\t}\n\tvector<int> st,\
    \ en;\n\tvector<int> tour = EulerTour(st, en, adj);\n\tFenwick<ll> BIT((int)tour.size()\
    \ + 1);\n\tfor (int i = 0; i < n; i++) BIT.update(st[i], a[i]);\n\twhile (q--)\
    \ {\n\t\tint type; cin >> type;\n\t\tif (type == 0) {\n\t\t\tint u, x; cin >>\
    \ u >> x;\n\t\t\tBIT.update(st[u], x);\n\t\t} else if (type == 1) {\n\t\t\tint\
    \ u; cin >> u;\n\t\t\tcout << BIT.get(st[u], en[u]) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - template.h
  - Tree/EulerTour/EulerTour.h
  - DataStructure/Fenwick/Fenwick.h
  isVerificationFile: true
  path: Tree/Vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2025-05-25 00:26:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Tree/Vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/Tree/Vertex_add_subtree_sum.test.cpp
- /verify/Tree/Vertex_add_subtree_sum.test.cpp.html
title: Tree/Vertex_add_subtree_sum.test.cpp
---
