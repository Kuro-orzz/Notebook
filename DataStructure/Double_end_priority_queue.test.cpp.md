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
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"DataStructure/Double_end_priority_queue.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\n\n\
    #line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n \n\
    #define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 4 \"DataStructure/Double_end_priority_queue.test.cpp\"\n\nvoid\
    \ solve() {\n\tint n, q; cin >> n >> q;\n\tpriority_queue<int> maxElement;\n\t\
    priority_queue<int, vector<int>, greater<int>> minElement;\n\tunordered_map<int,\
    \ int> maxRev, minRev;\n\tfor (int i = 0; i < n; i++) {\n\t\tint x; cin >> x;\n\
    \t\tmaxElement.push(x);\n\t\tminElement.push(x);\n\t}\n\tauto lazyRev = [&]()\
    \ {\n\t\twhile (!maxElement.empty() && maxRev[maxElement.top()] > 0) {\n\t\t\t\
    maxRev[maxElement.top()]--;\n\t\t\tmaxElement.pop();\n\t\t}\n\t\twhile (!minElement.empty()\
    \ && minRev[minElement.top()] > 0) {\n\t\t\tminRev[minElement.top()]--;\n\t\t\t\
    minElement.pop();\n\t\t}\n\t};\n\twhile (q--) {\n\t\tint tv; cin >> tv;\n\t\t\
    if (tv == 0) {\n\t\t\tint x; cin >> x;\n\t\t\tmaxElement.push(x);\n\t\t\tminElement.push(x);\n\
    \t\t} else if (tv == 1) {\n\t\t\tlazyRev();\n\t\t\tint mn = minElement.top();\n\
    \t\t\tminElement.pop();\n\t\t\tmaxRev[mn]++;\n\t\t\tcout << mn << '\\n';\n\t\t\
    } else if (tv == 2) {\n\t\t\tlazyRev();\n\t\t\tint mx = maxElement.top();\n\t\t\
    \tmaxElement.pop();\n\t\t\tminRev[mx]++;\n\t\t\tcout << mx << '\\n';\n\t\t}\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../template.h\"\n\nvoid solve() {\n\tint n, q; cin >> n >> q;\n\
    \tpriority_queue<int> maxElement;\n\tpriority_queue<int, vector<int>, greater<int>>\
    \ minElement;\n\tunordered_map<int, int> maxRev, minRev;\n\tfor (int i = 0; i\
    \ < n; i++) {\n\t\tint x; cin >> x;\n\t\tmaxElement.push(x);\n\t\tminElement.push(x);\n\
    \t}\n\tauto lazyRev = [&]() {\n\t\twhile (!maxElement.empty() && maxRev[maxElement.top()]\
    \ > 0) {\n\t\t\tmaxRev[maxElement.top()]--;\n\t\t\tmaxElement.pop();\n\t\t}\n\t\
    \twhile (!minElement.empty() && minRev[minElement.top()] > 0) {\n\t\t\tminRev[minElement.top()]--;\n\
    \t\t\tminElement.pop();\n\t\t}\n\t};\n\twhile (q--) {\n\t\tint tv; cin >> tv;\n\
    \t\tif (tv == 0) {\n\t\t\tint x; cin >> x;\n\t\t\tmaxElement.push(x);\n\t\t\t\
    minElement.push(x);\n\t\t} else if (tv == 1) {\n\t\t\tlazyRev();\n\t\t\tint mn\
    \ = minElement.top();\n\t\t\tminElement.pop();\n\t\t\tmaxRev[mn]++;\n\t\t\tcout\
    \ << mn << '\\n';\n\t\t} else if (tv == 2) {\n\t\t\tlazyRev();\n\t\t\tint mx =\
    \ maxElement.top();\n\t\t\tmaxElement.pop();\n\t\t\tminRev[mx]++;\n\t\t\tcout\
    \ << mx << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - template.h
  isVerificationFile: true
  path: DataStructure/Double_end_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2025-05-12 18:52:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Double_end_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Double_end_priority_queue.test.cpp
- /verify/DataStructure/Double_end_priority_queue.test.cpp.html
title: DataStructure/Double_end_priority_queue.test.cpp
---
