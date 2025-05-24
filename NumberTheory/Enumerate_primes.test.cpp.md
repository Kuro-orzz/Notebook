---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/CheckPrime.h
    title: NumberTheory/Math/CheckPrime.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Sieve.h
    title: NumberTheory/Math/Sieve.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"NumberTheory/Enumerate_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#line 2 \"template.h\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n\
    #define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64\
    \ ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n#define pii\
    \ pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define se second\n\
    \nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"NumberTheory/Math/CheckPrime.h\"\
    \n\n\nbool BruteForce(ll n) {\n    if (n == 2 || n == 3) return true;\n    if\
    \ (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;\n    for (ll i = 5; i * i\
    \ <= n; i += 6)\n        if (n % i == 0 || n % (i+2) == 0)\n            return\
    \ false;\n    return true;\n}\n\n// https://codeforces.com/blog/entry/91632\n\
    ll Meissel(ll n) {\n    vector<ll> v;\n    for (ll i = 1; i*i <= n; i++) {\n \
    \       v.push_back(i);\n        v.push_back(n / i);\n    }\n    sort(all(v));\n\
    \    unique(v);\n    ll sq = sqrt(n);\n    auto geti = [&](ll x) {\n        if\
    \ (x <= sq) return x-1;\n        return (int)v.size() - n / x;\n    };\n    vector<ll>\
    \ dp = v;\n    ll a = 0;\n    for (ll p = 2; p*p <= n; p++) {\n        if (dp[geti(p)]\
    \ == dp[geti(p-1)]) continue;\n        a++;\n        for (int i = (int)v.size()-1;\
    \ i >= 0; i--) {\n            if (v[i] < p * p) break;\n            dp[i] -= dp[geti(v[i]\
    \ / p)] - a;\n        }\n    }\n    return dp[geti(n)] - 1;\n}\n#line 2 \"NumberTheory/Math/Sieve.h\"\
    \n\nvector<int> sieve(int n) {\n\tvector<int> nt(n+1, 1);\n\tnt[0] = nt[1] = 0;\n\
    \tfor (int i = 2; i * i <= n; i++) {\n\t\tif (!nt[i]) continue;\n\t\tfor (int\
    \ j = i * i; j <= n; j += i)\n\t\t\tnt[j] = 0;\n\t}\n\treturn nt;\n}\n\nvector<int>\
    \ segmentSieve(int l, int r){\n\tvector<int> prime(r-l+1, 1);\n\tfor(ll p = 2;\
    \ p*p <= r; p++){\n\t\tll lim = max(p*p, (l+p-1)/p*p);\n\t\tfor(ll j = lim; j\
    \ <= r; j += p)\n\t\t\tif (j-l >= 0) prime[j-l] = 0;\n\t}\n\tif (l == 0) prime[0]\
    \ = 0;\n\tif (l == 0 && r > l) prime[1] = 0;\n\tif (l == 1) prime[1-l] = 0;\n\t\
    return prime;\n}\n\nvector<int> listPrime(int l, int r) {\n\tvector<int> prime\
    \ = segmentSieve(l, r);\n\tvector<int> listPi;\n\tfor (int i = l; i <= r; i++)\
    \ {\n\t\tif (prime[i-l]) listPi.push_back(i);\n\t}\n\treturn listPi;\n}\n#line\
    \ 6 \"NumberTheory/Enumerate_primes.test.cpp\"\n\nvoid solve() {\n\tint n, a,\
    \ b; cin >> n >> a >> b;\n\tll cnt_pi = Meissel(n);\n\t\n\tint lim = 1e6;\n\t\
    vector<int> need;\n\tint i = 0;\n\twhile (a*i + b <= n && (int)need.size() < lim)\
    \ {\n\t\tneed.push_back(a*i+b);\n\t\ti++;\n\t}\n\n\tvector<int> prime = listPrime(0,\
    \ lim);\n\tvector<int> res;\n\tint cnt = 0, idx = 0;\n\tfor (int l = 2; l <= n;\
    \ l += lim) {\n\t\tint r = min(l + lim - 1, n);\n\t\tvector<int> isPrime(r - l\
    \ + 1, 1);\n\t\tfor (int p : prime) {\n\t\t\tll low = max(1ll*p*p, 1ll*(l+p-1)/p*p);\n\
    \t\t\tfor (ll j = low; j <= r; j += p) {\n\t\t\t\tif (j-l >= 0) isPrime[j-l] =\
    \ 0;\n\t\t\t}\n\t\t}\n\t\t// vector<int> isPrime = segmentSieve(l, r);\n\n\t\t\
    for (int p = l; p <= min(r, n); p++) {\n\t\t\tif (!isPrime[p-l]) continue;\n\t\
    \t\tif (cnt == need[idx]) {\n\t\t\t\tres.push_back(p);\n\t\t\t\tidx++;\n\t\t\t\
    }\n\t\t\tcnt++;\n\t\t\tif (idx == (int)need.size()) break;\n\t\t}\n\n\t\tif (idx\
    \ == (int)need.size()) break;\n\t}\n\n\tcout << cnt_pi << ' ' << res.size() <<\
    \ '\\n';\n\tfor (int x : res) cout << x << ' ';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include \"../template.h\"\n#include \"Math/CheckPrime.h\"\n#include \"Math/Sieve.h\"\
    \n\nvoid solve() {\n\tint n, a, b; cin >> n >> a >> b;\n\tll cnt_pi = Meissel(n);\n\
    \t\n\tint lim = 1e6;\n\tvector<int> need;\n\tint i = 0;\n\twhile (a*i + b <= n\
    \ && (int)need.size() < lim) {\n\t\tneed.push_back(a*i+b);\n\t\ti++;\n\t}\n\n\t\
    vector<int> prime = listPrime(0, lim);\n\tvector<int> res;\n\tint cnt = 0, idx\
    \ = 0;\n\tfor (int l = 2; l <= n; l += lim) {\n\t\tint r = min(l + lim - 1, n);\n\
    \t\tvector<int> isPrime(r - l + 1, 1);\n\t\tfor (int p : prime) {\n\t\t\tll low\
    \ = max(1ll*p*p, 1ll*(l+p-1)/p*p);\n\t\t\tfor (ll j = low; j <= r; j += p) {\n\
    \t\t\t\tif (j-l >= 0) isPrime[j-l] = 0;\n\t\t\t}\n\t\t}\n\t\t// vector<int> isPrime\
    \ = segmentSieve(l, r);\n\n\t\tfor (int p = l; p <= min(r, n); p++) {\n\t\t\t\
    if (!isPrime[p-l]) continue;\n\t\t\tif (cnt == need[idx]) {\n\t\t\t\tres.push_back(p);\n\
    \t\t\t\tidx++;\n\t\t\t}\n\t\t\tcnt++;\n\t\t\tif (idx == (int)need.size()) break;\n\
    \t\t}\n\n\t\tif (idx == (int)need.size()) break;\n\t}\n\n\tcout << cnt_pi << '\
    \ ' << res.size() << '\\n';\n\tfor (int x : res) cout << x << ' ';\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/CheckPrime.h
  - NumberTheory/Math/Sieve.h
  isVerificationFile: true
  path: NumberTheory/Enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2025-05-25 00:26:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Enumerate_primes.test.cpp
- /verify/NumberTheory/Enumerate_primes.test.cpp.html
title: NumberTheory/Enumerate_primes.test.cpp
---
