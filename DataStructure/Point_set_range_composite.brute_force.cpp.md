---
data:
  _extendedDependsOn:
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
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"DataStructure/Point_set_range_composite.brute_force.cpp\"\
    \n// #define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\
    #define vi vector<int>\n#define pii pair<int, int>\n#define pll pair<ll, ll>\n\
    #define fi first\n#define se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\
    \nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 4 \"DataStructure/Point_set_range_composite.brute_force.cpp\"\n\
    \nconst int mod = 998244353;\n\nvector<int> a, b;\n\nint calc(int l, int r, int\
    \ x) {\n\tif (l == r) return (1ll * a[l] * x + b[l]) % mod;\n\treturn (1ll * a[r]\
    \ * calc(l, r-1, x) + b[r]) % mod;\n}\n\nvoid solve() {\n\tint n, q; cin >> n\
    \ >> q;\n\ta.resize(n);\n\tb.resize(n);\n\tfor (int i = 0; i < n; i++) {\n\t\t\
    cin >> a[i] >> b[i];\n\t}\n\twhile (q--) {\n\t\tint tv; cin >> tv;\n\t\tif (tv\
    \ == 0) {\n\t\t\tint p, c, d; cin >> p >> c >> d;\n\t\t\ta[p] = c;\n\t\t\tb[p]\
    \ = d;\n\t\t} else {\n\t\t\tint l, r, x; cin >> l >> r >> x;\n\t\t\tcout << calc(l,\
    \ r-1, x) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "// #define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../template.h\"\n\nconst int mod = 998244353;\n\nvector<int> a,\
    \ b;\n\nint calc(int l, int r, int x) {\n\tif (l == r) return (1ll * a[l] * x\
    \ + b[l]) % mod;\n\treturn (1ll * a[r] * calc(l, r-1, x) + b[r]) % mod;\n}\n\n\
    void solve() {\n\tint n, q; cin >> n >> q;\n\ta.resize(n);\n\tb.resize(n);\n\t\
    for (int i = 0; i < n; i++) {\n\t\tcin >> a[i] >> b[i];\n\t}\n\twhile (q--) {\n\
    \t\tint tv; cin >> tv;\n\t\tif (tv == 0) {\n\t\t\tint p, c, d; cin >> p >> c >>\
    \ d;\n\t\t\ta[p] = c;\n\t\t\tb[p] = d;\n\t\t} else {\n\t\t\tint l, r, x; cin >>\
    \ l >> r >> x;\n\t\t\tcout << calc(l, r-1, x) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/Point_set_range_composite.brute_force.cpp
  requiredBy: []
  timestamp: '2025-05-06 22:27:53+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Point_set_range_composite.brute_force.cpp
layout: document
redirect_from:
- /library/DataStructure/Point_set_range_composite.brute_force.cpp
- /library/DataStructure/Point_set_range_composite.brute_force.cpp.html
title: DataStructure/Point_set_range_composite.brute_force.cpp
---
