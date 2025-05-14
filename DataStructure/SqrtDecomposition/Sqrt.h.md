---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
    title: DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
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
    \ 0;\n}\n#line 2 \"DataStructure/SqrtDecomposition/Sqrt.h\"\n\nclass SimpleSqrt\
    \ {\npublic:\n\tint n, block_sz;\n\tvector<ll> a, block;\n\n\tSimpleSqrt() {}\n\
    \n\tSimpleSqrt(int _n): n(_n), a(_n, 0) {\n\t\tblock_sz = sqrt(_n);\n\t\tblock.resize(n\
    \ / block_sz + 1);\n\t}\n\n\tSimpleSqrt(int _n, vector<ll> &arr): n(_n), a(arr)\
    \ {\n    \tblock_sz = sqrt(n);\n    \tblock.resize(n / block_sz + 1);\n    \t\
    int cnt = -1;\n    \tfor(int i = 0; i < n; i++) {\n        \tif(i % block_sz ==\
    \ 0) cnt++;\n        \tblock[cnt] += arr[i];\n    \t}\n\t}\n\n\tll query(int l,\
    \ int r) {\n\t    ll sum = 0;\n\t    for(int i = l; i <= r;) {\n\t        if(i\
    \ % block_sz == 0 && i+block_sz-1 <= r) {\n\t            sum += block[i/block_sz];\n\
    \t            i += block_sz;\n\t        } else {\n\t            sum += a[i];\n\
    \t            i++;\n\t        }\n\t    }\n\t    return sum;\n\t}\n\n\tvoid add(int\
    \ pos, int val) {\n\t\tint idx = pos / block_sz;\n\t    block[idx] += val;\n\t\
    \    a[pos] += val;\n\t}\n};\n"
  code: "#include \"../../template.h\"\n\nclass SimpleSqrt {\npublic:\n\tint n, block_sz;\n\
    \tvector<ll> a, block;\n\n\tSimpleSqrt() {}\n\n\tSimpleSqrt(int _n): n(_n), a(_n,\
    \ 0) {\n\t\tblock_sz = sqrt(_n);\n\t\tblock.resize(n / block_sz + 1);\n\t}\n\n\
    \tSimpleSqrt(int _n, vector<ll> &arr): n(_n), a(arr) {\n    \tblock_sz = sqrt(n);\n\
    \    \tblock.resize(n / block_sz + 1);\n    \tint cnt = -1;\n    \tfor(int i =\
    \ 0; i < n; i++) {\n        \tif(i % block_sz == 0) cnt++;\n        \tblock[cnt]\
    \ += arr[i];\n    \t}\n\t}\n\n\tll query(int l, int r) {\n\t    ll sum = 0;\n\t\
    \    for(int i = l; i <= r;) {\n\t        if(i % block_sz == 0 && i+block_sz-1\
    \ <= r) {\n\t            sum += block[i/block_sz];\n\t            i += block_sz;\n\
    \t        } else {\n\t            sum += a[i];\n\t            i++;\n\t       \
    \ }\n\t    }\n\t    return sum;\n\t}\n\n\tvoid add(int pos, int val) {\n\t\tint\
    \ idx = pos / block_sz;\n\t    block[idx] += val;\n\t    a[pos] += val;\n\t}\n\
    };"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SqrtDecomposition/Sqrt.h
  requiredBy: []
  timestamp: '2025-05-15 00:54:17+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/SqrtDecomposition/Point_Add_Range_Sum.test.cpp
documentation_of: DataStructure/SqrtDecomposition/Sqrt.h
layout: document
redirect_from:
- /library/DataStructure/SqrtDecomposition/Sqrt.h
- /library/DataStructure/SqrtDecomposition/Sqrt.h.html
title: DataStructure/SqrtDecomposition/Sqrt.h
---
