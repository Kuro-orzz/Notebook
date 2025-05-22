---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/221/problem/D
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template.h:\
    \ line -1: no such header\n"
  code: "// https://codeforces.com/contest/221/problem/D\n\n#include \"../../template.h\"\
    \n\nint block_sz;\nvector<int> a;\n \nstruct Query{\n    int l, r, idx;\n};\n\
    \ \nvector<Query> q;\n \nbool cmp(Query a, Query b){\n    if(a.l/block_sz != b.l/block_sz)\n\
    \        return a.l/block_sz < b.l/block_sz;\n    return a.r < b.r;\n}\n\nunordered_map<int,\
    \ int> fre;\nint cnt = 0;\n\nvoid insert(int i){\n    if(fre[a[i]] == a[i]) cnt--;\n\
    \    fre[a[i]]++;\n    if(fre[a[i]] == a[i]) cnt++;\n}\n \nvoid remove(int i){\n\
    \    if(fre[a[i]] == a[i]) cnt--;\n    fre[a[i]]--;\n    if(fre[a[i]] == a[i])\
    \ cnt++;\n}\n \nvector<int> query(){\n    sort(q.begin(), q.end(), cmp);\n   \
    \ int curL = 0, curR = 0;\n    vector<int> ans((int)q.size());\n    for(int i\
    \ = 0; i < (int)q.size(); i++){\n        auto [L, R, idx] = q[i];\n        while(curL\
    \ < L) remove(curL++);\n        while(curL > L) insert(--curL);\n        while(curR\
    \ <= R) insert(curR++);\n        while(curR > R+1) remove(--curR);\n        ans[idx]\
    \ = cnt;\n    }\n    return ans;\n}\n \nvoid solve(){\n    int n, t; cin >> n\
    \ >> t;\n    a.resize(n);\n    for(int i = 0; i < n; i++)\n        cin >> a[i];\n\
    \    for(int i = 0; i < t; i++){\n        int l, r; cin >> l >> r;\n        q.push_back({l-1,\
    \ r-1, i});\n    }\n    block_sz = sqrt(n);\n    vector<int> ans = query();\n\
    \    for(auto it : ans) cout << it << '\\n';\n}"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SqrtDecomposition/Mo/test1.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SqrtDecomposition/Mo/test1.cpp
layout: document
redirect_from:
- /library/DataStructure/SqrtDecomposition/Mo/test1.cpp
- /library/DataStructure/SqrtDecomposition/Mo/test1.cpp.html
title: DataStructure/SqrtDecomposition/Mo/test1.cpp
---
