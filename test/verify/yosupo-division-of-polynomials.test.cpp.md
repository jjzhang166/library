---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/combinatorics/mod-int.cpp
    title: math/combinatorics/mod-int.cpp
  - icon: ':heavy_check_mark:'
    path: math/fft/number-theoretic-transform-friendly-mod-int.cpp
    title: Number-Theoretic-Transform-Friendly-Mod-Int
  - icon: ':heavy_check_mark:'
    path: math/fps/formal-power-series-friendly-ntt.cpp
    title: "Formal-Power-Series-Friendly-NTT(NTTmod\u7528\u5F62\u5F0F\u7684\u51AA\u7D1A\
      \u6570)"
  - icon: ':heavy_check_mark:'
    path: other/printer.cpp
    title: "Printer(\u9AD8\u901F\u51FA\u529B)"
  - icon: ':heavy_check_mark:'
    path: other/scanner.cpp
    title: "Scanner(\u9AD8\u901F\u5165\u529B)"
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
    PROBLEM: https://judge.yosupo.jp/problem/division_of_polynomials
    links:
    - https://judge.yosupo.jp/problem/division_of_polynomials
  bundledCode: "#line 1 \"test/verify/yosupo-division-of-polynomials.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\n\n\
    #line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
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
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/yosupo-division-of-polynomials.test.cpp\"\
    \n\n#line 1 \"math/combinatorics/mod-int.cpp\"\ntemplate< int mod >\nstruct ModInt\
    \ {\n  int x;\n\n  ModInt() : x(0) {}\n\n  ModInt(int64_t y) : x(y >= 0 ? y %\
    \ mod : (mod - (-y) % mod) % mod) {}\n\n  ModInt &operator+=(const ModInt &p)\
    \ {\n    if((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n\n  ModInt &operator-=(const\
    \ ModInt &p) {\n    if((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n\
    \  }\n\n  ModInt &operator*=(const ModInt &p) {\n    x = (int) (1LL * x * p.x\
    \ % mod);\n    return *this;\n  }\n\n  ModInt &operator/=(const ModInt &p) {\n\
    \    *this *= p.inverse();\n    return *this;\n  }\n\n  ModInt operator-() const\
    \ { return ModInt(-x); }\n\n  ModInt operator+(const ModInt &p) const { return\
    \ ModInt(*this) += p; }\n\n  ModInt operator-(const ModInt &p) const { return\
    \ ModInt(*this) -= p; }\n\n  ModInt operator*(const ModInt &p) const { return\
    \ ModInt(*this) *= p; }\n\n  ModInt operator/(const ModInt &p) const { return\
    \ ModInt(*this) /= p; }\n\n  bool operator==(const ModInt &p) const { return x\
    \ == p.x; }\n\n  bool operator!=(const ModInt &p) const { return x != p.x; }\n\
    \n  ModInt inverse() const {\n    int a = x, b = mod, u = 1, v = 0, t;\n    while(b\
    \ > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v,\
    \ v);\n    }\n    return ModInt(u);\n  }\n\n  ModInt pow(int64_t n) const {\n\
    \    ModInt ret(1), mul(x);\n    while(n > 0) {\n      if(n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream\
    \ &operator<<(ostream &os, const ModInt &p) {\n    return os << p.x;\n  }\n\n\
    \  friend istream &operator>>(istream &is, ModInt &a) {\n    int64_t t;\n    is\
    \ >> t;\n    a = ModInt< mod >(t);\n    return (is);\n  }\n\n  static int get_mod()\
    \ { return mod; }\n};\n\nusing modint = ModInt< mod >;\n#line 1 \"math/fft/number-theoretic-transform-friendly-mod-int.cpp\"\
    \n/**\n * @brief Number-Theoretic-Transform-Friendly-Mod-Int\n */\ntemplate< typename\
    \ Mint >\nstruct NumberTheoreticTransformFriendlyModInt {\n\n  static vector<\
    \ Mint > dw, idw;\n  static int max_base;\n  static Mint root;\n\n  NumberTheoreticTransformFriendlyModInt()\
    \ = default;\n\n  static void init() {\n    if(dw.empty()) {\n      const unsigned\
    \ mod = Mint::get_mod();\n      assert(mod >= 3 && mod % 2 == 1);\n      auto\
    \ tmp = mod - 1;\n      max_base = 0;\n      while(tmp % 2 == 0) tmp >>= 1, max_base++;\n\
    \      root = 2;\n      while(root.pow((mod - 1) >> 1) == 1) root += 1;\n    \
    \  assert(root.pow(mod - 1) == 1);\n      dw.resize(max_base);\n      idw.resize(max_base);\n\
    \      for(int i = 0; i < max_base; i++) {\n        dw[i] = -root.pow((mod - 1)\
    \ >> (i + 2));\n        idw[i] = Mint(1) / dw[i];\n      }\n    }\n  }\n\n  static\
    \ void ntt(vector< Mint > &a) {\n    init();\n    const int n = (int) a.size();\n\
    \    assert((n & (n - 1)) == 0);\n    assert(__builtin_ctz(n) <= max_base);\n\
    \    for(int m = n; m >>= 1;) {\n      Mint w = 1;\n      for(int s = 0, k = 0;\
    \ s < n; s += 2 * m) {\n        for(int i = s, j = s + m; i < s + m; ++i, ++j)\
    \ {\n          auto x = a[i], y = a[j] * w;\n          a[i] = x + y, a[j] = x\
    \ - y;\n        }\n        w *= dw[__builtin_ctz(++k)];\n      }\n    }\n  }\n\
    \n  static void intt(vector< Mint > &a, bool f = true) {\n    init();\n    const\
    \ int n = (int) a.size();\n    assert((n & (n - 1)) == 0);\n    assert(__builtin_ctz(n)\
    \ <= max_base);\n    for(int m = 1; m < n; m *= 2) {\n      Mint w = 1;\n    \
    \  for(int s = 0, k = 0; s < n; s += 2 * m) {\n        for(int i = s, j = s +\
    \ m; i < s + m; ++i, ++j) {\n          auto x = a[i], y = a[j];\n          a[i]\
    \ = x + y, a[j] = (x - y) * w;\n        }\n        w *= idw[__builtin_ctz(++k)];\n\
    \      }\n    }\n    if(f) {\n      Mint inv_sz = Mint(1) / n;\n      for(int\
    \ i = 0; i < n; i++) a[i] *= inv_sz;\n    }\n  }\n\n  static vector< Mint > multiply(vector<\
    \ Mint > a, vector< Mint > b) {\n    int need = a.size() + b.size() - 1;\n   \
    \ int nbase = 1;\n    while((1 << nbase) < need) nbase++;\n    int sz = 1 << nbase;\n\
    \    a.resize(sz, 0);\n    b.resize(sz, 0);\n    ntt(a);\n    ntt(b);\n    Mint\
    \ inv_sz = Mint(1) / sz;\n    for(int i = 0; i < sz; i++) a[i] *= b[i] * inv_sz;\n\
    \    intt(a, false);\n    a.resize(need);\n    return a;\n  }\n};\n\ntemplate<\
    \ typename Mint >\nvector< Mint > NumberTheoreticTransformFriendlyModInt< Mint\
    \ >::dw = vector< Mint >();\ntemplate< typename Mint >\nvector< Mint > NumberTheoreticTransformFriendlyModInt<\
    \ Mint >::idw = vector< Mint >();\ntemplate< typename Mint >\nint NumberTheoreticTransformFriendlyModInt<\
    \ Mint >::max_base = 0;\ntemplate< typename Mint >\nMint NumberTheoreticTransformFriendlyModInt<\
    \ Mint >::root = Mint();\n#line 2 \"math/fps/formal-power-series-friendly-ntt.cpp\"\
    \n\n/**\n * @brief Formal-Power-Series-Friendly-NTT(NTTmod\u7528\u5F62\u5F0F\u7684\
    \u51AA\u7D1A\u6570)\n * @docs docs/formal-power-series-friendly-ntt.md\n */\n\
    template< typename T >\nstruct FormalPowerSeriesFriendlyNTT : vector< T > {\n\
    \  using vector< T >::vector;\n  using P = FormalPowerSeriesFriendlyNTT;\n  using\
    \ NTT = NumberTheoreticTransformFriendlyModInt< T >;\n\n  P pre(int deg) const\
    \ {\n    return P(begin(*this), begin(*this) + min((int) this->size(), deg));\n\
    \  }\n\n  P rev(int deg = -1) const {\n    P ret(*this);\n    if(deg != -1) ret.resize(deg,\
    \ T(0));\n    reverse(begin(ret), end(ret));\n    return ret;\n  }\n\n  void shrink()\
    \ {\n    while(this->size() && this->back() == T(0)) this->pop_back();\n  }\n\n\
    \  P operator+(const P &r) const { return P(*this) += r; }\n\n  P operator+(const\
    \ T &v) const { return P(*this) += v; }\n\n  P operator-(const P &r) const { return\
    \ P(*this) -= r; }\n\n  P operator-(const T &v) const { return P(*this) -= v;\
    \ }\n\n  P operator*(const P &r) const { return P(*this) *= r; }\n\n  P operator*(const\
    \ T &v) const { return P(*this) *= v; }\n\n  P operator/(const P &r) const { return\
    \ P(*this) /= r; }\n\n  P operator%(const P &r) const { return P(*this) %= r;\
    \ }\n\n  P &operator+=(const P &r) {\n    if(r.size() > this->size()) this->resize(r.size());\n\
    \    for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n\n  P &operator-=(const P &r) {\n    if(r.size() > this->size()) this->resize(r.size());\n\
    \    for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n\
    \  }\n\n  // https://judge.yosupo.jp/problem/convolution_mod\n  P &operator*=(const\
    \ P &r) {\n    if(this->empty() || r.empty()) {\n      this->clear();\n      return\
    \ *this;\n    }\n    auto ret = NTT::multiply(*this, r);\n    return *this = {begin(ret),\
    \ end(ret)};\n  }\n\n  P &operator/=(const P &r) {\n    if(this->size() < r.size())\
    \ {\n      this->clear();\n      return *this;\n    }\n    int n = this->size()\
    \ - r.size() + 1;\n    return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \  }\n\n  P &operator%=(const P &r) {\n    *this -= *this / r * r;\n    shrink();\n\
    \    return *this;\n  }\n\n  // https://judge.yosupo.jp/problem/division_of_polynomials\n\
    \  pair< P, P > div_mod(const P &r) {\n    P q = *this / r;\n    P x = *this -\
    \ q * r;\n    x.shrink();\n    return make_pair(q, x);\n  }\n\n  P operator-()\
    \ const {\n    P ret(this->size());\n    for(int i = 0; i < this->size(); i++)\
    \ ret[i] = -(*this)[i];\n    return ret;\n  }\n\n  P &operator+=(const T &r) {\n\
    \    if(this->empty()) this->resize(1);\n    (*this)[0] += r;\n    return *this;\n\
    \  }\n\n  P &operator-=(const T &r) {\n    if(this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n\n  P &operator*=(const T &v) {\n\
    \    for(int i = 0; i < this->size(); i++) (*this)[i] *= v;\n    return *this;\n\
    \  }\n\n  P dot(P r) const {\n    P ret(min(this->size(), r.size()));\n    for(int\
    \ i = 0; i < ret.size(); i++) ret[i] = (*this)[i] * r[i];\n    return ret;\n \
    \ }\n\n  P operator>>(int sz) const {\n    if(this->size() <= sz) return {};\n\
    \    P ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n    return\
    \ ret;\n  }\n\n  P operator<<(int sz) const {\n    P ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, T(0));\n    return ret;\n  }\n\n  T operator()(T x) const {\n    T r = 0,\
    \ w = 1;\n    for(auto &v : *this) {\n      r += w * v;\n      w *= x;\n    }\n\
    \    return r;\n  }\n\n  P diff() const {\n    const int n = (int) this->size();\n\
    \    P ret(max(0, n - 1));\n    for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i]\
    \ * T(i);\n    return ret;\n  }\n\n  P integral() const {\n    const int n = (int)\
    \ this->size();\n    P ret(n + 1);\n    ret[0] = T(0);\n    for(int i = 0; i <\
    \ n; i++) ret[i + 1] = (*this)[i] / T(i + 1);\n    return ret;\n  }\n\n  // https://judge.yosupo.jp/problem/inv_of_formal_power_series\n\
    \  // F(0) must not be 0\n  P inv(int deg = -1) const {\n    assert(((*this)[0])\
    \ != T(0));\n    const int n = (int) this->size();\n    if(deg == -1) deg = n;\n\
    \    P res(deg);\n    res[0] = {T(1) / (*this)[0]};\n    for(int d = 1; d < deg;\
    \ d <<= 1) {\n      P f(2 * d), g(2 * d);\n      for(int j = 0; j < min(n, 2 *\
    \ d); j++) f[j] = (*this)[j];\n      for(int j = 0; j < d; j++) g[j] = res[j];\n\
    \      NTT::ntt(f);\n      NTT::ntt(g);\n      f = f.dot(g);\n      NTT::intt(f);\n\
    \      for(int j = 0; j < d; j++) f[j] = 0;\n      NTT::ntt(f);\n      for(int\
    \ j = 0; j < 2 * d; j++) f[j] *= g[j];\n      NTT::intt(f);\n      for(int j =\
    \ d; j < min(2 * d, deg); j++) res[j] = -f[j];\n    }\n    return res;\n  }\n\n\
    \  // https://judge.yosupo.jp/problem/log_of_formal_power_series\n  // F(0) must\
    \ be 1\n  P log(int deg = -1) const {\n    assert((*this)[0] == T(1));\n    const\
    \ int n = (int) this->size();\n    if(deg == -1) deg = n;\n    return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n  }\n\n  // https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\n\
    \  P sqrt(int deg = -1, const function< T(T) > &get_sqrt = [](T) { return T(1);\
    \ }) const {\n    const int n = (int) this->size();\n    if(deg == -1) deg = n;\n\
    \    if((*this)[0] == T(0)) {\n      for(int i = 1; i < n; i++) {\n        if((*this)[i]\
    \ != T(0)) {\n          if(i & 1) return {};\n          if(deg - i / 2 <= 0) break;\n\
    \          auto ret = (*this >> i).sqrt(deg - i / 2, get_sqrt);\n          if(ret.empty())\
    \ return {};\n          ret = ret << (i / 2);\n          if(ret.size() < deg)\
    \ ret.resize(deg, T(0));\n          return ret;\n        }\n      }\n      return\
    \ P(deg, 0);\n    }\n    auto sqr = T(get_sqrt((*this)[0]));\n    if(sqr * sqr\
    \ != (*this)[0]) return {};\n    P ret{sqr};\n    T inv2 = T(1) / T(2);\n    for(int\
    \ i = 1; i < deg; i <<= 1) {\n      ret = (ret + pre(i << 1) * ret.inv(i << 1))\
    \ * inv2;\n    }\n    return ret.pre(deg);\n  }\n\n  P sqrt(const function< T(T)\
    \ > &get_sqrt, int deg = -1) const {\n    return sqrt(deg, get_sqrt);\n  }\n\n\
    \  // https://judge.yosupo.jp/problem/exp_of_formal_power_series\n  // F(0) must\
    \ be 0\n  P exp(int deg = -1) const {\n    if(deg == -1) deg = this->size();\n\
    \    assert((*this)[0] == T(0));\n\n    P inv;\n    inv.reserve(deg + 1);\n  \
    \  inv.push_back(T(0));\n    inv.push_back(T(1));\n\n    auto inplace_integral\
    \ = [&](P &F) -> void {\n      const int n = (int) F.size();\n      auto mod =\
    \ T::get_mod();\n      while((int) inv.size() <= n) {\n        int i = inv.size();\n\
    \        inv.push_back((-inv[mod % i]) * (mod / i));\n      }\n      F.insert(begin(F),\
    \ T(0));\n      for(int i = 1; i <= n; i++) F[i] *= inv[i];\n    };\n\n    auto\
    \ inplace_diff = [](P &F) -> void {\n      if(F.empty()) return;\n      F.erase(begin(F));\n\
    \      T coeff = 1, one = 1;\n      for(int i = 0; i < (int) F.size(); i++) {\n\
    \        F[i] *= coeff;\n        coeff += one;\n      }\n    };\n\n    P b{1,\
    \ 1 < (int) this->size() ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};\n    for(int m\
    \ = 2; m < deg; m *= 2) {\n      auto y = b;\n      y.resize(2 * m);\n      NTT::ntt(y);\n\
    \      z1 = z2;\n      P z(m);\n      for(int i = 0; i < m; ++i) z[i] = y[i] *\
    \ z1[i];\n      NTT::intt(z);\n      fill(begin(z), begin(z) + m / 2, T(0));\n\
    \      NTT::ntt(z);\n      for(int i = 0; i < m; ++i) z[i] *= -z1[i];\n      NTT::intt(z);\n\
    \      c.insert(end(c), begin(z) + m / 2, end(z));\n      z2 = c;\n      z2.resize(2\
    \ * m);\n      NTT::ntt(z2);\n      P x(begin(*this), begin(*this) + min< int\
    \ >(this->size(), m));\n      inplace_diff(x);\n      x.push_back(T(0));\n   \
    \   NTT::ntt(x);\n      for(int i = 0; i < m; ++i) x[i] *= y[i];\n      NTT::intt(x);\n\
    \      x -= b.diff();\n      x.resize(2 * m);\n      for(int i = 0; i < m - 1;\
    \ ++i) x[m + i] = x[i], x[i] = T(0);\n      NTT::ntt(x);\n      for(int i = 0;\
    \ i < 2 * m; ++i) x[i] *= z2[i];\n      NTT::intt(x);\n      x.pop_back();\n \
    \     inplace_integral(x);\n      for(int i = m; i < min< int >(this->size(),\
    \ 2 * m); ++i) x[i] += (*this)[i];\n      fill(begin(x), begin(x) + m, T(0));\n\
    \      NTT::ntt(x);\n      for(int i = 0; i < 2 * m; ++i) x[i] *= y[i];\n    \
    \  NTT::intt(x);\n      b.insert(end(b), begin(x) + m, end(x));\n    }\n    return\
    \ P{begin(b), begin(b) + deg};\n  }\n\n  // https://judge.yosupo.jp/problem/pow_of_formal_power_series\n\
    \  P pow(int64_t k, int deg = -1) const {\n    const int n = (int) this->size();\n\
    \    if(deg == -1) deg = n;\n    for(int i = 0; i < n; i++) {\n      if((*this)[i]\
    \ != T(0)) {\n        T rev = T(1) / (*this)[i];\n        P ret = (((*this * rev)\
    \ >> i).log() * k).exp() * ((*this)[i].pow(k));\n        if(i * k > deg) return\
    \ P(deg, T(0));\n        ret = (ret << (i * k)).pre(deg);\n        if(ret.size()\
    \ < deg) ret.resize(deg, T(0));\n        return ret;\n      }\n    }\n    return\
    \ *this;\n  }\n\n  P mod_pow(int64_t k, P g) const {\n    P modinv = g.rev().inv();\n\
    \    auto get_div = [&](P base) {\n      if(base.size() < g.size()) {\n      \
    \  base.clear();\n        return base;\n      }\n      int n = base.size() - g.size()\
    \ + 1;\n      return (base.rev().pre(n) * modinv.pre(n)).pre(n).rev(n);\n    };\n\
    \    P x(*this), ret{1};\n    while(k > 0) {\n      if(k & 1) {\n        ret *=\
    \ x;\n        ret -= get_div(ret) * g;\n        ret.shrink();\n      }\n     \
    \ x *= x;\n      x -= get_div(x) * g;\n      x.shrink();\n      k >>= 1;\n   \
    \ }\n    return ret;\n  }\n\n  // https://judge.yosupo.jp/problem/polynomial_taylor_shift\n\
    \  P taylor_shift(T c) const {\n    int n = (int) this->size();\n    vector< T\
    \ > fact(n), rfact(n);\n    fact[0] = rfact[0] = T(1);\n    for(int i = 1; i <\
    \ n; i++) fact[i] = fact[i - 1] * T(i);\n    rfact[n - 1] = T(1) / fact[n - 1];\n\
    \    for(int i = n - 1; i > 1; i--) rfact[i - 1] = rfact[i] * T(i);\n    P p(*this);\n\
    \    for(int i = 0; i < n; i++) p[i] *= fact[i];\n    p = p.rev();\n    P bs(n,\
    \ T(1));\n    for(int i = 1; i < n; i++) bs[i] = bs[i - 1] * c * rfact[i] * fact[i\
    \ - 1];\n    p = (p * bs).pre(n);\n    p = p.rev();\n    for(int i = 0; i < n;\
    \ i++) p[i] *= rfact[i];\n    return p;\n  }\n};\n\n\ntemplate< typename Mint\
    \ >\nusing FPS = FormalPowerSeriesFriendlyNTT< Mint >;\n#line 7 \"test/verify/yosupo-division-of-polynomials.test.cpp\"\
    \n\n#line 1 \"other/scanner.cpp\"\n/**\n * @brief Scanner(\u9AD8\u901F\u5165\u529B\
    )\n */\nstruct Scanner {\npublic:\n\n  explicit Scanner(FILE *fp) : fp(fp) {}\n\
    \n  template< typename T, typename... E >\n  void read(T &t, E &... e) {\n   \
    \ read_single(t);\n    read(e...);\n  }\n\nprivate:\n  static constexpr size_t\
    \ line_size = 1 << 16;\n  static constexpr size_t int_digits = 20;\n  char line[line_size\
    \ + 1] = {};\n  FILE *fp = nullptr;\n  char *st = line;\n  char *ed = line;\n\n\
    \  void read() {}\n\n  static inline bool is_space(char c) {\n    return c <=\
    \ ' ';\n  }\n\n  void reread() {\n    ptrdiff_t len = ed - st;\n    memmove(line,\
    \ st, len);\n    char *tmp = line + len;\n    ed = tmp + fread(tmp, 1, line_size\
    \ - len, fp);\n    *ed = 0;\n    st = line;\n  }\n\n  void skip_space() {\n  \
    \  while(true) {\n      if(st == ed) reread();\n      while(*st && is_space(*st))\
    \ ++st;\n      if(st != ed) return;\n    }\n  }\n\n  template< typename T, enable_if_t<\
    \ is_integral< T >::value, int > = 0 >\n  void read_single(T &s) {\n    skip_space();\n\
    \    if(st + int_digits >= ed) reread();\n    bool neg = false;\n    if(is_signed<\
    \ T >::value && *st == '-') {\n      neg = true;\n      ++st;\n    }\n    typename\
    \ make_unsigned< T >::type y = *st++ - '0';\n    while(*st >= '0') {\n      y\
    \ = 10 * y + *st++ - '0';\n    }\n    s = (neg ? -y : y);\n  }\n\n  template<\
    \ typename T, enable_if_t< is_same< T, string >::value, int > = 0 >\n  void read_single(T\
    \ &s) {\n    s = \"\";\n    skip_space();\n    while(true) {\n      char *base\
    \ = st;\n      while(*st && !is_space(*st)) ++st;\n      s += string(base, st);\n\
    \      if(st != ed) return;\n      reread();\n    }\n  }\n\n  template< typename\
    \ T >\n  void read_single(vector< T > &s) {\n    for(auto &d : s) read(d);\n \
    \ }\n};\n#line 1 \"other/printer.cpp\"\n/**\n * @brief Printer(\u9AD8\u901F\u51FA\
    \u529B)\n */\nstruct Printer {\npublic:\n  explicit Printer(FILE *fp) : fp(fp)\
    \ {}\n\n  ~Printer() { flush(); }\n\n  template< bool f = false, typename T, typename...\
    \ E >\n  void write(const T &t, const E &... e) {\n    if(f) write_single(' ');\n\
    \    write_single(t);\n    write< true >(e...);\n  }\n\n  template< typename...\
    \ T >\n  void writeln(const T &...t) {\n    write(t...);\n    write_single('\\\
    n');\n  }\n\n  void flush() {\n    fwrite(line, 1, st - line, fp);\n    st = line;\n\
    \  }\n\nprivate:\n  FILE *fp = nullptr;\n  static constexpr size_t line_size =\
    \ 1 << 16;\n  static constexpr size_t int_digits = 20;\n  char line[line_size\
    \ + 1] = {};\n  char small[32] = {};\n  char *st = line;\n\n  template< bool f\
    \ = false >\n  void write() {}\n\n  void write_single(const char &t) {\n    if(st\
    \ + 1 >= line + line_size) flush();\n    *st++ = t;\n  }\n\n  template< typename\
    \ T, enable_if_t< is_integral< T >::value, int > = 0 >\n  void write_single(T\
    \ s) {\n    if(st + int_digits >= line + line_size) flush();\n    if(s == 0) {\n\
    \      write_single('0');\n      return;\n    }\n    if(s < 0) {\n      write_single('-');\n\
    \      s = -s;\n    }\n    char *mp = small + sizeof(small);\n    typename make_unsigned<\
    \ T >::type y = s;\n    size_t len = 0;\n    while(y > 0) {\n      *--mp = y %\
    \ 10 + '0';\n      y /= 10;\n      ++len;\n    }\n    memmove(st, mp, len);\n\
    \    st += len;\n  }\n\n  void write_single(const string &s) {\n    for(auto &c\
    \ : s) write_single(c);\n  }\n\n  void write_single(const char *s) {\n    while(*s\
    \ != 0) write_single(*s++);\n  }\n\n  template< typename T >\n  void write_single(const\
    \ vector< T > &s) {\n    for(size_t i = 0; i < s.size(); i++) {\n      if(i) write_single('\
    \ ');\n      write_single(s[i]);\n    }\n  }\n};\n#line 10 \"test/verify/yosupo-division-of-polynomials.test.cpp\"\
    \n\nconst int MOD = 998244353;\nusing mint = ModInt< MOD >;\n\nint main() {\n\
    \  Scanner in(stdin);\n  Printer out(stdout);\n\n  int N, M;\n  in.read(N, M);\n\
    \  FPS< mint > f, g;\n  f.reserve(N);\n  g.reserve(M);\n  for(int i = 0; i < N;\
    \ i++) {\n    int x;\n    in.read(x);\n    f.emplace_back(x);\n  }\n  for(int\
    \ i = 0; i < M; i++) {\n    int x;\n    in.read(x);\n    g.emplace_back(x);\n\
    \  }\n  auto[q, r] = f.div_mod(g);\n  out.writeln(q.size(), r.size());\n  for(int\
    \ i = 0; i < q.size(); i++) {\n    if(i > 0) out.write(' ');\n    out.write(q[i].x);\n\
    \  }\n  out.writeln();\n  for(int i = 0; i < r.size(); i++) {\n    if(i > 0) out.write('\
    \ ');\n    out.write(r[i].x);\n  }\n  out.writeln();\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\
    \n\n#include \"../../template/template.cpp\"\n\n#include \"../../math/combinatorics/mod-int.cpp\"\
    \n#include \"../../math/fps/formal-power-series-friendly-ntt.cpp\"\n\n#include\
    \ \"../../other/scanner.cpp\"\n#include \"../../other/printer.cpp\"\n\nconst int\
    \ MOD = 998244353;\nusing mint = ModInt< MOD >;\n\nint main() {\n  Scanner in(stdin);\n\
    \  Printer out(stdout);\n\n  int N, M;\n  in.read(N, M);\n  FPS< mint > f, g;\n\
    \  f.reserve(N);\n  g.reserve(M);\n  for(int i = 0; i < N; i++) {\n    int x;\n\
    \    in.read(x);\n    f.emplace_back(x);\n  }\n  for(int i = 0; i < M; i++) {\n\
    \    int x;\n    in.read(x);\n    g.emplace_back(x);\n  }\n  auto[q, r] = f.div_mod(g);\n\
    \  out.writeln(q.size(), r.size());\n  for(int i = 0; i < q.size(); i++) {\n \
    \   if(i > 0) out.write(' ');\n    out.write(q[i].x);\n  }\n  out.writeln();\n\
    \  for(int i = 0; i < r.size(); i++) {\n    if(i > 0) out.write(' ');\n    out.write(r[i].x);\n\
    \  }\n  out.writeln();\n}\n\n"
  dependsOn:
  - template/template.cpp
  - math/combinatorics/mod-int.cpp
  - math/fps/formal-power-series-friendly-ntt.cpp
  - math/fft/number-theoretic-transform-friendly-mod-int.cpp
  - other/scanner.cpp
  - other/printer.cpp
  isVerificationFile: true
  path: test/verify/yosupo-division-of-polynomials.test.cpp
  requiredBy: []
  timestamp: '2021-07-13 01:03:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-division-of-polynomials.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-division-of-polynomials.test.cpp
- /verify/test/verify/yosupo-division-of-polynomials.test.cpp.html
title: test/verify/yosupo-division-of-polynomials.test.cpp
---