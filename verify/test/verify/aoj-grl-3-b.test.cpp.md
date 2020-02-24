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


# :heavy_check_mark: test/verify/aoj-grl-3-b.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/verify/aoj-grl-3-b.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-30 23:02:43+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/others/lowlink.cpp.html">graph/others/lowlink.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>
* :heavy_check_mark: <a href="../../../library/template/template.cpp.html">template/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include "../../template/template.cpp"
#include "../../graph/template.cpp"

#include "../../graph/others/lowlink.cpp"

int main() {
  int V, E;
  scanf("%d %d", &V, &E);
  UnWeightedGraph g(V);
  for(int i = 0; i < E; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  LowLink< UnWeightedGraph > lowlink(g);
  lowlink.build();
  sort(lowlink.bridge.begin(), lowlink.bridge.end());
  for(auto &p : lowlink.bridge) printf("%d %d\n", p.first, p.second);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/verify/aoj-grl-3-b.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#line 1 "test/verify/../../template/template.cpp"
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
#line 1 "test/verify/../../graph/template.cpp"
template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
#line 5 "test/verify/aoj-grl-3-b.test.cpp"

#line 1 "test/verify/../../graph/others/lowlink.cpp"
template< typename G >
struct LowLink {
  const G &g;
  vector< int > used, ord, low;
  vector< int > articulation;
  vector< pair< int, int > > bridge;
 
  LowLink(const G &g) : g(g) {}
 
  int dfs(int idx, int k, int par) {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];
    bool is_articulation = false;
    int cnt = 0;
    for(auto &to : g[idx]) {
      if(!used[to]) {
        ++cnt;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        is_articulation |= ~par && low[to] >= ord[idx];
        if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));
      } else if(to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_articulation |= par == -1 && cnt > 1;
    if(is_articulation) articulation.push_back(idx);
    return k;
  }
 
  virtual void build() {
    used.assign(g.size(), 0);
    ord.assign(g.size(), 0);
    low.assign(g.size(), 0);
    int k = 0;
    for(int i = 0; i < g.size(); i++) {
      if(!used[i]) k = dfs(i, k, -1);
    }
  }
};
#line 7 "test/verify/aoj-grl-3-b.test.cpp"

int main() {
  int V, E;
  scanf("%d %d", &V, &E);
  UnWeightedGraph g(V);
  for(int i = 0; i < E; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  LowLink< UnWeightedGraph > lowlink(g);
  lowlink.build();
  sort(lowlink.bridge.begin(), lowlink.bridge.end());
  for(auto &p : lowlink.bridge) printf("%d %d\n", p.first, p.second);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
