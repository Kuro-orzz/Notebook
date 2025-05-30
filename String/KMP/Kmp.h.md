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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template.h:\
    \ line -1: no such header\n"
  code: "#include \"../template.h\"\n\nvector<int> lps(const string &s) {\n\tint n\
    \ = s.size();\n\tvector<int> pi(n);\n\tfor (int i = 1; i < n; i++) {\n\t\tint\
    \ j = pi[i-1];\n\t\twhile (j > 0 && s[i] != s[j]) {\n\t\t\tj = pi[j - 1];\n\t\t\
    }\n\t\tif (s[i] == s[j]) j++;\n\t\tpi[i] = j;\n\t}\n\treturn pi;\n}\n\nvector<int>\
    \ __KMP(const string &s, const string &t) {\n\tint n = s.size(), m = t.size();\n\
    \tif (n == 0) return {};\n\tvector<int> pi = lps(s);\n\tint j = 0;\n\tvector<int>\
    \ ans(m);\n\tfor (int i = 0; i < m; i++) {\n\t\twhile (j > 0 && t[i] != s[j])\
    \ {\n\t\t\tj = pi[j - 1];\n\t\t}\n\t\tif (t[i] == s[j]) j++;\n\t\tans[i] = j;\n\
    \t\tif (j == n) {\n\t\t\tj = pi[j - 1];\n\t\t}\n\t}\n\treturn ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/KMP/Kmp.h
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/KMP/Kmp.h
layout: document
redirect_from:
- /library/String/KMP/Kmp.h
- /library/String/KMP/Kmp.h.html
title: String/KMP/Kmp.h
---
