---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
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
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Misc.h\"\n\n\n// for negative val\nll GCD(ll\
    \ a, ll b) {\n    a = llabs(a), b = llabs(b);\n    return (!b ? a : GCD(b, a %\
    \ b));\n}\n\nll GCD(ll a, ll b) { return (!b ? a : GCD(b, a % b)); }\nll LCM(ll\
    \ a, ll b) { return a / GCD(a, b) * b; }\n// logb(a)\ndouble log_base(ll a, ll\
    \ b) { return log(a) / log(b); }\n\n// use for 2 <= BASE <= 26\nstring decimal_to_base(ll\
    \ n, int BASE) {\n    if (!n) return \"0\";\n    bool neg = (n < 0 ? 1 : 0);\n\
    \    n = llabs(n);\n    string num = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ;\n    string res;\n    while(n) {\n        res.push_back(num[n % BASE]);\n  \
    \      n /= BASE;\n    }\n    if (neg) res += '-';\n    reverse(all(res));\n \
    \   return res;\n}\n\n// any BASE to decimal\n// use ctype lib\nll convert_decimal(string\
    \ s, int BASE) {\n    auto val = [&](char c) { return (isdigit(toupper(c)) ? c-'0'\
    \ : c-'A'+10); };\n    ll n = s.size(), p = 1, res = 0;\n    for (int i = n-1;\
    \ i >= 0; i--) {\n        res += val(s[i]) * p;\n        p = p * BASE;\n    }\n\
    \    return res;\n}\n"
  code: "#include \"../../template.h\"\n\n\n// for negative val\nll GCD(ll a, ll b)\
    \ {\n    a = llabs(a), b = llabs(b);\n    return (!b ? a : GCD(b, a % b));\n}\n\
    \nll GCD(ll a, ll b) { return (!b ? a : GCD(b, a % b)); }\nll LCM(ll a, ll b)\
    \ { return a / GCD(a, b) * b; }\n// logb(a)\ndouble log_base(ll a, ll b) { return\
    \ log(a) / log(b); }\n\n// use for 2 <= BASE <= 26\nstring decimal_to_base(ll\
    \ n, int BASE) {\n    if (!n) return \"0\";\n    bool neg = (n < 0 ? 1 : 0);\n\
    \    n = llabs(n);\n    string num = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ;\n    string res;\n    while(n) {\n        res.push_back(num[n % BASE]);\n  \
    \      n /= BASE;\n    }\n    if (neg) res += '-';\n    reverse(all(res));\n \
    \   return res;\n}\n\n// any BASE to decimal\n// use ctype lib\nll convert_decimal(string\
    \ s, int BASE) {\n    auto val = [&](char c) { return (isdigit(toupper(c)) ? c-'0'\
    \ : c-'A'+10); };\n    ll n = s.size(), p = 1, res = 0;\n    for (int i = n-1;\
    \ i >= 0; i--) {\n        res += val(s[i]) * p;\n        p = p * BASE;\n    }\n\
    \    return res;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Misc.h
  requiredBy: []
  timestamp: '2025-07-06 11:39:53+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/Math/Misc.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Misc.h
- /library/NumberTheory/Math/Misc.h.html
title: NumberTheory/Math/Misc.h
---
