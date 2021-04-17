---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/knapsack-limitations.cpp
    title: "Knapsack-Limitations(\u500B\u6570\u5236\u9650\u3064\u304D\u30CA\u30C3\u30D7\
      \u30B5\u30C3\u30AF\u554F\u984C) $O(NW)$"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G
  bundledCode: "#line 1 \"test/verify/aoj-dpl-1-g.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing int64 = long long;\nconst int mod = 1e9 + 7;\n\nconst int64 infll\
    \ = (1LL << 62) - 1;\nconst int inf = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(10);\n    cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\
    \n\ntemplate< typename T1, typename T2 >\nostream &operator<<(ostream &os, const\
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
    \  FixPoint(F &&f) : F(forward< F >(f)) {}\n \n  template< typename... Args >\n\
    \  decltype(auto) operator()(Args &&... args) const {\n    return F::operator()(*this,\
    \ forward< Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/aoj-dpl-1-g.test.cpp\"\
    \n\n#line 1 \"dp/knapsack-limitations.cpp\"\n/**\n * @brief Knapsack-Limitations(\u500B\
    \u6570\u5236\u9650\u3064\u304D\u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u554F\u984C\
    ) $O(NW)$\n * @docs docs/knapsack-limitations.md\n */\ntemplate< typename T, typename\
    \ Compare = greater< T > >\nvector< T > knapsack_limitations(const vector< int\
    \ > &w, const vector< int > &m, const vector< T > &v,\n                      \
    \           const int &W, const T &NG, const Compare &comp = Compare()) {\n  const\
    \ int N = (int) w.size();\n  vector< T > dp(W + 1, NG), deqv(W + 1);\n  dp[0]\
    \ = T();\n  vector< int > deq(W + 1);\n  for(int i = 0; i < N; i++) {\n    for(int\
    \ a = 0; a < w[i]; a++) {\n      int s = 0, t = 0;\n      for(int j = 0; w[i]\
    \ * j + a <= W; j++) {\n        if(dp[w[i] * j + a] != NG) {\n          auto val\
    \ = dp[w[i] * j + a] - j * v[i];\n          while(s < t && comp(val, deqv[t -\
    \ 1])) --t;\n          deq[t] = j;\n          deqv[t++] = val;\n        }\n  \
    \      if(s < t) {\n          dp[j * w[i] + a] = deqv[s] + j * v[i];\n       \
    \   if(deq[s] == j - m[i]) ++s;\n        }\n      }\n    }\n  }\n  return dp;\n\
    }\n#line 6 \"test/verify/aoj-dpl-1-g.test.cpp\"\n\nint main() {\n  int N, W;\n\
    \  cin >> N >> W;\n  vector< int > v(N), w(N), m(N);\n  for(int i = 0; i < N;\
    \ i++) {\n    cin >> v[i] >> w[i] >> m[i];\n  }\n  auto ret = knapsack_limitations(w,\
    \ m, v, W, -1);\n  cout << *max_element(begin(ret), end(ret)) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G\"\
    \n\n#include \"../../template/template.cpp\"\n\n#include \"../../dp/knapsack-limitations.cpp\"\
    \n\nint main() {\n  int N, W;\n  cin >> N >> W;\n  vector< int > v(N), w(N), m(N);\n\
    \  for(int i = 0; i < N; i++) {\n    cin >> v[i] >> w[i] >> m[i];\n  }\n  auto\
    \ ret = knapsack_limitations(w, m, v, W, -1);\n  cout << *max_element(begin(ret),\
    \ end(ret)) << endl;\n}\n"
  dependsOn:
  - template/template.cpp
  - dp/knapsack-limitations.cpp
  isVerificationFile: true
  path: test/verify/aoj-dpl-1-g.test.cpp
  requiredBy: []
  timestamp: '2020-02-26 02:30:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-dpl-1-g.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-dpl-1-g.test.cpp
- /verify/test/verify/aoj-dpl-1-g.test.cpp.html
title: test/verify/aoj-dpl-1-g.test.cpp
---