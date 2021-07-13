---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/connected-components/strongly-connected-components.hpp
    title: "Strongly-Connected-Components(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/verify/yosupo-scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing int64 = long long;\nconst int mod = 1e9 + 7;\n\nconst int64 infll\
    \ = (1LL << 62) - 1;\nconst int inf = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(10);\n    cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\
    \ntemplate< typename T1, typename T2 >\nostream &operator<<(ostream &os, const\
    \ pair< T1, T2 >& p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\n\ntemplate< typename T1, typename T2 >\nistream &operator>>(istream &is, pair<\
    \ T1, T2 > &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate< typename\
    \ T >\nostream &operator<<(ostream &os, const vector< T > &v) {\n  for(int i =\
    \ 0; i < (int) v.size(); i++) {\n    os << v[i] << (i + 1 != v.size() ? \" \"\
    \ : \"\");\n  }\n  return os;\n}\n\ntemplate< typename T >\nistream &operator>>(istream\
    \ &is, vector< T > &v) {\n  for(T &in : v) is >> in;\n  return is;\n}\n\ntemplate<\
    \ typename T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) { return a < b &&\
    \ (a = b, true); }\n\ntemplate< typename T1, typename T2 >\ninline bool chmin(T1\
    \ &a, T2 b) { return a > b && (a = b, true); }\n\ntemplate< typename T = int64\
    \ >\nvector< T > make_v(size_t a) {\n  return vector< T >(a);\n}\n\ntemplate<\
    \ typename T, typename... Ts >\nauto make_v(size_t a, Ts... ts) {\n  return vector<\
    \ decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));\n}\n\ntemplate< typename\
    \ T, typename V >\ntypename enable_if< is_class< T >::value == 0 >::type fill_v(T\
    \ &t, const V &v) {\n  t = v;\n}\n\ntemplate< typename T, typename V >\ntypename\
    \ enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {\n  for(auto\
    \ &e : t) fill_v(e, v);\n}\n\ntemplate< typename F >\nstruct FixPoint : F {\n\
    \  explicit FixPoint(F &&f) : F(forward< F >(f)) {}\n\n  template< typename...\
    \ Args >\n  decltype(auto) operator()(Args &&... args) const {\n    return F::operator()(*this,\
    \ forward< Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/yosupo-scc.test.cpp\"\
    \n\n#line 2 \"graph/connected-components/strongly-connected-components.hpp\"\n\
    \n#line 2 \"graph/graph-template.hpp\"\n\ntemplate< typename T = int >\nstruct\
    \ Edge {\n  int from, to;\n  T cost;\n  int idx;\n\n  Edge() = default;\n\n  Edge(int\
    \ from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n\n  operator int() const { return to; }\n};\n\ntemplate< typename T = int\
    \ >\nstruct Graph {\n  vector< vector< Edge< T > > > g;\n  int es;\n\n  Graph()\
    \ = default;\n\n  explicit Graph(int n) : g(n), es(0) {}\n\n  size_t size() const\
    \ {\n    return g.size();\n  }\n\n  void add_directed_edge(int from, int to, T\
    \ cost = 1) {\n    g[from].emplace_back(from, to, cost, es++);\n  }\n\n  void\
    \ add_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from, to,\
    \ cost, es);\n    g[to].emplace_back(to, from, cost, es++);\n  }\n\n  void read(int\
    \ M, int padding = -1, bool weighted = false, bool directed = false) {\n    for(int\
    \ i = 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b;\n      a += padding;\n\
    \      b += padding;\n      T c = T(1);\n      if(weighted) cin >> c;\n      if(directed)\
    \ add_directed_edge(a, b, c);\n      else add_edge(a, b, c);\n    }\n  }\n};\n\
    \ntemplate< typename T = int >\nusing Edges = vector< Edge< T > >;\n#line 4 \"\
    graph/connected-components/strongly-connected-components.hpp\"\n\n/**\n * @brief\
    \ Strongly-Connected-Components(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)\n\
    \ * @docs docs/strongly-connected-components.md\n */\ntemplate< typename T = int\
    \ >\nstruct StronglyConnectedComponents : Graph< T > {\npublic:\n  using Graph<\
    \ T >::Graph;\n  using Graph< T >::g;\n  vector< int > comp;\n  Graph< T > dag;\n\
    \  vector< vector< int > > group;\n\n  void build() {\n    rg = Graph< T >(g.size());\n\
    \    for(size_t i = 0; i < g.size(); i++) {\n      for(auto &e : g[i]) {\n   \
    \     rg.add_directed_edge(e.to, e.from, e.cost);\n      }\n    }\n    comp.assign(g.size(),\
    \ -1);\n    used.assign(g.size(), 0);\n    for(size_t i = 0; i < g.size(); i++)\
    \ dfs(i);\n    reverse(begin(order), end(order));\n    int ptr = 0;\n    for(int\
    \ i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;\n    dag = Graph< T >(ptr);\n\
    \    for(size_t i = 0; i < g.size(); i++) {\n      for(auto &e : g[i]) {\n   \
    \     int x = comp[e.from], y = comp[e.to];\n        if(x == y) continue;\n  \
    \      dag.add_directed_edge(x, y, e.cost);\n      }\n    }\n    group.resize(ptr);\n\
    \    for(size_t i = 0; i < g.size(); i++) {\n      group[comp[i]].emplace_back(i);\n\
    \    }\n  }\n\n  int operator[](int k) const {\n    return comp[k];\n  }\n\nprivate:\n\
    \  vector< int > order, used;\n  Graph< T > rg;\n\n  void dfs(int idx) {\n   \
    \ if(exchange(used[idx], true)) return;\n    for(auto &to : g[idx]) dfs(to);\n\
    \    order.push_back(idx);\n  }\n\n  void rdfs(int idx, int cnt) {\n    if(comp[idx]\
    \ != -1) return;\n    comp[idx] = cnt;\n    for(auto &to : rg.g[idx]) rdfs(to,\
    \ cnt);\n  }\n};\n#line 6 \"test/verify/yosupo-scc.test.cpp\"\n\nint main() {\n\
    \  int N, M;\n  cin >> N >> M;\n  StronglyConnectedComponents<> g(N);\n  g.read(M,\
    \ 0, false, true);\n  g.build();\n  cout << g.group.size() << \"\\n\";\n  for(auto\
    \ &p : g.group) {\n    cout << p.size() << \" \" << p << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../template/template.cpp\"\
    \n\n#include \"../../graph/connected-components/strongly-connected-components.hpp\"\
    \n\nint main() {\n  int N, M;\n  cin >> N >> M;\n  StronglyConnectedComponents<>\
    \ g(N);\n  g.read(M, 0, false, true);\n  g.build();\n  cout << g.group.size()\
    \ << \"\\n\";\n  for(auto &p : g.group) {\n    cout << p.size() << \" \" << p\
    \ << \"\\n\";\n  }\n}\n"
  dependsOn:
  - template/template.cpp
  - graph/connected-components/strongly-connected-components.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: test/verify/yosupo-scc.test.cpp
  requiredBy: []
  timestamp: '2021-07-01 02:53:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-scc.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-scc.test.cpp
- /verify/test/verify/yosupo-scc.test.cpp.html
title: test/verify/yosupo-scc.test.cpp
---