---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/connected-components/incremental-bridge-connectivity.cpp
    title: Incremental-Bridge-Connectivity
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.cpp
    title: graph/graph-template.cpp
  - icon: ':heavy_check_mark:'
    path: structure/union-find/union-find.cpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-three-edge-connected-components.test.cpp
    title: test/verify/yosupo-three-edge-connected-components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Three-Edge-Connected-Components(\u4E09\u91CD\u8FBA\u9023\u7D50\
      \u6210\u5206\u5206\u89E3)"
    links: []
  bundledCode: "#line 2 \"graph/graph-template.cpp\"\n\ntemplate< typename T = int\
    \ >\nstruct Edge {\n  int from, to;\n  T cost;\n  int idx;\n\n  Edge() = default;\n\
    \n  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost),\
    \ idx(idx) {}\n\n  operator int() const { return to; }\n};\n\ntemplate< typename\
    \ T = int >\nstruct Graph {\n  vector< vector< Edge< T > > > g;\n  int es;\n\n\
    \  Graph() = default;\n\n  explicit Graph(int n) : g(n), es(0) {}\n\n  size_t\
    \ size() const {\n    return g.size();\n  }\n\n  void add_directed_edge(int from,\
    \ int to, T cost = 1) {\n    g[from].emplace_back(from, to, cost, es++);\n  }\n\
    \n  void add_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from,\
    \ to, cost, es);\n    g[to].emplace_back(to, from, cost, es++);\n  }\n\n  void\
    \ read(int M, int padding = -1, bool weighted = false, bool directed = false)\
    \ {\n    for(int i = 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b;\n\
    \      a += padding;\n      b += padding;\n      T c = T(1);\n      if(weighted)\
    \ cin >> c;\n      if(directed) add_directed_edge(a, b, c);\n      else add_edge(a,\
    \ b, c);\n    }\n  }\n};\n\ntemplate< typename T = int >\nusing Edges = vector<\
    \ Edge< T > >;\n#line 1 \"structure/union-find/union-find.cpp\"\n/**\n * @brief\
    \ Union-Find\n * @docs docs/union-find.md\n */\nstruct UnionFind {\n  vector<\
    \ int > data;\n\n  UnionFind() = default;\n\n  explicit UnionFind(size_t sz) :\
    \ data(sz, -1) {}\n\n  bool unite(int x, int y) {\n    x = find(x), y = find(y);\n\
    \    if(x == y) return false;\n    if(data[x] > data[y]) swap(x, y);\n    data[x]\
    \ += data[y];\n    data[y] = x;\n    return true;\n  }\n\n  int find(int k) {\n\
    \    if(data[k] < 0) return (k);\n    return data[k] = find(data[k]);\n  }\n\n\
    \  int size(int k) {\n    return -data[find(k)];\n  }\n\n  bool same(int x, int\
    \ y) {\n    return find(x) == find(y);\n  }\n\n  vector< vector< int > > groups()\
    \ {\n    int n = (int) data.size();\n    vector< vector< int > > ret(n);\n   \
    \ for(int i = 0; i < n; i++) {\n      ret[find(i)].emplace_back(i);\n    }\n \
    \   ret.erase(remove_if(begin(ret), end(ret), [&](const vector< int > &v) {\n\
    \      return v.empty();\n    }));\n    return ret;\n  }\n};\n#line 2 \"graph/connected-components/incremental-bridge-connectivity.cpp\"\
    \n\n/**\n * @brief Incremental-Bridge-Connectivity\n * @docs docs/incremental-bridge-connectivity.md\n\
    \ * @see https://scrapbox.io/data-structures/Incremental_Bridge-Connectivity\n\
    \ */\nstruct IncrementalBridgeConnectivity {\nprivate:\n  UnionFind cc, bcc;\n\
    \  vector< int > bbf;\n  size_t bridge;\n\n  int size() {\n    return bbf.size();\n\
    \  }\n\n  int par(int x) {\n    return bbf[x] == size() ? size() : bcc.find(bbf[x]);\n\
    \  }\n\n  int lca(int x, int y) {\n    unordered_set< int > used;\n    for(;;)\
    \ {\n      if(x != size()) {\n        if(!used.insert(x).second) return x;\n \
    \       x = par(x);\n      }\n      swap(x, y);\n    }\n  }\n\n  void compress(int\
    \ x, int y) {\n    while(bcc.find(x) != bcc.find(y)) {\n      int nxt = par(x);\n\
    \      bbf[x] = bbf[y];\n      bcc.unite(x, y);\n      x = nxt;\n      --bridge;\n\
    \    }\n  }\n\n  void link(int x, int y) {\n    int v = x, pre = y;\n    while(v\
    \ != size()) {\n      int nxt = par(v);\n      bbf[v] = pre;\n      pre = v;\n\
    \      v = nxt;\n    }\n  }\n\npublic:\n  IncrementalBridgeConnectivity() = default;\n\
    \n  explicit IncrementalBridgeConnectivity(int sz) : cc(sz), bcc(sz), bbf(sz,\
    \ sz), bridge(0) {}\n\n  int find(int k) {\n    return bcc.find(k);\n  }\n\n \
    \ size_t bridge_size() const {\n    return bridge;\n  }\n\n  void add_edge(int\
    \ x, int y) {\n    x = bcc.find(x);\n    y = bcc.find(y);\n    if(cc.find(x) ==\
    \ cc.find(y)) {\n      int w = lca(x, y);\n      compress(x, w);\n      compress(y,\
    \ w);\n    } else {\n      if(cc.size(x) > cc.size(y)) swap(x, y);\n      link(x,\
    \ y);\n      cc.unite(x, y);\n      ++bridge;\n    }\n  }\n};\n#line 3 \"graph/connected-components/three-edge-connected-components.cpp\"\
    \n\n/**\n * @brief Three-Edge-Connected-Components(\u4E09\u91CD\u8FBA\u9023\u7D50\
    \u6210\u5206\u5206\u89E3)\n */\ntemplate< typename T = int >\nstruct ThreeEdgeConnectedComponents\
    \ : Graph< T > {\npublic:\n  using Graph< T >::Graph;\n  using Graph< T >::g;\n\
    \  vector< vector< int > > group;\n\n  void build() {\n    uf = UnionFind(g.size());\n\
    \    bcc = IncrementalBridgeConnectivity(g.size());\n    used.assign(g.size(),\
    \ 0);\n    in.assign(g.size(), 0);\n    out.assign(g.size(), 0);\n    deg.assign(g.size(),\
    \ 0);\n    low.assign(g.size(), g.size());\n    for(int from = 0; from < g.size();\
    \ from++) {\n      for(auto &to : g[from]) {\n        if(from < to) bcc.add_edge(from,\
    \ to);\n      }\n    }\n    int cnt = 0;\n    for(int i = 0; i < g.size(); i++)\
    \ {\n      if(used[i]) continue;\n      vector< int > tmp;\n      dfs(i, -1, tmp,\
    \ cnt);\n      cnt++;\n    }\n    vector< int > id(g.size(), -1);\n    cnt = 0;\n\
    \    for(int i = 0; i < g.size(); i++) {\n      if(id[uf.find(i)] == -1) id[uf.find(i)]\
    \ = cnt++;\n    }\n    group.resize(cnt);\n    for(int i = 0; i < g.size(); i++)\
    \ {\n      group[id[uf.find(i)]].emplace_back(i);\n    }\n  }\n\n  int operator[](const\
    \ int &k) {\n    return uf.find(k);\n  }\n\nprivate:\n  vector< int > used;\n\
    \  vector< int > in, out, low, deg;\n  IncrementalBridgeConnectivity bcc;\n  UnionFind\
    \ uf;\n\n  void absorb(vector< int > &path, int v, int w = -1) {\n    while(!path.empty())\
    \ {\n      int x = path.back();\n      if(w != -1 && (in[x] > in[w] or in[w] >=\
    \ out[x])) break;\n      path.pop_back();\n      uf.unite(v, x);\n      deg[v]\
    \ += deg[x] - 2;\n    }\n  }\n\n  void dfs(int idx, int p, vector< int > &path,\
    \ int &k) {\n    used[idx] = 1;\n    in[idx] = low[idx] = k++;\n    for(auto &to\
    \ : g[idx]) {\n      if(idx == to || bcc.find(idx) != bcc.find(to)) continue;\n\
    \      deg[idx]++;\n      if(to == p) {\n        p = -1;\n        continue;\n\
    \      }\n      if(used[to]) {\n        if(in[idx] > in[to]) {\n          if(in[to]\
    \ < low[idx]) {\n            low[idx] = in[to];\n            absorb(path, idx);\n\
    \          }\n        } else {\n          deg[idx] -= 2;\n          absorb(path,\
    \ idx, to);\n        }\n      } else {\n        vector< int > ps;\n        dfs(to,\
    \ idx, ps, k);\n        if(deg[to] == 2) ps.pop_back();\n        if(low[to] <\
    \ low[idx]) {\n          low[idx] = low[to];\n          absorb(path, idx);\n \
    \         path = ps;\n        } else {\n          absorb(ps, idx);\n        }\n\
    \      }\n    }\n    out[idx] = k;\n    path.push_back(idx);\n  }\n};\n\n"
  code: "#include \"../graph-template.cpp\"\n#include \"incremental-bridge-connectivity.cpp\"\
    \n\n/**\n * @brief Three-Edge-Connected-Components(\u4E09\u91CD\u8FBA\u9023\u7D50\
    \u6210\u5206\u5206\u89E3)\n */\ntemplate< typename T = int >\nstruct ThreeEdgeConnectedComponents\
    \ : Graph< T > {\npublic:\n  using Graph< T >::Graph;\n  using Graph< T >::g;\n\
    \  vector< vector< int > > group;\n\n  void build() {\n    uf = UnionFind(g.size());\n\
    \    bcc = IncrementalBridgeConnectivity(g.size());\n    used.assign(g.size(),\
    \ 0);\n    in.assign(g.size(), 0);\n    out.assign(g.size(), 0);\n    deg.assign(g.size(),\
    \ 0);\n    low.assign(g.size(), g.size());\n    for(int from = 0; from < g.size();\
    \ from++) {\n      for(auto &to : g[from]) {\n        if(from < to) bcc.add_edge(from,\
    \ to);\n      }\n    }\n    int cnt = 0;\n    for(int i = 0; i < g.size(); i++)\
    \ {\n      if(used[i]) continue;\n      vector< int > tmp;\n      dfs(i, -1, tmp,\
    \ cnt);\n      cnt++;\n    }\n    vector< int > id(g.size(), -1);\n    cnt = 0;\n\
    \    for(int i = 0; i < g.size(); i++) {\n      if(id[uf.find(i)] == -1) id[uf.find(i)]\
    \ = cnt++;\n    }\n    group.resize(cnt);\n    for(int i = 0; i < g.size(); i++)\
    \ {\n      group[id[uf.find(i)]].emplace_back(i);\n    }\n  }\n\n  int operator[](const\
    \ int &k) {\n    return uf.find(k);\n  }\n\nprivate:\n  vector< int > used;\n\
    \  vector< int > in, out, low, deg;\n  IncrementalBridgeConnectivity bcc;\n  UnionFind\
    \ uf;\n\n  void absorb(vector< int > &path, int v, int w = -1) {\n    while(!path.empty())\
    \ {\n      int x = path.back();\n      if(w != -1 && (in[x] > in[w] or in[w] >=\
    \ out[x])) break;\n      path.pop_back();\n      uf.unite(v, x);\n      deg[v]\
    \ += deg[x] - 2;\n    }\n  }\n\n  void dfs(int idx, int p, vector< int > &path,\
    \ int &k) {\n    used[idx] = 1;\n    in[idx] = low[idx] = k++;\n    for(auto &to\
    \ : g[idx]) {\n      if(idx == to || bcc.find(idx) != bcc.find(to)) continue;\n\
    \      deg[idx]++;\n      if(to == p) {\n        p = -1;\n        continue;\n\
    \      }\n      if(used[to]) {\n        if(in[idx] > in[to]) {\n          if(in[to]\
    \ < low[idx]) {\n            low[idx] = in[to];\n            absorb(path, idx);\n\
    \          }\n        } else {\n          deg[idx] -= 2;\n          absorb(path,\
    \ idx, to);\n        }\n      } else {\n        vector< int > ps;\n        dfs(to,\
    \ idx, ps, k);\n        if(deg[to] == 2) ps.pop_back();\n        if(low[to] <\
    \ low[idx]) {\n          low[idx] = low[to];\n          absorb(path, idx);\n \
    \         path = ps;\n        } else {\n          absorb(ps, idx);\n        }\n\
    \      }\n    }\n    out[idx] = k;\n    path.push_back(idx);\n  }\n};\n\n"
  dependsOn:
  - graph/graph-template.cpp
  - graph/connected-components/incremental-bridge-connectivity.cpp
  - structure/union-find/union-find.cpp
  isVerificationFile: false
  path: graph/connected-components/three-edge-connected-components.cpp
  requiredBy: []
  timestamp: '2021-05-07 20:07:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-three-edge-connected-components.test.cpp
documentation_of: graph/connected-components/three-edge-connected-components.cpp
layout: document
redirect_from:
- /library/graph/connected-components/three-edge-connected-components.cpp
- /library/graph/connected-components/three-edge-connected-components.cpp.html
title: "Three-Edge-Connected-Components(\u4E09\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
  \u5206\u89E3)"
---