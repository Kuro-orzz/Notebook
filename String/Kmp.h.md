---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
  code: "#include \"../../template.h\"\n\nvector<int> lps(const string &s) {\n   \
    \ int n = s.size();\n    vector<int> pi(n);\n    for (int i = 1; i < n; i++) {\n\
    \        int j = pi[i-1];\n        while (j > 0 && s[i] != s[j]) {\n         \
    \   j = pi[j - 1];\n        }\n        if (s[i] == s[j]) j++;\n        pi[i] =\
    \ j;\n    }\n    return pi;\n}\n\nvector<int> __KMP(const string &s, const string\
    \ &t) {\n    int n = s.size(), m = t.size();\n    if (n == 0) return {};\n   \
    \ vector<int> pi = lps(s);\n    int j = 0;\n    vector<int> ans(m);\n    for (int\
    \ i = 0; i < m; i++) {\n        while (j > 0 && t[i] != s[j]) {\n            j\
    \ = pi[j - 1];\n        }\n        if (t[i] == s[j]) j++;\n        ans[i] = j;\n\
    \        if (j == n) {\n            j = pi[j - 1];\n        }\n    }\n    return\
    \ ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/Kmp.h
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Kmp.h
layout: document
redirect_from:
- /library/String/Kmp.h
- /library/String/Kmp.h.html
title: String/Kmp.h
---
