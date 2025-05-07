---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Static_RMQ.test.cpp
    title: DataStructure/Static_RMQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ 0;\n}\n#line 2 \"DataStructure/RMQ/RMQ.h\"\n\ntemplate <typename T>\nstruct\
    \ RMQ {\n\tint n;\n\tvector<vector<T>> mn, mx, sum;\n\n\tRMQ() {}\n\tRMQ(int _n):\
    \ n(_n) {\n\t\tmn = mx = sum = vector<vector<T>>(20, vector<T>(_n+1));\n\t}\n\n\
    \tvoid preprocess(vector<T> &a) {\n\t\tfor (int i = 1; i <= n; i++) {\n\t\t\t\
    mn[0][i] = mx[0][i] = sum[0][i] = a[i];\n\t\t}\n\t\tfor (int i = 1; i < 20; i++)\
    \ {\n\t\t\tfor (int j = 1; j + (1 << i) - 1 <= n; j++) {\n\t\t\t\tmn[i][j] = min(mn[i-1][j],\
    \ mn[i - 1][j + (1 << (i-1))]);\n\t\t\t\tmx[i][j] = max(mx[i-1][j], mx[i - 1][j\
    \ + (1 << (i-1))]);\n\t\t\t\tsum[i][j] = sum[i-1][j] + sum[i - 1][j + (1 << (i-1))];\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tT queryMin(int l, int r) {\n\t\tint k = __lg(r-l+1);\n\
    \t\treturn min(mn[k][l], mn[k][r - (1 << k) + 1]);\n\t}\n\n\tT queryMax(int l,\
    \ int r) {\n\t\tint k = __lg(r-l+1);\n\t\treturn max(mx[k][l], mx[k][r - (1 <<\
    \ k) + 1]);\n\t}\n\n\tT querySum(int l, int r) {\n\t\tint len = r-l+1;\n\t\tT\
    \ ans = 0;\n\t\tfor (int i = 0; (1 << i) <= len; i++) {\n\t\t\tif (len >> i &\
    \ 1) {\n\t\t\t\tans += sum[i][l];\n\t\t\t\tl += (1 << i);\n\t\t\t}\n\t\t}\n\t\t\
    return ans;\n\t}\n};\n"
  code: "#include \"../../template.h\"\n\ntemplate <typename T>\nstruct RMQ {\n\t\
    int n;\n\tvector<vector<T>> mn, mx, sum;\n\n\tRMQ() {}\n\tRMQ(int _n): n(_n) {\n\
    \t\tmn = mx = sum = vector<vector<T>>(20, vector<T>(_n+1));\n\t}\n\n\tvoid preprocess(vector<T>\
    \ &a) {\n\t\tfor (int i = 1; i <= n; i++) {\n\t\t\tmn[0][i] = mx[0][i] = sum[0][i]\
    \ = a[i];\n\t\t}\n\t\tfor (int i = 1; i < 20; i++) {\n\t\t\tfor (int j = 1; j\
    \ + (1 << i) - 1 <= n; j++) {\n\t\t\t\tmn[i][j] = min(mn[i-1][j], mn[i - 1][j\
    \ + (1 << (i-1))]);\n\t\t\t\tmx[i][j] = max(mx[i-1][j], mx[i - 1][j + (1 << (i-1))]);\n\
    \t\t\t\tsum[i][j] = sum[i-1][j] + sum[i - 1][j + (1 << (i-1))];\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tT queryMin(int l, int r) {\n\t\tint k = __lg(r-l+1);\n\t\treturn min(mn[k][l],\
    \ mn[k][r - (1 << k) + 1]);\n\t}\n\n\tT queryMax(int l, int r) {\n\t\tint k =\
    \ __lg(r-l+1);\n\t\treturn max(mx[k][l], mx[k][r - (1 << k) + 1]);\n\t}\n\n\t\
    T querySum(int l, int r) {\n\t\tint len = r-l+1;\n\t\tT ans = 0;\n\t\tfor (int\
    \ i = 0; (1 << i) <= len; i++) {\n\t\t\tif (len >> i & 1) {\n\t\t\t\tans += sum[i][l];\n\
    \t\t\t\tl += (1 << i);\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\t}\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/RMQ/RMQ.h
  requiredBy: []
  timestamp: '2025-05-07 22:18:34+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/Static_RMQ.test.cpp
documentation_of: DataStructure/RMQ/RMQ.h
layout: document
redirect_from:
- /library/DataStructure/RMQ/RMQ.h
- /library/DataStructure/RMQ/RMQ.h.html
title: DataStructure/RMQ/RMQ.h
---
