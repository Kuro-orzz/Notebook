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
    \ 0;\n}\n#line 2 \"String/Trie/Trie_array_ver.h\"\n\n\nstruct Node {\n\tint child[26],\
    \ isEnd;\n\n\tNode() {\n\t\tmemset(child, 0, sizeof child);\n\t\tisEnd = 0;\n\t\
    }\n};\n\nclass Trie {\npublic:\n\tint n, curVertex;\n\tvector<Node> tree;\n\n\t\
    Trie() {}\n\tTrie(int _n): n(_n+1), curVertex(0) {\n\t\ttree.assign(n+1, Node());\n\
    \t}\n\n\tvoid add(const string &s) {\n\t\tint u = 0;\n\t\tfor (size_t i = 0; i\
    \ < s.size(); i++) {\n\t\t\tint k = s[i] - 'a';\n\t\t\tif (!tree[u].child[k])\
    \ {\n\t\t\t\ttree[u].child[k] = ++curVertex;\n\t\t\t}\n\t\t\tu = tree[u].child[k];\n\
    \t\t}\n\t\ttree[u].isEnd++;\n\t}\n\n\tbool search(const string &s) {\n\t\tint\
    \ u = 0;\n\t\tfor (size_t i = 0; i < s.size(); i++) {\n\t\t\tint k = s[i] - 'a';\n\
    \t\t\tif (!tree[u].child[k]) {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tu = tree[u].child[k];\n\
    \t\t}\n\t\treturn tree[u].isEnd;\n\t}\n\n\tvoid del(const string &s) {\n\t\tif\
    \ (!search(s)) return;\n\t\tint u = 0;\n\t\tfor (size_t i = 0; i < s.size(); i++)\
    \ {\n\t\t\tint k = s[i] - 'a';\n\t\t\tu = tree[u].child[k];\n\t\t}\n\t\ttree[u].isEnd--;\n\
    \t}\n\n\t// sort string\n\tvoid dfs(int pos, string &cur, vector<string> &res)\
    \ {\n\t\tfor (int i = 0; i < tree[pos].isEnd; i++) {\n\t\t\tres.push_back(cur);\n\
    \t\t}\n\t\tfor (int i = 0; i < 26; i++) {\n\t\t\tif (!tree[pos].child[i]) continue;\n\
    \t\t\tcur += char(i + 'a');\n\t\t\tdfs(tree[pos].child[i], cur, res);\n\t\t\t\
    cur.pop_back();\n\t\t}\n\t}\n\n\tvector<string> sort_string() {\n\t\tvecor<int>\
    \ res;\n\t\tstring s = \"\";\n\t\tdfs(0, s, res);\n\t\treturn res;\n\t}\n\n\t\
    string find_kth_string(int k) {\n\t\t\n\t}\n};\n"
  code: "#include \"../../template.h\"\n\n\nstruct Node {\n\tint child[26], isEnd;\n\
    \n\tNode() {\n\t\tmemset(child, 0, sizeof child);\n\t\tisEnd = 0;\n\t}\n};\n\n\
    class Trie {\npublic:\n\tint n, curVertex;\n\tvector<Node> tree;\n\n\tTrie() {}\n\
    \tTrie(int _n): n(_n+1), curVertex(0) {\n\t\ttree.assign(n+1, Node());\n\t}\n\n\
    \tvoid add(const string &s) {\n\t\tint u = 0;\n\t\tfor (size_t i = 0; i < s.size();\
    \ i++) {\n\t\t\tint k = s[i] - 'a';\n\t\t\tif (!tree[u].child[k]) {\n\t\t\t\t\
    tree[u].child[k] = ++curVertex;\n\t\t\t}\n\t\t\tu = tree[u].child[k];\n\t\t}\n\
    \t\ttree[u].isEnd++;\n\t}\n\n\tbool search(const string &s) {\n\t\tint u = 0;\n\
    \t\tfor (size_t i = 0; i < s.size(); i++) {\n\t\t\tint k = s[i] - 'a';\n\t\t\t\
    if (!tree[u].child[k]) {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tu = tree[u].child[k];\n\
    \t\t}\n\t\treturn tree[u].isEnd;\n\t}\n\n\tvoid del(const string &s) {\n\t\tif\
    \ (!search(s)) return;\n\t\tint u = 0;\n\t\tfor (size_t i = 0; i < s.size(); i++)\
    \ {\n\t\t\tint k = s[i] - 'a';\n\t\t\tu = tree[u].child[k];\n\t\t}\n\t\ttree[u].isEnd--;\n\
    \t}\n\n\t// sort string\n\tvoid dfs(int pos, string &cur, vector<string> &res)\
    \ {\n\t\tfor (int i = 0; i < tree[pos].isEnd; i++) {\n\t\t\tres.push_back(cur);\n\
    \t\t}\n\t\tfor (int i = 0; i < 26; i++) {\n\t\t\tif (!tree[pos].child[i]) continue;\n\
    \t\t\tcur += char(i + 'a');\n\t\t\tdfs(tree[pos].child[i], cur, res);\n\t\t\t\
    cur.pop_back();\n\t\t}\n\t}\n\n\tvector<string> sort_string() {\n\t\tvecor<int>\
    \ res;\n\t\tstring s = \"\";\n\t\tdfs(0, s, res);\n\t\treturn res;\n\t}\n\n\t\
    string find_kth_string(int k) {\n\t\t\n\t}\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/Trie/Trie_array_ver.h
  requiredBy: []
  timestamp: '2025-06-02 20:04:33+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Trie/Trie_array_ver.h
layout: document
redirect_from:
- /library/String/Trie/Trie_array_ver.h
- /library/String/Trie/Trie_array_ver.h.html
title: String/Trie/Trie_array_ver.h
---
