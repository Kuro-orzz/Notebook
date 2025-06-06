---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Big_Integer/BigInt_full.h\"\n\nconst int BASE_DIGITS = 9;\n\
    const int BASE = 1'000'000'000;\n\nclass BigInt {\npublic:\n    int sign;\n  \
    \  vector<uint32_t> digit;\n\n    BigInt(): sign(1) {}\n\n    BigInt(const string\
    \ &s) { *this = s; }\n\n    BigInt(int64_t val) { *this = val; }\n\n    BigInt\
    \ &operator = (const BigInt &b) {\n        sign = b.sign;\n        digit = b.digit;\n\
    \        return *this;\n    }\n\n    BigInt &operator = (const string &s) {\n\
    \        read(s);\n        return *this;\n    }\n\n    BigInt &operator = (int64_t\
    \ val) {\n        sign = val >= 0 ? 1 : -1;\n        val = llabs(val);\n     \
    \   digit.clear();\n        for (; val; val /= BASE) {\n            digit.push_back(val\
    \ % BASE);\n        }\n        return *this;\n    }\n\n    BigInt &operator +=\
    \ (const BigInt &b) {\n        if (sign != b.sign) {\n            BigInt t = b;\n\
    \            t.sign *= -1;\n            return *this -= t;\n        }\n      \
    \  int carry = 0, len = (int)max(size(), b.size());\n        for (size_t i = 0;\
    \ i < len; i++) {\n            int sum = carry;\n            if (i < size()) sum\
    \ += digit[i];\n            if (i < b.size()) sum += b[i];\n            if (i\
    \ < size()) digit[i] = sum % BASE;\n            else digit.push_back(sum % BASE);\n\
    \            carry = sum / BASE;\n        }\n        if (carry) digit.push_back(carry);\n\
    \        trim();\n        return *this;\n    }\n\n    BigInt &operator -= (const\
    \ BigInt &b) {\n        if (sign != b.sign) {\n            return *this += (-b);\n\
    \        }\n        if (__compare_abs(b) == -1) {\n            BigInt t = b;\n\
    \            t -= *this;\n            t.sign *= -1;\n            return *this\
    \ = t;\n        }\n        int borrow = 0, len = (int)max(size(), b.size());\n\
    \        for (size_t i = 0; i < len; i++) {\n            int sub = -borrow;\n\
    \            if (i < size()) sub += digit[i];\n            if (i < b.size()) sub\
    \ -= b[i];\n            if (sub < 0) sub += BASE, borrow = 1;\n            else\
    \ borrow = 0;\n            digit[i] = sub;\n        }\n        trim();\n     \
    \   return *this;\n    }\n\n    BigInt &operator *= (const BigInt &b) {\n    \
    \    return *this = karatsuba(*this, b);\n    }\n\n    // BigInt += Int\n    BigInt\
    \ &operator += (int64_t t) { return *this += BigInt(t); }\n    BigInt &operator\
    \ -= (int64_t t) { return *this -= BigInt(t); }\n    BigInt &operator *= (int64_t\
    \ t) { return *this *= BigInt(t); }\n\n    BigInt operator - () const { \n   \
    \     BigInt res = *this;\n        if (!res.isZero()) res.sign *= -1;\n      \
    \  return res;\n    } // -a;\n    BigInt operator + () const { return BigInt(*this);\
    \ } // +a;\n    BigInt &operator ++ () { *this += 1; return *this; } // ++a;\n\
    \    BigInt &operator -- () { *this -= 1; return *this; } // --a;\n    BigInt\
    \ operator ++ (int) {BigInt res = *this; *this += 1; return res;} // a++;\n  \
    \  BigInt operator -- (int) {BigInt res = *this; *this -= 1; return res;} // a--;\n\
    \n    // BigInt = BigInt + BigInt\n    BigInt operator + (const BigInt &b) const\
    \ { return BigInt(*this) += b; }\n    BigInt operator - (const BigInt &b) const\
    \ { return BigInt(*this) -= b; }\n    BigInt operator * (const BigInt &b) const\
    \ { return BigInt(*this) *= b; }\n\n    // BigInt = BigInt + Int\n    BigInt operator\
    \ + (int64_t t) const { return BigInt(*this) += t; }\n    BigInt operator - (int64_t\
    \ t) const { return BigInt(*this) -= t; }\n    BigInt operator * (int64_t t) const\
    \ { return BigInt(*this) *= t; }\n\n    // BigInt = Int + BigInt\n    friend BigInt\
    \ operator + (int64_t t, const BigInt &b) { BigInt res(t); res += b; return res;\
    \ }\n    friend BigInt operator - (int64_t t, const BigInt &b) { BigInt res(t);\
    \ res -= b; return res; }\n    friend BigInt operator * (int64_t t, const BigInt\
    \ &b) { BigInt res(t); res *= b; return res; }\n\n    uint32_t operator [] (const\
    \ int i) const { assert(i >= 0 && i < size()); return digit[i]; }\n    uint32_t\
    \ &operator [] (const int i) { assert(i >= 0 && i < size()); return digit[i];\
    \ }\n\n    // ------------------------- Comparison ---------------------\n   \
    \ bool operator < (const BigInt &b) const {\n        if (sign != b.sign) {\n \
    \           return sign < b.sign;\n        }\n        if (size() != b.size())\
    \ {\n            return size() * sign < b.size() * b.sign;\n        }\n      \
    \  for (int i = (int)size() - 1; i >= 0; i--) {\n            if ((*this)[i] !=\
    \ b[i]) {\n                return (*this)[i] * sign < b[i] * sign;\n         \
    \   }\n        }\n        return false;\n    }\n\n    bool operator > (const BigInt\
    \ &b) const { return b < *this; }\n    bool operator <= (const BigInt &b) const\
    \ { return !(b < *this); }\n    bool operator >= (const BigInt &b) const { return\
    \ !(*this < b); }\n    bool operator == (const BigInt &b) const { return !(*this\
    \ < b) && !(b < *this); }\n    bool operator != (const BigInt &b) const { return\
    \ *this < b || b < *this; }\n\n    bool operator == (int64_t t) const { return\
    \ *this == BigInt(t); }\n    bool operator != (int64_t t) const { return *this\
    \ != BigInt(t); }\n    bool operator < (int64_t t) const { return *this < BigInt(t);\
    \ }\n    bool operator <= (int64_t t) const { return *this <= BigInt(t); }\n \
    \   bool operator > (int64_t t) const { return *this > BigInt(t); }\n    bool\
    \ operator >= (int64_t t) const { return *this >= BigInt(t); }\n\n    // 0 if\
    \ |a| == |b|\n    // -1 if |a| < |b|\n    // 1 if |a| > |b|\n    int __compare_abs(const\
    \ BigInt &b) {\n        if (size() != b.size()) {\n            return size() <\
    \ b.size() ? -1 : 1;\n        }\n        for (int i = (int)size() - 1; i >= 0;\
    \ i--) {\n            if ((*this)[i] != b[i]) {\n                return (*this)[i]\
    \ < b[i] ? -1 : 1;\n            }\n        }\n        return 0;\n    }\n\n   \
    \ // -------------------- karatsuba ---------------------\n    BigInt mul_simple(const\
    \ BigInt &a, const BigInt &b) {\n        BigInt x = a, y = b;\n        BigInt\
    \ res;\n        res.sign = x.sign * y.sign;\n        res.digit.resize(x.size()\
    \ + y.size());\n        for (int i = 0; i < (int)x.size(); i++) {\n          \
    \  uint64_t carry = 0;\n            for (int j = 0; j < (int)y.size(); j++) {\n\
    \                uint64_t cur = res[i+j] + carry;\n                cur += 1ull\
    \ * x[i] * y[j];\n                res[i+j] = cur % BASE;\n                carry\
    \ = cur / BASE;\n            }\n            if (carry) res[i+(int)y.size()] +=\
    \ carry;\n        }\n        res.trim();\n        if (res.isZero()) res.sign =\
    \ 1;\n        return res;\n    }\n\n    BigInt shifted(int k) const {\n      \
    \  if (isZero()) return *this;\n        BigInt r = *this;\n        r.digit.insert(r.digit.begin(),\
    \ k, 0);\n        return r;\n    }\n\n    BigInt karatsuba(const BigInt &a, const\
    \ BigInt &b) {\n        if (a.size() < 32 || b.size() < 32) {\n            return\
    \ mul_simple(a, b);\n        }\n        size_t n = max(a.size(), b.size());\n\
    \        size_t k = n / 2;\n\n        BigInt a_low, a_high, b_low, b_high;\n \
    \       int m1 = min(k, a.size()), m2 = min(k, b.size());\n        a_low.digit.assign(a.digit.begin(),\
    \ a.digit.begin() + m1);\n        a_high.digit.assign(a.digit.begin() + m1, a.digit.end());\n\
    \        b_low.digit.assign(b.digit.begin(), b.digit.begin() + m2);\n        b_high.digit.assign(b.digit.begin()\
    \ + m2, b.digit.end());\n        a_low.sign = a_high.sign = b_low.sign = b_high.sign\
    \ = 1;\n        a_low.trim(); a_high.trim();\n        b_low.trim(); b_high.trim();\n\
    \n\n        BigInt z0 = karatsuba(a_low, b_low);\n        BigInt z1 = karatsuba(a_high,\
    \ b_high);\n        BigInt z2 = karatsuba(a_low + a_high, b_low + b_high) - z1\
    \ - z0;\n        BigInt res = z1.shifted(2 * k) + z2.shifted(k) + z0;\n      \
    \  res.trim();\n        res.sign = (a.sign != b.sign ? -1 : 1);\n        return\
    \ res;\n    }\n\n    // ------------------------- Misc ---------------------------\n\
    \    size_t size() const { return digit.size(); }\n\n    bool isZero() const {\
    \ return digit.empty(); }\n\n    void trim() {\n        while (!digit.empty()\
    \ && !digit.back()) {\n            digit.pop_back();\n        }\n        if (digit.empty())\
    \ sign = 1;\n    }\n\n    // ---------------------- Input Output ---------------------\n\
    \    /* only use for decim number */\n    void read(const string &s) {\n     \
    \   sign = (s[0] == '-' ? -1 : 1);\n        digit.clear();\n        int pos =\
    \ (s[0] == '-' ? 1 : 0);\n        for (int i = (int)s.size() - 1; i >= pos; i\
    \ -= BASE_DIGITS) {\n            int x = 0;\n            int k = max(pos, i -\
    \ BASE_DIGITS + 1);\n            for (int j = k; j <= i; j++) {\n            \
    \    x = x * 10 + (s[j] - '0');\n            }\n            digit.push_back(x);\n\
    \        }\n        trim();\n    }\n\n    friend istream &operator >> (istream\
    \ &in, BigInt &a) {\n        string s; in >> s;\n        a.read(s);\n        return\
    \ in;\n    }\n\n    friend ostream &operator << (ostream &out, const BigInt &a)\
    \ {\n        if (a.sign == -1 && !a.isZero()) out << '-';\n        out << (a.digit.empty()\
    \ ? 0 : a.digit.back());\n        for (int i = (int)a.size() - 2; i >= 0; i--)\n\
    \            out << setw(BASE_DIGITS) << setfill('0') << a[i];\n        return\
    \ out;\n    }\n};\n"
  code: "#include \"../template.h\"\n\nconst int BASE_DIGITS = 9;\nconst int BASE\
    \ = 1'000'000'000;\n\nclass BigInt {\npublic:\n    int sign;\n    vector<uint32_t>\
    \ digit;\n\n    BigInt(): sign(1) {}\n\n    BigInt(const string &s) { *this =\
    \ s; }\n\n    BigInt(int64_t val) { *this = val; }\n\n    BigInt &operator = (const\
    \ BigInt &b) {\n        sign = b.sign;\n        digit = b.digit;\n        return\
    \ *this;\n    }\n\n    BigInt &operator = (const string &s) {\n        read(s);\n\
    \        return *this;\n    }\n\n    BigInt &operator = (int64_t val) {\n    \
    \    sign = val >= 0 ? 1 : -1;\n        val = llabs(val);\n        digit.clear();\n\
    \        for (; val; val /= BASE) {\n            digit.push_back(val % BASE);\n\
    \        }\n        return *this;\n    }\n\n    BigInt &operator += (const BigInt\
    \ &b) {\n        if (sign != b.sign) {\n            BigInt t = b;\n          \
    \  t.sign *= -1;\n            return *this -= t;\n        }\n        int carry\
    \ = 0, len = (int)max(size(), b.size());\n        for (size_t i = 0; i < len;\
    \ i++) {\n            int sum = carry;\n            if (i < size()) sum += digit[i];\n\
    \            if (i < b.size()) sum += b[i];\n            if (i < size()) digit[i]\
    \ = sum % BASE;\n            else digit.push_back(sum % BASE);\n            carry\
    \ = sum / BASE;\n        }\n        if (carry) digit.push_back(carry);\n     \
    \   trim();\n        return *this;\n    }\n\n    BigInt &operator -= (const BigInt\
    \ &b) {\n        if (sign != b.sign) {\n            return *this += (-b);\n  \
    \      }\n        if (__compare_abs(b) == -1) {\n            BigInt t = b;\n \
    \           t -= *this;\n            t.sign *= -1;\n            return *this =\
    \ t;\n        }\n        int borrow = 0, len = (int)max(size(), b.size());\n \
    \       for (size_t i = 0; i < len; i++) {\n            int sub = -borrow;\n \
    \           if (i < size()) sub += digit[i];\n            if (i < b.size()) sub\
    \ -= b[i];\n            if (sub < 0) sub += BASE, borrow = 1;\n            else\
    \ borrow = 0;\n            digit[i] = sub;\n        }\n        trim();\n     \
    \   return *this;\n    }\n\n    BigInt &operator *= (const BigInt &b) {\n    \
    \    return *this = karatsuba(*this, b);\n    }\n\n    // BigInt += Int\n    BigInt\
    \ &operator += (int64_t t) { return *this += BigInt(t); }\n    BigInt &operator\
    \ -= (int64_t t) { return *this -= BigInt(t); }\n    BigInt &operator *= (int64_t\
    \ t) { return *this *= BigInt(t); }\n\n    BigInt operator - () const { \n   \
    \     BigInt res = *this;\n        if (!res.isZero()) res.sign *= -1;\n      \
    \  return res;\n    } // -a;\n    BigInt operator + () const { return BigInt(*this);\
    \ } // +a;\n    BigInt &operator ++ () { *this += 1; return *this; } // ++a;\n\
    \    BigInt &operator -- () { *this -= 1; return *this; } // --a;\n    BigInt\
    \ operator ++ (int) {BigInt res = *this; *this += 1; return res;} // a++;\n  \
    \  BigInt operator -- (int) {BigInt res = *this; *this -= 1; return res;} // a--;\n\
    \n    // BigInt = BigInt + BigInt\n    BigInt operator + (const BigInt &b) const\
    \ { return BigInt(*this) += b; }\n    BigInt operator - (const BigInt &b) const\
    \ { return BigInt(*this) -= b; }\n    BigInt operator * (const BigInt &b) const\
    \ { return BigInt(*this) *= b; }\n\n    // BigInt = BigInt + Int\n    BigInt operator\
    \ + (int64_t t) const { return BigInt(*this) += t; }\n    BigInt operator - (int64_t\
    \ t) const { return BigInt(*this) -= t; }\n    BigInt operator * (int64_t t) const\
    \ { return BigInt(*this) *= t; }\n\n    // BigInt = Int + BigInt\n    friend BigInt\
    \ operator + (int64_t t, const BigInt &b) { BigInt res(t); res += b; return res;\
    \ }\n    friend BigInt operator - (int64_t t, const BigInt &b) { BigInt res(t);\
    \ res -= b; return res; }\n    friend BigInt operator * (int64_t t, const BigInt\
    \ &b) { BigInt res(t); res *= b; return res; }\n\n    uint32_t operator [] (const\
    \ int i) const { assert(i >= 0 && i < size()); return digit[i]; }\n    uint32_t\
    \ &operator [] (const int i) { assert(i >= 0 && i < size()); return digit[i];\
    \ }\n\n    // ------------------------- Comparison ---------------------\n   \
    \ bool operator < (const BigInt &b) const {\n        if (sign != b.sign) {\n \
    \           return sign < b.sign;\n        }\n        if (size() != b.size())\
    \ {\n            return size() * sign < b.size() * b.sign;\n        }\n      \
    \  for (int i = (int)size() - 1; i >= 0; i--) {\n            if ((*this)[i] !=\
    \ b[i]) {\n                return (*this)[i] * sign < b[i] * sign;\n         \
    \   }\n        }\n        return false;\n    }\n\n    bool operator > (const BigInt\
    \ &b) const { return b < *this; }\n    bool operator <= (const BigInt &b) const\
    \ { return !(b < *this); }\n    bool operator >= (const BigInt &b) const { return\
    \ !(*this < b); }\n    bool operator == (const BigInt &b) const { return !(*this\
    \ < b) && !(b < *this); }\n    bool operator != (const BigInt &b) const { return\
    \ *this < b || b < *this; }\n\n    bool operator == (int64_t t) const { return\
    \ *this == BigInt(t); }\n    bool operator != (int64_t t) const { return *this\
    \ != BigInt(t); }\n    bool operator < (int64_t t) const { return *this < BigInt(t);\
    \ }\n    bool operator <= (int64_t t) const { return *this <= BigInt(t); }\n \
    \   bool operator > (int64_t t) const { return *this > BigInt(t); }\n    bool\
    \ operator >= (int64_t t) const { return *this >= BigInt(t); }\n\n    // 0 if\
    \ |a| == |b|\n    // -1 if |a| < |b|\n    // 1 if |a| > |b|\n    int __compare_abs(const\
    \ BigInt &b) {\n        if (size() != b.size()) {\n            return size() <\
    \ b.size() ? -1 : 1;\n        }\n        for (int i = (int)size() - 1; i >= 0;\
    \ i--) {\n            if ((*this)[i] != b[i]) {\n                return (*this)[i]\
    \ < b[i] ? -1 : 1;\n            }\n        }\n        return 0;\n    }\n\n   \
    \ // -------------------- karatsuba ---------------------\n    BigInt mul_simple(const\
    \ BigInt &a, const BigInt &b) {\n        BigInt x = a, y = b;\n        BigInt\
    \ res;\n        res.sign = x.sign * y.sign;\n        res.digit.resize(x.size()\
    \ + y.size());\n        for (int i = 0; i < (int)x.size(); i++) {\n          \
    \  uint64_t carry = 0;\n            for (int j = 0; j < (int)y.size(); j++) {\n\
    \                uint64_t cur = res[i+j] + carry;\n                cur += 1ull\
    \ * x[i] * y[j];\n                res[i+j] = cur % BASE;\n                carry\
    \ = cur / BASE;\n            }\n            if (carry) res[i+(int)y.size()] +=\
    \ carry;\n        }\n        res.trim();\n        if (res.isZero()) res.sign =\
    \ 1;\n        return res;\n    }\n\n    BigInt shifted(int k) const {\n      \
    \  if (isZero()) return *this;\n        BigInt r = *this;\n        r.digit.insert(r.digit.begin(),\
    \ k, 0);\n        return r;\n    }\n\n    BigInt karatsuba(const BigInt &a, const\
    \ BigInt &b) {\n        if (a.size() < 32 || b.size() < 32) {\n            return\
    \ mul_simple(a, b);\n        }\n        size_t n = max(a.size(), b.size());\n\
    \        size_t k = n / 2;\n\n        BigInt a_low, a_high, b_low, b_high;\n \
    \       int m1 = min(k, a.size()), m2 = min(k, b.size());\n        a_low.digit.assign(a.digit.begin(),\
    \ a.digit.begin() + m1);\n        a_high.digit.assign(a.digit.begin() + m1, a.digit.end());\n\
    \        b_low.digit.assign(b.digit.begin(), b.digit.begin() + m2);\n        b_high.digit.assign(b.digit.begin()\
    \ + m2, b.digit.end());\n        a_low.sign = a_high.sign = b_low.sign = b_high.sign\
    \ = 1;\n        a_low.trim(); a_high.trim();\n        b_low.trim(); b_high.trim();\n\
    \n\n        BigInt z0 = karatsuba(a_low, b_low);\n        BigInt z1 = karatsuba(a_high,\
    \ b_high);\n        BigInt z2 = karatsuba(a_low + a_high, b_low + b_high) - z1\
    \ - z0;\n        BigInt res = z1.shifted(2 * k) + z2.shifted(k) + z0;\n      \
    \  res.trim();\n        res.sign = (a.sign != b.sign ? -1 : 1);\n        return\
    \ res;\n    }\n\n    // ------------------------- Misc ---------------------------\n\
    \    size_t size() const { return digit.size(); }\n\n    bool isZero() const {\
    \ return digit.empty(); }\n\n    void trim() {\n        while (!digit.empty()\
    \ && !digit.back()) {\n            digit.pop_back();\n        }\n        if (digit.empty())\
    \ sign = 1;\n    }\n\n    // ---------------------- Input Output ---------------------\n\
    \    /* only use for decim number */\n    void read(const string &s) {\n     \
    \   sign = (s[0] == '-' ? -1 : 1);\n        digit.clear();\n        int pos =\
    \ (s[0] == '-' ? 1 : 0);\n        for (int i = (int)s.size() - 1; i >= pos; i\
    \ -= BASE_DIGITS) {\n            int x = 0;\n            int k = max(pos, i -\
    \ BASE_DIGITS + 1);\n            for (int j = k; j <= i; j++) {\n            \
    \    x = x * 10 + (s[j] - '0');\n            }\n            digit.push_back(x);\n\
    \        }\n        trim();\n    }\n\n    friend istream &operator >> (istream\
    \ &in, BigInt &a) {\n        string s; in >> s;\n        a.read(s);\n        return\
    \ in;\n    }\n\n    friend ostream &operator << (ostream &out, const BigInt &a)\
    \ {\n        if (a.sign == -1 && !a.isZero()) out << '-';\n        out << (a.digit.empty()\
    \ ? 0 : a.digit.back());\n        for (int i = (int)a.size() - 2; i >= 0; i--)\n\
    \            out << setw(BASE_DIGITS) << setfill('0') << a[i];\n        return\
    \ out;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Big_Integer/BigInt_full.h
  requiredBy: []
  timestamp: '2025-06-07 01:29:16+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Big_Integer/BigInt_full.h
layout: document
redirect_from:
- /library/Big_Integer/BigInt_full.h
- /library/Big_Integer/BigInt_full.h.html
title: Big_Integer/BigInt_full.h
---
