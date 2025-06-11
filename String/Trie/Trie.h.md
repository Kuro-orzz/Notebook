---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \ 0;\n}\n#line 2 \"String/Trie/Trie.h\"\n\nstruct Node {\n    Node *child[26];\n\
    \    bool isEnd;\n\n    Node() {\n        memset(child, 0, sizeof child);\n  \
    \      isEnd = false;\n    }\n};\n\nclass Trie {\n    Node *r = new Node();\n\n\
    \    Trie() {}\n\n    void add(const string &s) {\n        Node *u = r;\n    \
    \    for (size_t i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n\
    \            if (!u->child[k]) {\n                u->child[k] = new Node();\n\
    \            }\n            u = u->child[k];\n        }\n        u->isEnd = true;\n\
    \    }\n\n    bool search(const string &s) {\n        Node *u = r;\n        for\
    \ (size_t i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n     \
    \       if (!u->child[k]) {\n                return false;\n            }\n  \
    \          u = u->child[k];\n        }\n        return u->isEnd;\n    }\n};\n"
  code: "#include \"../../template.h\"\n\nstruct Node {\n    Node *child[26];\n  \
    \  bool isEnd;\n\n    Node() {\n        memset(child, 0, sizeof child);\n    \
    \    isEnd = false;\n    }\n};\n\nclass Trie {\n    Node *r = new Node();\n\n\
    \    Trie() {}\n\n    void add(const string &s) {\n        Node *u = r;\n    \
    \    for (size_t i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n\
    \            if (!u->child[k]) {\n                u->child[k] = new Node();\n\
    \            }\n            u = u->child[k];\n        }\n        u->isEnd = true;\n\
    \    }\n\n    bool search(const string &s) {\n        Node *u = r;\n        for\
    \ (size_t i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n     \
    \       if (!u->child[k]) {\n                return false;\n            }\n  \
    \          u = u->child[k];\n        }\n        return u->isEnd;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/Trie/Trie.h
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Trie/Trie.h
layout: document
redirect_from:
- /library/String/Trie/Trie.h
- /library/String/Trie/Trie.h.html
title: String/Trie/Trie.h
---
