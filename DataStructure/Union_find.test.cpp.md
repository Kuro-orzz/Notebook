---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Dsu/Dsu.h: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../template.h\"\n#include \"Dsu/Dsu.h\"\n\nvoid solve(){\n    int n, q; cin\
    \ >> n >> q;\n    Dsu g(n+1);\n    while (q--) {\n        int tv, u, v; cin >>\
    \ tv >> u >> v;\n        if (tv == 0) g.merge(u, v);\n        else if (g.find(u)\
    \ == g.find(v))\n            cout << \"1\\n\";\n        else cout << \"0\\n\"\
    ;\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: DataStructure/Union_find.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: DataStructure/Union_find.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Union_find.test.cpp
- /verify/DataStructure/Union_find.test.cpp.html
title: DataStructure/Union_find.test.cpp
---
