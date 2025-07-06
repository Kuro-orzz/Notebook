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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Misc/ModInt.h:\
    \ line -1: no such header\n"
  code: "#include \"../../template.h\"\n#include \"../../Misc/ModInt.h\"\n#include\
    \ \"Binary_exponentiation.h\"\n\n// This modint only work for MOD is prime cuz\
    \ using modulo inverse\n// using mint = ModInt<MOD>;\n\n// vector<mint> fact;\n\
    \n// void preprocess() {\n//     fact[0] = 1;\n//     for (int i = 1; i < (int)fact.size();\
    \ i++) {\n//         fact[i] = fact[i-1] * i;\n//     }\n// }\n\n// mint comb(int\
    \ n, int k) {\n//     if (k < 0 || k > n) return 0; \n//     return fact[n] /\
    \ (fact[n-k] * fact[k]);\n// }\n\n\n// Using for n * k <= 1e7 or n,k <= 5000,\
    \ O(1) per operation\nvector<vector<int>> preprocess(int n, int k, int m) {\n\
    \    vector<vector<int>> C(n+1, vector<int>(k+1));\n    for (int i = 0; i <= n;\
    \ i++) {\n        C[i][0] = 1;\n        for (int j = 1; j <= min(i, k); j++) {\n\
    \            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % m;\n        }\n    }\n    return\
    \ C;\n}\n\n// Using for n, k <= 1e6, MOD is prime\nconst int N = 1e6 + 6;\nvector<ll>\
    \ fact(N), inv(N), invFact(N);\n\nvoid preprocess() {\n    fact[0] = 1;\n    for\
    \ (int i = 1; i < N; i++) {\n        fact[i] = fact[i-1] * i % MOD;\n    }\n \
    \   invFact[0] = invFact[1] = 1;\n    inv[1] = 1;\n    for(int i = 2; i < N; i++)\
    \ {\n        inv[i] = MOD - (ll)(MOD/i) * inv[MOD%i] % MOD;\n        invFact[i]\
    \ = invFact[i-1] * inv[i] % MOD;\n    }\n    // Optional\n    // invFact[N-1]\
    \ = binPow(fact[N-1], MOD-2, MOD);\n    // for (int i = N-2; i >= 0; i--) {\n\
    \    //     invFact[i] = invFact[i+1] * (i + 1) % MOD;\n    // }\n}\n\n// m must\
    \ be prime\n// fermat's little theorem a^(m-2) \u2261 a^(-1)\nll inverse1(ll a,\
    \ ll m) { return binPow(a, m-2, m); }\n// m coprime to a, gcd(a, m) = 1\n// base\
    \ on extended euclid trick\nll inverse2(ll a, ll m) { return a <= 1 ? a : m-m/a\
    \ * inverse2(m % a, m) % m; }\n\nll comb(int n, int k) {\n    if (k < 0 || k >\
    \ n) return 0;\n    // ll t = binMul(fact[k], fact[n-k], MOD);\n    // return\
    \ fact[n] * inverse2(t, MOD) % MOD;\n    return fact[n] * invFact[k] % MOD * invFact[n-k]\
    \ % MOD;\n}"
  dependsOn: []
  isVerificationFile: false
  path: NumberTheory/Math/Combination.h
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/Math/Combination.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Combination.h
- /library/NumberTheory/Math/Combination.h.html
title: NumberTheory/Math/Combination.h
---
