---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Big_Integer/BigInt.h
    title: Big_Integer/BigInt.h
  - icon: ':question:'
    path: DataStructure/DSU/Dsu.h
    title: DataStructure/DSU/Dsu.h
  - icon: ':warning:'
    path: DataStructure/DSU/Dsu_2D.h
    title: DataStructure/DSU/Dsu_2D.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick/Fenwick.h
    title: DataStructure/Fenwick/Fenwick.h
  - icon: ':warning:'
    path: DataStructure/Point_set_range_composite.brute_force.cpp
    title: DataStructure/Point_set_range_composite.brute_force.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/RMQ/RMQ.h
    title: DataStructure/RMQ/RMQ.h
  - icon: ':x:'
    path: DataStructure/SegTree/Affline.h
    title: DataStructure/SegTree/Affline.h
  - icon: ':warning:'
    path: DataStructure/SegTree/LazySegTree.h
    title: DataStructure/SegTree/LazySegTree.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree/SegTree.h
    title: DataStructure/SegTree/SegTree.h
  - icon: ':warning:'
    path: DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h
    title: DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h
  - icon: ':warning:'
    path: DataStructure/SegTree/SegTreeBeats/SegTreeBeats2.h
    title: DataStructure/SegTree/SegTreeBeats/SegTreeBeats2.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree/SegTreeBeats/SegTreeBeats3.h
    title: DataStructure/SegTree/SegTreeBeats/SegTreeBeats3.h
  - icon: ':warning:'
    path: DataStructure/SegTree/SegTreeBeats/test1.cpp
    title: DataStructure/SegTree/SegTreeBeats/test1.cpp
  - icon: ':warning:'
    path: DataStructure/SegTree/SegTreeBeats/test2.cpp
    title: DataStructure/SegTree/SegTreeBeats/test2.cpp
  - icon: ':warning:'
    path: DataStructure/SegTree/SegTreeBeats/test3.cpp
    title: DataStructure/SegTree/SegTreeBeats/test3.cpp
  - icon: ':heavy_check_mark:'
    path: Tree/Tree/BinaryLifting.h
    title: Tree/Tree/BinaryLifting.h
  - icon: ':heavy_check_mark:'
    path: Tree/Tree/Lca.h
    title: Tree/Tree/Lca.h
  - icon: ':heavy_check_mark:'
    path: Tree/Tree/Tree.h
    title: Tree/Tree/Tree.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Big_Integer/Addition_of_Big_Integers.test.cpp
    title: Big_Integer/Addition_of_Big_Integers.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/Associative_array.test.cpp
    title: DataStructure/Associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/Point_add_range_sum.test.cpp
    title: DataStructure/Point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/Predecessor_problem.test.cpp
    title: DataStructure/Predecessor_problem.test.cpp
  - icon: ':x:'
    path: DataStructure/Range_affine_range_sum.test.cpp
    title: DataStructure/Range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/Range_chmin_chmax_add_range_sum.test.cpp
    title: DataStructure/Range_chmin_chmax_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/Static_RMQ.test.cpp
    title: DataStructure/Static_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/Static_range_sum.test.cpp
    title: DataStructure/Static_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/Union_find.test.cpp
    title: DataStructure/Union_find.test.cpp
  - icon: ':x:'
    path: DataStructure/Unionfind_with_potential.test.cpp
    title: DataStructure/Unionfind_with_potential.test.cpp
  - icon: ':heavy_check_mark:'
    path: Sample/A_plus_B.test.cpp
    title: Sample/A_plus_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Sample/Many_A_plus_B.test.cpp
    title: Sample/Many_A_plus_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Sample/Many_A_plus_B_128bit.test.cpp
    title: Sample/Many_A_plus_B_128bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: Tree/Diameter_tree.test.cpp
    title: Tree/Diameter_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Tree/Jump_on_tree.test.cpp
    title: Tree/Jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Tree/Lowest_common_ancestor.test.cpp
    title: Tree/Lowest_common_ancestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\
    #define vi vector<int>\n#define pii pair<int, int>\n#define pll pair<ll, ll>\n\
    #define fi first\n#define se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\
    \nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define\
    \ ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define INF32 ((1ull<<31)-1)\n#define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\
    #define vi vector<int>\n#define pii pair<int, int>\n#define pll pair<ll, ll>\n\
    #define fi first\n#define se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\
    \nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: template.h
  requiredBy:
  - Tree/Tree/BinaryLifting.h
  - Tree/Tree/Lca.h
  - Tree/Tree/Tree.h
  - Big_Integer/BigInt.h
  - DataStructure/DSU/Dsu_2D.h
  - DataStructure/DSU/Dsu.h
  - DataStructure/Fenwick/Fenwick.h
  - DataStructure/RMQ/RMQ.h
  - DataStructure/SegTree/SegTree.h
  - DataStructure/SegTree/Affline.h
  - DataStructure/SegTree/SegTreeBeats/test1.cpp
  - DataStructure/SegTree/SegTreeBeats/SegTreeBeats2.h
  - DataStructure/SegTree/SegTreeBeats/test2.cpp
  - DataStructure/SegTree/SegTreeBeats/SegTreeBeats1.h
  - DataStructure/SegTree/SegTreeBeats/test3.cpp
  - DataStructure/SegTree/SegTreeBeats/SegTreeBeats3.h
  - DataStructure/SegTree/LazySegTree.h
  - DataStructure/Point_set_range_composite.brute_force.cpp
  timestamp: '2025-05-06 22:27:53+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Tree/Jump_on_tree.test.cpp
  - Tree/Diameter_tree.test.cpp
  - Tree/Lowest_common_ancestor.test.cpp
  - Big_Integer/Addition_of_Big_Integers.test.cpp
  - Sample/A_plus_B.test.cpp
  - Sample/Many_A_plus_B.test.cpp
  - Sample/Many_A_plus_B_128bit.test.cpp
  - DataStructure/Predecessor_problem.test.cpp
  - DataStructure/Point_add_range_sum.test.cpp
  - DataStructure/Static_RMQ.test.cpp
  - DataStructure/Static_range_sum.test.cpp
  - DataStructure/Associative_array.test.cpp
  - DataStructure/Unionfind_with_potential.test.cpp
  - DataStructure/Range_chmin_chmax_add_range_sum.test.cpp
  - DataStructure/Range_affine_range_sum.test.cpp
  - DataStructure/Union_find.test.cpp
documentation_of: template.h
layout: document
redirect_from:
- /library/template.h
- /library/template.h.html
title: template.h
---
