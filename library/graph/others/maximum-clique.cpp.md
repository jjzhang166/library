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


# :heavy_check_mark: Maximum-Clique(最大クリーク) <small>(graph/others/maximum-clique.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e557c7f962c39680942b9dada22cabec">graph/others</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/others/maximum-clique.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-25 22:57:51+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/verify/yosupo-maximum-independent-set-2.test.cpp.html">test/verify/yosupo-maximum-independent-set-2.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Maximum-Clique(最大クリーク)
 */
template< int V >
struct MaximumClique {
  using B = bitset< V >;
  vector< B > g, col_buf;

  struct P {
    int idx, col, deg;

    P(int idx, int col, int deg) : idx(idx), col(col), deg(deg) {}
  };

  MaximumClique() = default;

  explicit MaximumClique(int N) : g(N), col_buf(N) {}

  void add_edge(int a, int b) {
    g[a].set(b);
    g[b].set(a);
  }

  vector< int > now, clique;

  void dfs(vector< P > &rem) {
    if(clique.size() < now.size()) clique = now;
    sort(begin(rem), end(rem), [](const P &a, const P &b) {
      return a.deg > b.deg;
    });
    int max_c = 1;
    for(auto &p : rem) {
      p.col = 0;
      while((g[p.idx] & col_buf[p.col]).any()) ++p.col;
      max_c = max(max_c, p.idx + 1);
      col_buf[p.col].set(p.idx);
    }
    for(int i = 0; i < max_c; i++) col_buf[i].reset();
    sort(begin(rem), end(rem), [&](const P &a, const P &b) {
      return a.col < b.col;
    });
    for(; !rem.empty(); rem.pop_back()) {
      auto &p = rem.back();
      if(now.size() + p.col + 1 <= clique.size()) break;
      vector< P > nrem;
      B bs;
      for(auto &q : rem) {
        if(g[p.idx][q.idx]) {
          nrem.emplace_back(q.idx, -1, 0);
          bs.set(q.idx);
        }
      }
      for(auto &q : nrem) {
        q.deg = (bs & g[q.idx]).count();
      }
      now.emplace_back(p.idx);
      dfs(nrem);
      now.pop_back();
    }
  }

  vector< int > solve() {
    vector< P > remark;
    for(int i = 0; i < g.size(); i++) {
      remark.emplace_back(i, -1, (int) g[i].size());
    }
    dfs(remark);
    return clique;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/others/maximum-clique.cpp"
/**
 * @brief Maximum-Clique(最大クリーク)
 */
template< int V >
struct MaximumClique {
  using B = bitset< V >;
  vector< B > g, col_buf;

  struct P {
    int idx, col, deg;

    P(int idx, int col, int deg) : idx(idx), col(col), deg(deg) {}
  };

  MaximumClique() = default;

  explicit MaximumClique(int N) : g(N), col_buf(N) {}

  void add_edge(int a, int b) {
    g[a].set(b);
    g[b].set(a);
  }

  vector< int > now, clique;

  void dfs(vector< P > &rem) {
    if(clique.size() < now.size()) clique = now;
    sort(begin(rem), end(rem), [](const P &a, const P &b) {
      return a.deg > b.deg;
    });
    int max_c = 1;
    for(auto &p : rem) {
      p.col = 0;
      while((g[p.idx] & col_buf[p.col]).any()) ++p.col;
      max_c = max(max_c, p.idx + 1);
      col_buf[p.col].set(p.idx);
    }
    for(int i = 0; i < max_c; i++) col_buf[i].reset();
    sort(begin(rem), end(rem), [&](const P &a, const P &b) {
      return a.col < b.col;
    });
    for(; !rem.empty(); rem.pop_back()) {
      auto &p = rem.back();
      if(now.size() + p.col + 1 <= clique.size()) break;
      vector< P > nrem;
      B bs;
      for(auto &q : rem) {
        if(g[p.idx][q.idx]) {
          nrem.emplace_back(q.idx, -1, 0);
          bs.set(q.idx);
        }
      }
      for(auto &q : nrem) {
        q.deg = (bs & g[q.idx]).count();
      }
      now.emplace_back(p.idx);
      dfs(nrem);
      now.pop_back();
    }
  }

  vector< int > solve() {
    vector< P > remark;
    for(int i = 0; i < g.size(); i++) {
      remark.emplace_back(i, -1, (int) g[i].size());
    }
    dfs(remark);
    return clique;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
