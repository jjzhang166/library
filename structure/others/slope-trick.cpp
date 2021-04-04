/**
 * @brief Slope-Trick
 * @see https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
 */
template< typename T >
struct SlopeTrick {

  const T INF = numeric_limits< T >::max() / 3;

  T min_f;
  priority_queue< T, vector< T >, less<> > L;
  priority_queue< T, vector< T >, greater<> > R;
  T add_l, add_r;


private:
  void push_R(const T &a) {
    R.push(a - add_r);
  }

  T top_R() const {
    return R.top() + add_r;
  }

  T pop_R() {
    T val = top_R();
    R.pop();
    return val;
  }

  void push_L(const T &a) {
    L.push(a - add_l);
  }

  T top_L() const {
    return L.top() + add_l;
  }

  T pop_L() {
    T val = top_L();
    L.pop();
    return val;
  }

public:
  SlopeTrick() : min_f(0), add_l(0), add_r(0) {
    L.push(-INF);
    R.push(INF);
  }

  struct Query {
    T lx, rx, min_f;
  };

  // return min f(x)
  Query query() const {
    return (Query) {top_L(), top_R(), min_f};
  }

  // f(x) += a
  void add_all(const T &a) {
    min_f += a;
  }

  // add \_
  // f(x) += max(a - x, 0)
  void add_a_minus_x(const T &a) {
    min_f += max(T(0), a - top_R());
    push_R(a);
    push_L(pop_R());
  }

  // add _/
  // f(x) += max(x - a, 0)
  void add_x_minus_a(const T &a) {
    min_f += max(T(0), top_L() - a);
    push_L(a);
    push_R(pop_L());
  }

  // add \/
  // f(x) += abs(x - a)
  void add_abs(const T &a) {
    add_a_minus_x(a);
    add_x_minus_a(a);
  }

  // \/ -> \_
  // f_{new} (x) = min f(y) (y <= x)
  void clear_right() {
    while(R.size() >= 2) R.pop();
  }

  // \/ -> _/
  // f_{new} (x) = min f(y) (y >= x)
  void clear_left() {
    while(L.size() >= 2) L.pop();
  }

  // \/. -> .\/
  // f_{new} (x) = f(x - a)
  void shift(const T &a) {
    add_l += a;
    add_r += a;
  }

  // L, R を破壊する
  T get(const T &x) {
    T ret = min_f;
    while(!L.empty()) {
      ret += max(T(0), pop_L() - x);
    }
    while(!R.empty()) {
      ret += max(T(0), x - pop_R());
    }
    return ret;
  }
};
