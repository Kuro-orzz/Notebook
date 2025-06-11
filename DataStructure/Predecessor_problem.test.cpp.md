---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"DataStructure/Predecessor_problem.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\n#line 2 \"template.h\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n\
    #define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64\
    \ ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n#define pii\
    \ pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define se second\n\
    \nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 4 \"DataStructure/Predecessor_problem.test.cpp\"\
    \n\ntemplate <typename T>\nclass custom_set {\npublic:\n    set<T> s;\n\n    void\
    \ insert(T k) {\n        s.insert(k);\n    }\n\n    void erase(T k) {\n      \
    \  s.erase(k);\n    }\n\n    bool contain(T k) {\n        return s.count(k);\n\
    \    }\n\n    T find_next(T k) {\n        auto it = s.lower_bound(k);\n      \
    \  if (it == s.end())\n            return -1;\n        return *it;\n    }\n\n\
    \    T find_prev(T k) {\n        auto it = s.upper_bound(k);\n        if (it ==\
    \ s.begin())\n            return -1;\n        return *prev(it);\n    }\n};\n\n\
    void solve(){\n    int n, q; cin >> n >> q;\n    string str; cin >> str;\n   \
    \ custom_set<int> s;\n    for (size_t i = 0; i < str.size(); i++) {\n        if\
    \ (str[i] == '1')\n            s.insert(i);\n    }\n    while (q--) {\n      \
    \  int tv, k; cin >> tv >> k;\n        if (tv == 0) {\n            s.insert(k);\n\
    \        } else if (tv == 1) {\n            s.erase(k);\n        } else if (tv\
    \ == 2) {\n            cout << (s.contain(k) ? 1 : 0) << '\\n';\n        } else\
    \ if (tv == 3) {\n            cout << s.find_next(k) << '\\n'; \n        } else\
    \ if (tv == 4) {\n            cout << s.find_prev(k) << '\\n';\n        }\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    \n#include \"../template.h\"\n\ntemplate <typename T>\nclass custom_set {\npublic:\n\
    \    set<T> s;\n\n    void insert(T k) {\n        s.insert(k);\n    }\n\n    void\
    \ erase(T k) {\n        s.erase(k);\n    }\n\n    bool contain(T k) {\n      \
    \  return s.count(k);\n    }\n\n    T find_next(T k) {\n        auto it = s.lower_bound(k);\n\
    \        if (it == s.end())\n            return -1;\n        return *it;\n   \
    \ }\n\n    T find_prev(T k) {\n        auto it = s.upper_bound(k);\n        if\
    \ (it == s.begin())\n            return -1;\n        return *prev(it);\n    }\n\
    };\n\nvoid solve(){\n    int n, q; cin >> n >> q;\n    string str; cin >> str;\n\
    \    custom_set<int> s;\n    for (size_t i = 0; i < str.size(); i++) {\n     \
    \   if (str[i] == '1')\n            s.insert(i);\n    }\n    while (q--) {\n \
    \       int tv, k; cin >> tv >> k;\n        if (tv == 0) {\n            s.insert(k);\n\
    \        } else if (tv == 1) {\n            s.erase(k);\n        } else if (tv\
    \ == 2) {\n            cout << (s.contain(k) ? 1 : 0) << '\\n';\n        } else\
    \ if (tv == 3) {\n            cout << s.find_next(k) << '\\n'; \n        } else\
    \ if (tv == 4) {\n            cout << s.find_prev(k) << '\\n';\n        }\n  \
    \  }\n}"
  dependsOn:
  - template.h
  isVerificationFile: true
  path: DataStructure/Predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2025-05-07 22:18:34+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Predecessor_problem.test.cpp
- /verify/DataStructure/Predecessor_problem.test.cpp.html
title: DataStructure/Predecessor_problem.test.cpp
---
