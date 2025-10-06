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
    PROBLEM: https://judge.yosupo.jp/problem/ordered_set
    links:
    - https://judge.yosupo.jp/problem/ordered_set
  bundledCode: "#line 1 \"DataStructure/Yosupo/Ordered_set.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/ordered_set\"\n\n#line 2 \"template.h\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n#define\
    \ MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x) x.erase(unique(all(x)),\
    \ x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define\
    \ inf (ll)1e18\n\n#define vi vector<int>\n#define pii pair<int, int>\n#define\
    \ pll pair<ll, ll>\n#define fi first\n#define se second\n\nconst int mod = 998244353;\n\
    \nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 4 \"DataStructure/Yosupo/Ordered_set.test.cpp\"\
    \n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds;\nusing ordered_set = tree<int, null_type, less<int>,\
    \ rb_tree_tag, tree_order_statistics_node_update>;\n\nvoid solve() {\n    int\
    \ n, q; cin >> n >> q;\n    ordered_set s;\n    for (int i = 0; i < n; i++) {\n\
    \        int x; cin >> x;\n        s.insert(x);\n    }\n    while (q--) {\n  \
    \      int tv, x; cin >> tv >> x;\n        if (tv == 0) {\n            s.insert(x);\n\
    \        } else if (tv == 1) {\n            s.erase(x);\n        } else if (tv\
    \ == 2) {\n            if (x > (int)s.size()) cout << \"-1\\n\";\n           \
    \ else cout << *s.find_by_order(x-1) << '\\n';\n        } else if (tv == 3) {\n\
    \            cout << s.order_of_key(x+1) << '\\n';\n        } else if (tv == 4)\
    \ {\n            int idx = s.order_of_key(x+1);\n            if (idx == 0) cout\
    \ << \"-1\\n\";\n            else cout << *s.find_by_order(idx-1) << '\\n';\n\
    \        } else if (tv == 5) {\n            int idx = s.order_of_key(x);\n   \
    \         if (idx == (int)s.size()) cout << \"-1\\n\";\n            else cout\
    \ << *s.find_by_order(idx) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/ordered_set\"\n\n#include\
    \ \"../../template.h\"\n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds;\nusing ordered_set = tree<int, null_type, less<int>,\
    \ rb_tree_tag, tree_order_statistics_node_update>;\n\nvoid solve() {\n    int\
    \ n, q; cin >> n >> q;\n    ordered_set s;\n    for (int i = 0; i < n; i++) {\n\
    \        int x; cin >> x;\n        s.insert(x);\n    }\n    while (q--) {\n  \
    \      int tv, x; cin >> tv >> x;\n        if (tv == 0) {\n            s.insert(x);\n\
    \        } else if (tv == 1) {\n            s.erase(x);\n        } else if (tv\
    \ == 2) {\n            if (x > (int)s.size()) cout << \"-1\\n\";\n           \
    \ else cout << *s.find_by_order(x-1) << '\\n';\n        } else if (tv == 3) {\n\
    \            cout << s.order_of_key(x+1) << '\\n';\n        } else if (tv == 4)\
    \ {\n            int idx = s.order_of_key(x+1);\n            if (idx == 0) cout\
    \ << \"-1\\n\";\n            else cout << *s.find_by_order(idx-1) << '\\n';\n\
    \        } else if (tv == 5) {\n            int idx = s.order_of_key(x);\n   \
    \         if (idx == (int)s.size()) cout << \"-1\\n\";\n            else cout\
    \ << *s.find_by_order(idx) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  isVerificationFile: true
  path: DataStructure/Yosupo/Ordered_set.test.cpp
  requiredBy: []
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Yosupo/Ordered_set.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Yosupo/Ordered_set.test.cpp
- /verify/DataStructure/Yosupo/Ordered_set.test.cpp.html
title: DataStructure/Yosupo/Ordered_set.test.cpp
---
