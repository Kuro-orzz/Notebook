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
    - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template:\
    \ line -1: no such header\n"
  code: "#include \"../../template\"\n#include \"Kmp.h\"\n\n// AC: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/\n\
    \nclass Solution {\npublic:\n    int strStr(string haystack, string needle) {\n\
    \        int n = haystack.size(), m = needle.size();\n        vector<int> res\
    \ = __KMP(needle, haystack);\n        for (size_t i = 0; i < n; i++) {\n     \
    \       if (res[i] == m) return i - m + 1;\n        }\n        return -1;\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: String/KMP/test_kmp.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/KMP/test_kmp.cpp
layout: document
redirect_from:
- /library/String/KMP/test_kmp.cpp
- /library/String/KMP/test_kmp.cpp.html
title: String/KMP/test_kmp.cpp
---
