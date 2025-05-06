---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RMQ/RMQ.h
    title: DataStructure/RMQ/RMQ.h
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"DataStructure/Static_RMQ.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 2 \"template.h\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n#define MOD\
    \ (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n#define vi vector<int>\n#define\
    \ pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define se second\n\
    \nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"DataStructure/RMQ/RMQ.h\"\n\
    \ntemplate <typename T>\nstruct RMQ {\n\tint n;\n\tvector<vector<T>> mn, mx, sum;\n\
    \n\tRMQ() {}\n\tRMQ(int _n): n(_n) {\n\t\tmn = mx = sum = vector<vector<T>>(20,\
    \ vector<T>(_n+1));\n\t}\n\n\tvoid preprocess(vector<T> &a) {\n\t\tfor (int i\
    \ = 1; i <= n; i++) {\n\t\t\tmn[0][i] = mx[0][i] = sum[0][i] = a[i];\n\t\t}\n\t\
    \tfor (int i = 1; i < 20; i++) {\n\t\t\tfor (int j = 1; j + (1 << i) - 1 <= n;\
    \ j++) {\n\t\t\t\tmn[i][j] = min(mn[i-1][j], mn[i - 1][j + (1 << (i-1))]);\n\t\
    \t\t\tmx[i][j] = max(mx[i-1][j], mx[i - 1][j + (1 << (i-1))]);\n\t\t\t\tsum[i][j]\
    \ = sum[i-1][j] + sum[i - 1][j + (1 << (i-1))];\n\t\t\t}\n\t\t}\n\t}\n\n\tT queryMin(int\
    \ l, int r) {\n\t\tint k = __lg(r-l+1);\n\t\treturn min(mn[k][l], mn[k][r - (1\
    \ << k) + 1]);\n\t}\n\n\tT queryMax(int l, int r) {\n\t\tint k = __lg(r-l+1);\n\
    \t\treturn max(mx[k][l], mx[k][r - (1 << k) + 1]);\n\t}\n\n\tT querySum(int l,\
    \ int r) {\n\t\tint len = r-l+1;\n\t\tT ans = 0;\n\t\tfor (int i = 0; (1 << i)\
    \ <= len; i++) {\n\t\t\tif (len >> i & 1) {\n\t\t\t\tans += sum[i][l];\n\t\t\t\
    \tl += (1 << i);\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\t}\n};\n#line 5 \"DataStructure/Static_RMQ.test.cpp\"\
    \n\nvoid solve() {\n\tint n, q; cin >> n >> q;\n\tvector<int> a(n+1);\n\tfor (int\
    \ i = 1; i <= n; i++) {\n\t\tcin >> a[i];\n\t}\n\tRMQ<int> rmq(n);\n\trmq.preprocess(a);\n\
    \twhile (q--) {\n\t\tint l, r; cin >> l >> r;\n\t\tcout << rmq.queryMin(l+1, r)\
    \ << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../template.h\"\n#include \"RMQ/RMQ.h\"\n\nvoid solve() {\n\tint n, q; cin\
    \ >> n >> q;\n\tvector<int> a(n+1);\n\tfor (int i = 1; i <= n; i++) {\n\t\tcin\
    \ >> a[i];\n\t}\n\tRMQ<int> rmq(n);\n\trmq.preprocess(a);\n\twhile (q--) {\n\t\
    \tint l, r; cin >> l >> r;\n\t\tcout << rmq.queryMin(l+1, r) << '\\n';\n\t}\n}"
  dependsOn:
  - template.h
  - DataStructure/RMQ/RMQ.h
  isVerificationFile: true
  path: DataStructure/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2025-05-06 22:27:53+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Static_RMQ.test.cpp
- /verify/DataStructure/Static_RMQ.test.cpp.html
title: DataStructure/Static_RMQ.test.cpp
---
