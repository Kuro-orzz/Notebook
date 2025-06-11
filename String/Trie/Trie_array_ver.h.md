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
    \ 0;\n}\n#line 2 \"String/Trie/Trie_array_ver.h\"\n\n\nstruct Node {\n    int\
    \ child[26], isEnd;\n\n    Node() {\n        memset(child, 0, sizeof child);\n\
    \        isEnd = 0;\n    }\n};\n\nclass Trie {\npublic:\n    int n, curVertex;\n\
    \    vector<Node> tree;\n\n    Trie() {}\n    Trie(int _n): n(_n+1), curVertex(0)\
    \ {\n        tree.assign(n+1, Node());\n    }\n\n    void add(const string &s)\
    \ {\n        int u = 0;\n        for (size_t i = 0; i < s.size(); i++) {\n   \
    \         int k = s[i] - 'a';\n            if (!tree[u].child[k]) {\n        \
    \        tree[u].child[k] = ++curVertex;\n            }\n            u = tree[u].child[k];\n\
    \        }\n        tree[u].isEnd++;\n    }\n\n    bool search(const string &s)\
    \ {\n        int u = 0;\n        for (size_t i = 0; i < s.size(); i++) {\n   \
    \         int k = s[i] - 'a';\n            if (!tree[u].child[k]) {\n        \
    \        return 0;\n            }\n            u = tree[u].child[k];\n       \
    \ }\n        return tree[u].isEnd;\n    }\n\n    void del(const string &s) {\n\
    \        if (!search(s)) return;\n        int u = 0;\n        for (size_t i =\
    \ 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n            u = tree[u].child[k];\n\
    \        }\n        tree[u].isEnd--;\n    }\n\n    // sort string\n    void dfs(int\
    \ pos, string &cur, vector<string> &res) {\n        for (int i = 0; i < tree[pos].isEnd;\
    \ i++) {\n            res.push_back(cur);\n        }\n        for (int i = 0;\
    \ i < 26; i++) {\n            if (!tree[pos].child[i]) continue;\n           \
    \ cur += char(i + 'a');\n            dfs(tree[pos].child[i], cur, res);\n    \
    \        cur.pop_back();\n        }\n    }\n\n    vector<string> sort_string()\
    \ {\n        vecor<int> res;\n        string s = \"\";\n        dfs(0, s, res);\n\
    \        return res;\n    }\n\n    string find_kth_string(int k) {\n        \n\
    \    }\n};\n"
  code: "#include \"../../template.h\"\n\n\nstruct Node {\n    int child[26], isEnd;\n\
    \n    Node() {\n        memset(child, 0, sizeof child);\n        isEnd = 0;\n\
    \    }\n};\n\nclass Trie {\npublic:\n    int n, curVertex;\n    vector<Node> tree;\n\
    \n    Trie() {}\n    Trie(int _n): n(_n+1), curVertex(0) {\n        tree.assign(n+1,\
    \ Node());\n    }\n\n    void add(const string &s) {\n        int u = 0;\n   \
    \     for (size_t i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n\
    \            if (!tree[u].child[k]) {\n                tree[u].child[k] = ++curVertex;\n\
    \            }\n            u = tree[u].child[k];\n        }\n        tree[u].isEnd++;\n\
    \    }\n\n    bool search(const string &s) {\n        int u = 0;\n        for\
    \ (size_t i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n     \
    \       if (!tree[u].child[k]) {\n                return 0;\n            }\n \
    \           u = tree[u].child[k];\n        }\n        return tree[u].isEnd;\n\
    \    }\n\n    void del(const string &s) {\n        if (!search(s)) return;\n \
    \       int u = 0;\n        for (size_t i = 0; i < s.size(); i++) {\n        \
    \    int k = s[i] - 'a';\n            u = tree[u].child[k];\n        }\n     \
    \   tree[u].isEnd--;\n    }\n\n    // sort string\n    void dfs(int pos, string\
    \ &cur, vector<string> &res) {\n        for (int i = 0; i < tree[pos].isEnd; i++)\
    \ {\n            res.push_back(cur);\n        }\n        for (int i = 0; i < 26;\
    \ i++) {\n            if (!tree[pos].child[i]) continue;\n            cur += char(i\
    \ + 'a');\n            dfs(tree[pos].child[i], cur, res);\n            cur.pop_back();\n\
    \        }\n    }\n\n    vector<string> sort_string() {\n        vecor<int> res;\n\
    \        string s = \"\";\n        dfs(0, s, res);\n        return res;\n    }\n\
    \n    string find_kth_string(int k) {\n        \n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/Trie/Trie_array_ver.h
  requiredBy: []
  timestamp: '2025-06-11 15:37:14+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Trie/Trie_array_ver.h
layout: document
redirect_from:
- /library/String/Trie/Trie_array_ver.h
- /library/String/Trie/Trie_array_ver.h.html
title: String/Trie/Trie_array_ver.h
---
