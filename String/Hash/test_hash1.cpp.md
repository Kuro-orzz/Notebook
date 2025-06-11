---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: String/Hash/Rolling_Hash.h
    title: String/Hash/Rolling_Hash.h
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
    - https://oj.vnoi.info/problem/substr
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"String/Hash/Rolling_Hash.h\"\n\ntemplate <typename T>\nclass\
    \ Hash {\npublic:\n    static constexpr int base = 331;\n    static constexpr\
    \ int mod = 1'000'000'007;\n    vector<T> h, p;\n\n    Hash() {}\n\n    Hash(const\
    \ string &s) {\n        build(s);\n    }\n\n    void build(const string &s) {\n\
    \        int n = s.size();\n        h = hashStr(s, n);\n        p = calc_pow(n);\n\
    \    }\n\n    T getHash(int l, int r) const {\n        T x = (h[r] - 1ll * h[l-1]\
    \ * p[r-l+1]) % mod;\n        return T((x + mod) % mod);\n    }\n\nprivate:\n\
    \    vector<T> hashStr(const string &s, int n) {\n        vector<T> hash(n + 1);\n\
    \        for (int i = 1; i <= n; i++) {\n            int c = s[i - 1] - 'a' +\
    \ 1;\n            hash[i] = (1ll * hash[i-1] * base + c) % mod;\n        }\n \
    \       return hash;\n    }\n\n    vector<T> calc_pow(int n) {\n        vector<T>\
    \ P;\n        P.emplace_back(1);\n        for (int i = 1; i <= n; i++) {\n   \
    \         P.emplace_back((1ll * P[i-1] * base) % mod);\n        }\n        return\
    \ P;\n    }\n};\n#line 3 \"String/Hash/test_hash1.cpp\"\n\n/* AC: https://oj.vnoi.info/problem/substr\
    \ */\n\nvoid solve() {\n    string s1, s2; cin >> s1 >> s2;\n    int n = s1.size(),\
    \ m = s2.size();\n    Hash<int> h1(s1), h2(s2);\n    for (int i = 1; i <= n-m+1;\
    \ i++) {\n        if (h1.getHash(i, i+m-1) == h2.getHash(1, m)) {\n          \
    \  cout << i << ' ';\n        }\n    }\n}\n"
  code: "#include \"../../template.h\"\n#include \"Rolling_Hash.h\"\n\n/* AC: https://oj.vnoi.info/problem/substr\
    \ */\n\nvoid solve() {\n    string s1, s2; cin >> s1 >> s2;\n    int n = s1.size(),\
    \ m = s2.size();\n    Hash<int> h1(s1), h2(s2);\n    for (int i = 1; i <= n-m+1;\
    \ i++) {\n        if (h1.getHash(i, i+m-1) == h2.getHash(1, m)) {\n          \
    \  cout << i << ' ';\n        }\n    }\n}"
  dependsOn:
  - template.h
  - String/Hash/Rolling_Hash.h
  isVerificationFile: false
  path: String/Hash/test_hash1.cpp
  requiredBy: []
  timestamp: '2025-05-30 22:12:29+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Hash/test_hash1.cpp
layout: document
redirect_from:
- /library/String/Hash/test_hash1.cpp
- /library/String/Hash/test_hash1.cpp.html
title: String/Hash/test_hash1.cpp
---
