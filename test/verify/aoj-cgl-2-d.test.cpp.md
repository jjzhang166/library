---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.cpp
    title: geometry/base.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.cpp
    title: geometry/ccw.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_sp.cpp
    title: geometry/distance_sp.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_ss.cpp
    title: geometry/distance_ss.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_sp.cpp
    title: geometry/is_intersect_sp.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_ss.cpp
    title: geometry/is_intersect_ss.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.cpp
    title: geometry/line.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.cpp
    title: geometry/point.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.cpp
    title: geometry/projection.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.cpp
    title: geometry/segment.cpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
  bundledCode: "#line 1 \"test/verify/aoj-cgl-2-d.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\"\
    \n#define ERROR 0.00000001\n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing int64 = long long;\nconst int mod = 1e9 + 7;\n\
    \nconst int64 infll = (1LL << 62) - 1;\nconst int inf = (1 << 30) - 1;\n\nstruct\
    \ IoSetup {\n  IoSetup() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(10);\n    cerr << fixed << setprecision(10);\n\
    \  }\n} iosetup;\n\ntemplate< typename T1, typename T2 >\nostream &operator<<(ostream\
    \ &os, const pair< T1, T2 >& p) {\n  os << p.first << \" \" << p.second;\n  return\
    \ os;\n}\n\ntemplate< typename T1, typename T2 >\nistream &operator>>(istream\
    \ &is, pair< T1, T2 > &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\n\
    template< typename T >\nostream &operator<<(ostream &os, const vector< T > &v)\
    \ {\n  for(int i = 0; i < (int) v.size(); i++) {\n    os << v[i] << (i + 1 !=\
    \ v.size() ? \" \" : \"\");\n  }\n  return os;\n}\n\ntemplate< typename T >\n\
    istream &operator>>(istream &is, vector< T > &v) {\n  for(T &in : v) is >> in;\n\
    \  return is;\n}\n\ntemplate< typename T1, typename T2 >\ninline bool chmax(T1\
    \ &a, T2 b) { return a < b && (a = b, true); }\n\ntemplate< typename T1, typename\
    \ T2 >\ninline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }\n\n\
    template< typename T = int64 >\nvector< T > make_v(size_t a) {\n  return vector<\
    \ T >(a);\n}\n\ntemplate< typename T, typename... Ts >\nauto make_v(size_t a,\
    \ Ts... ts) {\n  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));\n\
    }\n\ntemplate< typename T, typename V >\ntypename enable_if< is_class< T >::value\
    \ == 0 >::type fill_v(T &t, const V &v) {\n  t = v;\n}\n\ntemplate< typename T,\
    \ typename V >\ntypename enable_if< is_class< T >::value != 0 >::type fill_v(T\
    \ &t, const V &v) {\n  for(auto &e : t) fill_v(e, v);\n}\n\ntemplate< typename\
    \ F >\nstruct FixPoint : F {\n  explicit FixPoint(F &&f) : F(forward< F >(f))\
    \ {}\n\n  template< typename... Args >\n  decltype(auto) operator()(Args &&...\
    \ args) const {\n    return F::operator()(*this, forward< Args >(args)...);\n\
    \  }\n};\n \ntemplate< typename F >\ninline decltype(auto) MFP(F &&f) {\n  return\
    \ FixPoint< F >{forward< F >(f)};\n}\n#line 5 \"test/verify/aoj-cgl-2-d.test.cpp\"\
    \n\n#line 2 \"geometry/base.cpp\"\n\nnamespace geometry {\n  using Real = double;\n\
    \  const Real EPS = 1e-8;\n  const Real PI = acos(static_cast< Real >(-1));\n\n\
    \  enum {\n    OUT, ON, IN\n  };\n\n  inline int sign(const Real &r) {\n    return\
    \ r <= -EPS ? -1 : r >= EPS ? 1 : 0;\n  }\n\n  inline bool equals(const Real &a,\
    \ const Real &b) {\n    return sign(a - b) == 0;\n  }\n}\n#line 3 \"geometry/point.cpp\"\
    \n\nnamespace geometry {\n  using Point = complex< Real >;\n\n  istream &operator>>(istream\
    \ &is, Point &p) {\n    Real a, b;\n    is >> a >> b;\n    p = Point(a, b);\n\
    \    return is;\n  }\n\n  ostream &operator<<(ostream &os, const Point &p) {\n\
    \    return os << real(p) << \" \" << imag(p);\n  }\n\n  Point operator*(const\
    \ Point &p, const Real &d) {\n    return Point(real(p) * d, imag(p) * d);\n  }\n\
    \n  // rotate point p counterclockwise by theta rad\n  Point rotate(Real theta,\
    \ const Point &p) {\n    return Point(cos(theta) * real(p) - sin(theta) * imag(p),\
    \ sin(theta) * real(p) + cos(theta) * imag(p));\n  }\n\n  Real cross(const Point\
    \ &a, const Point &b) {\n    return real(a) * imag(b) - imag(a) * real(b);\n \
    \ }\n\n  Real dot(const Point &a, const Point &b) {\n    return real(a) * real(b)\
    \ + imag(a) * imag(b);\n  }\n\n  bool compare_x(const Point &a, const Point &b)\
    \ {\n    return equals(real(a), real(b)) ? imag(a) < imag(b) : real(a) < real(b);\n\
    \  }\n\n  bool compare_y(const Point &a, const Point &b) {\n    return equals(imag(a),\
    \ imag(b)) ? real(a) < real(b) : imag(a) < imag(b);\n  }\n\n  using Points = vector<\
    \ Point >;\n}\n#line 3 \"geometry/line.cpp\"\n\nnamespace geometry {\n  struct\
    \ Line {\n    Point a, b;\n\n    Line() = default;\n\n    Line(const Point &a,\
    \ const Point &b) : a(a), b(b) {}\n\n    Line(const Real &A, const Real &B, const\
    \ Real &C) { // Ax+By=C\n      if(equals(A, 0)) {\n        assert(!equals(B, 0));\n\
    \        a = Point(0, C / B);\n        b = Point(1, C / B);\n      } else if(equals(B,\
    \ 0)) {\n        a = Point(C / A, 0);\n        b = Point(C / A, 1);\n      } else\
    \ {\n        a = Point(0, C / B);\n        b = Point(C / A, 0);\n      }\n   \
    \ }\n\n    friend ostream &operator<<(ostream &os, Line &l) {\n      return os\
    \ << l.a << \" to \" << l.b;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, Line &l) {\n      return is >> l.a >> l.b;\n    }\n  };\n\n  using Lines\
    \ = vector< Line >;\n}\n#line 3 \"geometry/segment.cpp\"\n\nnamespace geometry\
    \ {\n  struct Segment : Line {\n    Segment() = default;\n\n    using Line::Line;\n\
    \  };\n\n  using Segments = vector< Segment >;\n}\n#line 3 \"geometry/ccw.cpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    \  constexpr int COUNTER_CLOCKWISE = +1;\n  constexpr int CLOCKWISE = -1;\n  constexpr\
    \ int ONLINE_BACK = +2; // c-a-b\n  constexpr int ONLINE_FRONT = -2; // a-b-c\n\
    \  constexpr int ON_SEGMENT = 0; // a-c-b\n  int ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if(sign(cross(b, c)) == +1) return\
    \ COUNTER_CLOCKWISE;\n    if(sign(cross(b, c)) == -1) return CLOCKWISE;\n    if(sign(dot(b,\
    \ c)) == -1) return ONLINE_BACK;\n    if(norm(b) < norm(c)) return ONLINE_FRONT;\n\
    \    return ON_SEGMENT;\n  }\n}\n#line 4 \"geometry/is_intersect_ss.cpp\"\n\n\n\
    namespace geometry {\n  bool is_intersect_ss(const Segment &s, const Segment &t)\
    \ {\n    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&\n           ccw(t.a,\
    \ t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n  }\n}\n#line 2 \"geometry/projection.cpp\"\
    \n\n#line 5 \"geometry/projection.cpp\"\n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    \  Point projection(const Line &l, const Point &p) {\n    auto t = dot(p - l.a,\
    \ l.a - l.b) / norm(l.a - l.b);\n    return l.a + (l.a - l.b) * t;\n  }\n}\n#line\
    \ 4 \"geometry/is_intersect_sp.cpp\"\n\nnamespace geometry {\n  bool is_intersect_sp(const\
    \ Segment &s, const Point &p) {\n    return ccw(s.a, s.b, p) == ON_SEGMENT;\n\
    \  }\n}\n#line 5 \"geometry/distance_sp.cpp\"\n\nnamespace geometry {\n  Real\
    \ distance_sp(const Segment &s, const Point &p) {\n    Point r = projection(s,\
    \ p);\n    if(is_intersect_sp(s, r)) return abs(r - p);\n    return min(abs(s.a\
    \ - p), abs(s.b - p));\n  }\n}\n#line 4 \"geometry/distance_ss.cpp\"\n\nnamespace\
    \ geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\n\
    \  Real distance_ss(const Segment &a, const Segment &b) {\n    if(is_intersect_ss(a,\
    \ b)) return 0;\n    return min({distance_sp(a, b.a), distance_sp(a, b.b), distance_sp(b,\
    \ a.a), distance_sp(b, a.b)});\n  }\n}\n\n#line 7 \"test/verify/aoj-cgl-2-d.test.cpp\"\
    \n\nusing namespace geometry;\n\nint main() {\n  int T;\n  cin >> T;\n  while(T--)\
    \ {\n    Segment a, b;\n    cin >> a >> b;\n    cout << distance_ss(a, b) << \"\
    \\n\";\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\"\
    \n#define ERROR 0.00000001\n\n#include \"../../template/template.cpp\"\n\n#include\
    \ \"../../geometry/distance_ss.cpp\"\n\nusing namespace geometry;\n\nint main()\
    \ {\n  int T;\n  cin >> T;\n  while(T--) {\n    Segment a, b;\n    cin >> a >>\
    \ b;\n    cout << distance_ss(a, b) << \"\\n\";\n  }\n}\n"
  dependsOn:
  - template/template.cpp
  - geometry/distance_ss.cpp
  - geometry/segment.cpp
  - geometry/line.cpp
  - geometry/point.cpp
  - geometry/base.cpp
  - geometry/is_intersect_ss.cpp
  - geometry/ccw.cpp
  - geometry/distance_sp.cpp
  - geometry/projection.cpp
  - geometry/is_intersect_sp.cpp
  isVerificationFile: true
  path: test/verify/aoj-cgl-2-d.test.cpp
  requiredBy: []
  timestamp: '2021-05-01 00:06:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-cgl-2-d.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-cgl-2-d.test.cpp
- /verify/test/verify/aoj-cgl-2-d.test.cpp.html
title: test/verify/aoj-cgl-2-d.test.cpp
---