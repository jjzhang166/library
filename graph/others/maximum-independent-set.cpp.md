---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-maximum-independent-set.test.cpp
    title: test/verify/yosupo-maximum-independent-set.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/others/maximum-independent-set.cpp\"\ntemplate< typename\
    \ T >\nvector< int > maximum_independent_set(const Matrix< T > &g, int trial =\
    \ 1000000) {\n\n  int N = (int) g.size();\n  vector< uint64_t > bit(N);\n\n  assert(N\
    \ <= 64);\n  for(int i = 0; i < N; i++) {\n    for(int j = 0; j < N; j++) {\n\
    \      if(i != j) {\n        assert(g[i][j] == g[j][i]);\n        if(g[i][j])\
    \ bit[i] |= uint64_t(1) << j;\n      }\n    }\n  }\n\n  vector< int > ord(N);\n\
    \  iota(begin(ord), end(ord), 0);\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \  int ret = 0;\n  uint64_t ver;\n  for(int i = 0; i < trial; i++) {\n    shuffle(begin(ord),\
    \ end(ord), mt);\n    uint64_t used = 0;\n    int add = 0;\n    for(int j : ord)\
    \ {\n      if(used & bit[j]) continue;\n      used |= uint64_t(1) << j;\n    \
    \  ++add;\n    }\n    if(ret < add) {\n      ret = add;\n      ver = used;\n \
    \   }\n  }\n  vector< int > ans;\n  for(int i = 0; i < N; i++) {\n    if((ver\
    \ >> i) & 1) ans.emplace_back(i);\n  }\n  return ans;\n}\n"
  code: "template< typename T >\nvector< int > maximum_independent_set(const Matrix<\
    \ T > &g, int trial = 1000000) {\n\n  int N = (int) g.size();\n  vector< uint64_t\
    \ > bit(N);\n\n  assert(N <= 64);\n  for(int i = 0; i < N; i++) {\n    for(int\
    \ j = 0; j < N; j++) {\n      if(i != j) {\n        assert(g[i][j] == g[j][i]);\n\
    \        if(g[i][j]) bit[i] |= uint64_t(1) << j;\n      }\n    }\n  }\n\n  vector<\
    \ int > ord(N);\n  iota(begin(ord), end(ord), 0);\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \  int ret = 0;\n  uint64_t ver;\n  for(int i = 0; i < trial; i++) {\n    shuffle(begin(ord),\
    \ end(ord), mt);\n    uint64_t used = 0;\n    int add = 0;\n    for(int j : ord)\
    \ {\n      if(used & bit[j]) continue;\n      used |= uint64_t(1) << j;\n    \
    \  ++add;\n    }\n    if(ret < add) {\n      ret = add;\n      ver = used;\n \
    \   }\n  }\n  vector< int > ans;\n  for(int i = 0; i < N; i++) {\n    if((ver\
    \ >> i) & 1) ans.emplace_back(i);\n  }\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/others/maximum-independent-set.cpp
  requiredBy: []
  timestamp: '2019-11-30 23:02:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-maximum-independent-set.test.cpp
documentation_of: graph/others/maximum-independent-set.cpp
layout: document
redirect_from:
- /library/graph/others/maximum-independent-set.cpp
- /library/graph/others/maximum-independent-set.cpp.html
title: graph/others/maximum-independent-set.cpp
---