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
    \ 0;\n}\n#line 2 \"Misc/Modint.h\"\n\ntemplate <int32_t mod>\nstruct ModInt {\n\
    \tint32_t x;\n\n\tModInt(): x(0) {}\n\tModInt(int32_t _x): x(_x % mod) { x = x\
    \ < 0 ? x + mod : x; }\n\n\tModInt &operator += (const ModInt &p) {\n\t\tx +=\
    \ p.x;\n\t\tif (x >= mod) x -= mod;\n\t\treturn *this;\n\t}\n\n\tModInt &operator\
    \ -= (const ModInt &p) {\n\t\tx -= p.x;\n\t\tif (x < 0) x += mod;\n\t\treturn\
    \ *this;\n\t}\n\n\tModInt &operator *= (const ModInt &p) {\n\t\tx = (int32_t)(1ll\
    \ * x * p.x % mod);\n\t\treturn *this; \n\t}\n\n\tModInt &operator /= (const ModInt\
    \ &p) {\n\t\t*this *= p.inverse();\n\t\treturn *this;\n\t}\n\n\t// ModInt += Int\n\
    \tModInt &operator += (int32_t t) { return *this += ModInt(t); }\n\tModInt &operator\
    \ -= (int32_t t) { return *this -= ModInt(t); }\n\tModInt &operator *= (int32_t\
    \ t) { return *this *= ModInt(t); }\n\tModInt &operator /= (int32_t t) { return\
    \ *this /= ModInt(t); }\n\n\tModInt operator - () const { return ModInt(-x); }\
    \ // -a;\n\tModInt operator + () const { return ModInt(*this); } // +a;\n\tModInt\
    \ &operator ++ () { *this += 1; return *this; } // ++a;\n\tModInt &operator --\
    \ () { *this -= 1; return *this; } // --a;\n\tModInt operator ++ (int) { ModInt\
    \ res = *this; *this += 1; return res; } // a++;\n\tModInt operator -- (int) {\
    \ ModInt res = *this; *this -= 1; return res; } // a--;\n\n\t// ModInt = ModInt\
    \ + ModInt\n\tModInt operator + (const ModInt &p) const { return ModInt(*this)\
    \ += p; }\n\tModInt operator - (const ModInt &p) const { return ModInt(*this)\
    \ -= p; }\n\tModInt operator * (const ModInt &p) const { return ModInt(*this)\
    \ *= p; }\n\tModInt operator / (const ModInt &p) const { return ModInt(*this)\
    \ /= p; }\n\n\t// ModInt = ModInt + Int\n\tModInt operator + (int32_t t) const\
    \ { return ModInt(*this) += t; }\n\tModInt operator - (int32_t t) const { return\
    \ ModInt(*this) -= t; }\n\tModInt operator * (int32_t t) const { return ModInt(*this)\
    \ *= t; }\n\tModInt operator / (int32_t t) const { return ModInt(*this) /= t;\
    \ }\n\n\t// ModInt = Int + ModInt\n\tfriend ModInt operator + (int32_t t, const\
    \ ModInt &p) { ModInt res(t); res += p; return res; }\n\tfriend ModInt operator\
    \ - (int32_t t, const ModInt &p) { ModInt res(t); res -= p; return res; }\n\t\
    friend ModInt operator * (int32_t t, const ModInt &p) { ModInt res(t); res *=\
    \ p; return res; }\n\tfriend ModInt operator / (int32_t t, const ModInt &p) {\
    \ ModInt res(t); res /= p; return res; }\n\n\tbool operator == (const ModInt &p)\
    \ const { return x == p.x; }\n\tbool operator != (const ModInt &p) const { return\
    \ x != p.x; }\n\tbool operator < (const ModInt &p) const { return x < p.x; }\n\
    \tbool operator <= (const ModInt &p) const { return x <= p.x; }\n\tbool operator\
    \ > (const ModInt &p) const { return x > p.x; }\n\tbool operator >= (const ModInt\
    \ &p) const { return x >= p.x; }\n\n\tbool operator == (int32_t t) const { return\
    \ x == t; }\n\tbool operator != (int32_t t) const { return x != t; }\n\tbool operator\
    \ < (int32_t t) const { return x < t; }\n\tbool operator <= (int32_t t) const\
    \ { return x <= t; }\n\tbool operator > (int32_t t) const { return x > t; }\n\t\
    bool operator >= (int32_t t) const { return x >= t; }\n\n\tModInt inverse() const\
    \ { return power(mod - 2); }\n\n\tModInt power(int32_t b) const {\n\t\tassert(b\
    \ >= 0);\n\t\tModInt mul(x), ret(1);\n\t\twhile (b) {\n\t\t\tif (b & 1) ret *=\
    \ mul;\n\t\t\tmul *= mul;\n\t\t\tb /= 2;\n\t\t}\n\t\treturn ret;\n\t}\n\n\tfriend\
    \ istream &operator >> (istream &in, ModInt &p) { \n\t\tint32_t t;\n\t\tin >>\
    \ t;\n\t\tp = ModInt<mod>(t);\n\t\treturn in;\n\t}\n\t\n\tfriend ostream &operator\
    \ << (ostream &out, const ModInt &p) { return out << p.x; }\n\n\tint32_t get()\
    \ const { return x; }\n\tstatic constexpr int32_t get_mod() { return mod; }\n\
    };\n"
  code: "#include \"../template.h\"\n\ntemplate <int32_t mod>\nstruct ModInt {\n\t\
    int32_t x;\n\n\tModInt(): x(0) {}\n\tModInt(int32_t _x): x(_x % mod) { x = x <\
    \ 0 ? x + mod : x; }\n\n\tModInt &operator += (const ModInt &p) {\n\t\tx += p.x;\n\
    \t\tif (x >= mod) x -= mod;\n\t\treturn *this;\n\t}\n\n\tModInt &operator -= (const\
    \ ModInt &p) {\n\t\tx -= p.x;\n\t\tif (x < 0) x += mod;\n\t\treturn *this;\n\t\
    }\n\n\tModInt &operator *= (const ModInt &p) {\n\t\tx = (int32_t)(1ll * x * p.x\
    \ % mod);\n\t\treturn *this; \n\t}\n\n\tModInt &operator /= (const ModInt &p)\
    \ {\n\t\t*this *= p.inverse();\n\t\treturn *this;\n\t}\n\n\t// ModInt += Int\n\
    \tModInt &operator += (int32_t t) { return *this += ModInt(t); }\n\tModInt &operator\
    \ -= (int32_t t) { return *this -= ModInt(t); }\n\tModInt &operator *= (int32_t\
    \ t) { return *this *= ModInt(t); }\n\tModInt &operator /= (int32_t t) { return\
    \ *this /= ModInt(t); }\n\n\tModInt operator - () const { return ModInt(-x); }\
    \ // -a;\n\tModInt operator + () const { return ModInt(*this); } // +a;\n\tModInt\
    \ &operator ++ () { *this += 1; return *this; } // ++a;\n\tModInt &operator --\
    \ () { *this -= 1; return *this; } // --a;\n\tModInt operator ++ (int) { ModInt\
    \ res = *this; *this += 1; return res; } // a++;\n\tModInt operator -- (int) {\
    \ ModInt res = *this; *this -= 1; return res; } // a--;\n\n\t// ModInt = ModInt\
    \ + ModInt\n\tModInt operator + (const ModInt &p) const { return ModInt(*this)\
    \ += p; }\n\tModInt operator - (const ModInt &p) const { return ModInt(*this)\
    \ -= p; }\n\tModInt operator * (const ModInt &p) const { return ModInt(*this)\
    \ *= p; }\n\tModInt operator / (const ModInt &p) const { return ModInt(*this)\
    \ /= p; }\n\n\t// ModInt = ModInt + Int\n\tModInt operator + (int32_t t) const\
    \ { return ModInt(*this) += t; }\n\tModInt operator - (int32_t t) const { return\
    \ ModInt(*this) -= t; }\n\tModInt operator * (int32_t t) const { return ModInt(*this)\
    \ *= t; }\n\tModInt operator / (int32_t t) const { return ModInt(*this) /= t;\
    \ }\n\n\t// ModInt = Int + ModInt\n\tfriend ModInt operator + (int32_t t, const\
    \ ModInt &p) { ModInt res(t); res += p; return res; }\n\tfriend ModInt operator\
    \ - (int32_t t, const ModInt &p) { ModInt res(t); res -= p; return res; }\n\t\
    friend ModInt operator * (int32_t t, const ModInt &p) { ModInt res(t); res *=\
    \ p; return res; }\n\tfriend ModInt operator / (int32_t t, const ModInt &p) {\
    \ ModInt res(t); res /= p; return res; }\n\n\tbool operator == (const ModInt &p)\
    \ const { return x == p.x; }\n\tbool operator != (const ModInt &p) const { return\
    \ x != p.x; }\n\tbool operator < (const ModInt &p) const { return x < p.x; }\n\
    \tbool operator <= (const ModInt &p) const { return x <= p.x; }\n\tbool operator\
    \ > (const ModInt &p) const { return x > p.x; }\n\tbool operator >= (const ModInt\
    \ &p) const { return x >= p.x; }\n\n\tbool operator == (int32_t t) const { return\
    \ x == t; }\n\tbool operator != (int32_t t) const { return x != t; }\n\tbool operator\
    \ < (int32_t t) const { return x < t; }\n\tbool operator <= (int32_t t) const\
    \ { return x <= t; }\n\tbool operator > (int32_t t) const { return x > t; }\n\t\
    bool operator >= (int32_t t) const { return x >= t; }\n\n\tModInt inverse() const\
    \ { return power(mod - 2); }\n\n\tModInt power(int32_t b) const {\n\t\tassert(b\
    \ >= 0);\n\t\tModInt mul(x), ret(1);\n\t\twhile (b) {\n\t\t\tif (b & 1) ret *=\
    \ mul;\n\t\t\tmul *= mul;\n\t\t\tb /= 2;\n\t\t}\n\t\treturn ret;\n\t}\n\n\tfriend\
    \ istream &operator >> (istream &in, ModInt &p) { \n\t\tint32_t t;\n\t\tin >>\
    \ t;\n\t\tp = ModInt<mod>(t);\n\t\treturn in;\n\t}\n\t\n\tfriend ostream &operator\
    \ << (ostream &out, const ModInt &p) { return out << p.x; }\n\n\tint32_t get()\
    \ const { return x; }\n\tstatic constexpr int32_t get_mod() { return mod; }\n\
    };"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/Modint.h
  requiredBy: []
  timestamp: '2025-06-02 20:02:33+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Modint.h
layout: document
redirect_from:
- /library/Misc/Modint.h
- /library/Misc/Modint.h.html
title: Misc/Modint.h
---
