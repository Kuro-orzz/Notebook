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
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"NumberTheory/Enumerate_quotients.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\n#line 2 \"template.h\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n\
    #define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64\
    \ ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n#define pii\
    \ pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define se second\n\
    \nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 4 \"NumberTheory/Enumerate_quotients.test.cpp\"\
    \n\nvoid solve() {\n    ll n; cin >> n;\n    set<ll> s;\n    for (ll i = 1; i*i\
    \ <= n; i++) {\n        s.insert(i);\n        s.insert(n / i);\n    }\n    cout\
    \ << s.size() << '\\n';\n    for (ll x : s) cout << x << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    \n#include \"../template.h\"\n\nvoid solve() {\n    ll n; cin >> n;\n    set<ll>\
    \ s;\n    for (ll i = 1; i*i <= n; i++) {\n        s.insert(i);\n        s.insert(n\
    \ / i);\n    }\n    cout << s.size() << '\\n';\n    for (ll x : s) cout << x <<\
    \ \" \";\n}"
  dependsOn:
  - template.h
  isVerificationFile: true
  path: NumberTheory/Enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Enumerate_quotients.test.cpp
- /verify/NumberTheory/Enumerate_quotients.test.cpp.html
title: NumberTheory/Enumerate_quotients.test.cpp
---
