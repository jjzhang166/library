---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/verify/yosupo-tree-diameter.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5a4423c79a88aeb6104a40a645f9430c">test/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/verify/yosupo-tree-diameter.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-26 02:31:26+09:00


* see: <a href="https://judge.yosupo.jp/problem/tree_diameter">https://judge.yosupo.jp/problem/tree_diameter</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/graph-template.cpp.html">graph/graph-template.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/tree/tree-diameter.cpp.html">Tree-Diameter(木の直径) <small>(graph/tree/tree-diameter.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/template/template.cpp.html">template/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../template/template.cpp"

#include "../../graph/graph-template.cpp"

#include "../../graph/tree/tree-diameter.cpp"

int main() {
  int N;
  cin >> N;
  TreeDiameter< int64_t > g(N);
  g.read(N - 1, 0, true);
  cout << g.build() << " ";
  cout << g.path.size() + 1 << "\n";
  cout << g.path[0].from << " " << g.path << "\n";
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/verify/yosupo-tree-diameter.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#line 1 "template/template.cpp"
#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}
 
  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};
 
template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}
#line 4 "test/verify/yosupo-tree-diameter.test.cpp"

#line 1 "graph/graph-template.cpp"
template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;
#line 6 "test/verify/yosupo-tree-diameter.test.cpp"

#line 1 "graph/tree/tree-diameter.cpp"
/**
 * @brief Tree-Diameter(木の直径)
 */
template< typename T = int >
struct TreeDiameter : Graph< T > {
public:
  using Graph< T >::Graph;
  using Graph< T >::g;
  vector< Edge< T > > path;

  T build() {
    to.assign(g.size(), -1);
    auto p = dfs(0, -1);
    auto q = dfs(p.second, -1);

    int now = p.second;
    while(now != q.second) {
      for(auto &e : g[now]) {
        if(to[now] == e.to) {
          path.emplace_back(e);
        }
      }
      now = to[now];
    }
    return q.first;
  }

  explicit TreeDiameter(const Graph< T > &g) : Graph< T >(g) {}

private:
  vector< int > to;

  pair< T, int > dfs(int idx, int par) {
    pair< T, int > ret(0, idx);
    for(auto &e : g[idx]) {
      if(e.to == par) continue;
      auto cost = dfs(e.to, idx);
      cost.first += e.cost;
      if(ret < cost) {
        ret = cost;
        to[idx] = e.to;
      }
    }
    return ret;
  }
};
#line 8 "test/verify/yosupo-tree-diameter.test.cpp"

int main() {
  int N;
  cin >> N;
  TreeDiameter< int64_t > g(N);
  g.read(N - 1, 0, true);
  cout << g.build() << " ";
  cout << g.path.size() + 1 << "\n";
  cout << g.path[0].from << " " << g.path << "\n";
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
