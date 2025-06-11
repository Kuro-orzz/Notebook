---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/Fenwick/Fenwick.h
    title: DataStructure/Fenwick/Fenwick.h
  - icon: ':x:'
    path: Tree/EulerTour/EulerTour.h
    title: Tree/EulerTour/EulerTour.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \n\nvector<int> EulerTour(vector<int> &st, vector<int> &en, \n               \
    \ vector<vector<int>> &adj, int root = 0, int type = 0) {\n    int n = adj.size();\n\
    \    st.assign(n, 0);\n    en.assign(n, 0);\n    vector<int> tour;\n    if (type\
    \ == 0) tour.reserve(n);\n    else if (type == 1) tour.reserve(2 * n);\n    int\
    \ pos = 0;\n    function<void(int, int)> dfs = [&] (int u, int par) {\n      \
    \  tour.push_back(u);\n        st[u] = ++pos;\n        for (int v : adj[u]) {\n\
    \            if (v == par) continue;\n            dfs(v, u);\n        }\n    \
    \    if (type == 1) {\n            tour.push_back(u);\n            pos++;\n  \
    \      }\n        en[u] = pos;\n    };\n    dfs(root, -1);\n    return tour;\n\
    }\n#line 2 \"DataStructure/Fenwick/Fenwick.h\"\n\ntemplate <typename T>\nstruct\
    \ Fenwick{\n    int n;\n    vector<T> fen;\n\n    Fenwick() {}\n    Fenwick(int\
    \ _n): n(_n), fen(_n+1) {}\n\n    void update(int pos, T val) {\n        for (;\
    \ pos <= n; pos += pos & -pos) {\n            fen[pos] += val;\n        }\n  \
    \  }\n\n    T get(int pos) {\n        T ans = 0;\n        for (; pos > 0; pos\
    \ -= pos & -pos) {\n            ans += fen[pos];\n        }\n        return ans;\n\
    \    }\n\n    T get(int l, int r) {\n        return get(r) - get(l - 1);\n   \
    \ }\n\n    void update_range(int l, int r, T val){\n        update(l, val);\n\
    \        update(r+1, -val);\n    }\n\n    void reset() {\n        fill(all(fen),\
    \ T(0));\n    }\n};\n#line 6 \"Tree/Vertex_add_subtree_sum.test.cpp\"\n\nvoid\
    \ solve() {\n    int n, q; cin >> n >> q;\n    int a[n];\n    for (int i = 0;\
    \ i < n; i++) {\n        cin >> a[i];\n    }\n    vector<vector<int>> adj(n);\n\
    \    for (int i = 1; i < n; i++) {\n        int x; cin >> x;\n        adj[i].push_back(x);\n\
    \        adj[x].push_back(i);\n    }\n    vector<int> st, en;\n    vector<int>\
    \ tour = EulerTour(st, en, adj);\n    Fenwick<ll> BIT((int)tour.size() + 1);\n\
    \    for (int i = 0; i < n; i++) BIT.update(st[i], a[i]);\n    while (q--) {\n\
    \        int type; cin >> type;\n        if (type == 0) {\n            int u,\
    \ x; cin >> u >> x;\n            BIT.update(st[u], x);\n        } else if (type\
    \ == 1) {\n            int u; cin >> u;\n            cout << BIT.get(st[u], en[u])\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../template.h\"\n#include \"EulerTour/EulerTour.h\"\n#include \"\
    ../DataStructure/Fenwick/Fenwick.h\"\n\nvoid solve() {\n    int n, q; cin >> n\
    \ >> q;\n    int a[n];\n    for (int i = 0; i < n; i++) {\n        cin >> a[i];\n\
    \    }\n    vector<vector<int>> adj(n);\n    for (int i = 1; i < n; i++) {\n \
    \       int x; cin >> x;\n        adj[i].push_back(x);\n        adj[x].push_back(i);\n\
    \    }\n    vector<int> st, en;\n    vector<int> tour = EulerTour(st, en, adj);\n\
    \    Fenwick<ll> BIT((int)tour.size() + 1);\n    for (int i = 0; i < n; i++) BIT.update(st[i],\
    \ a[i]);\n    while (q--) {\n        int type; cin >> type;\n        if (type\
    \ == 0) {\n            int u, x; cin >> u >> x;\n            BIT.update(st[u],\
    \ x);\n        } else if (type == 1) {\n            int u; cin >> u;\n       \
    \     cout << BIT.get(st[u], en[u]) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  - Tree/EulerTour/EulerTour.h
  - DataStructure/Fenwick/Fenwick.h
  isVerificationFile: true
  path: Tree/Vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Tree/Vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/Tree/Vertex_add_subtree_sum.test.cpp
- /verify/Tree/Vertex_add_subtree_sum.test.cpp.html
title: Tree/Vertex_add_subtree_sum.test.cpp
---
