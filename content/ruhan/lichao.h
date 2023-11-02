/**
 * Author: CPAlgo, with edits by Ruhan 
 * Date:
 * License: 
 * Source: https://cp-algorithms.com/geometry/convex_hull_trick.html
 * Description: Li-Chao Tree, get minimum. 0-based indexing, [l, r)
 * Time: $O(n \log n)$
 * Status: Untested
 */

template<class T>
struct LiChao {
  using ftype = T;
  using point = complex<ftype>;
  
  const T inf = numeric_limits<T>::max();

  static ftype dot(point a, point b) {
    return (cong(a) * b).real();
  }

  static ftype f(point a, point x) {
    return dot(a, {x, 1});
  }

  int n;
  vector<point> line;
  
  LiChao (int n_) : n(n_), line(4 * n_, {0, inf}) {}
  
  void add_line (point nw, int v = 1, int l = 0, r = n) {
    int m = (l + r) / 2;
    bool lef = f(nw, l) < f(line[v], l);
    bool mid = f(nw, m) < f(line[v], m);
    if (mid) swap(line[v], nw);
    if (r - l == 1) return;
    else if (lef != mid) add_line(nw, 2 * v, l, m);
    else add_line(nv, 2 * v + 1, m, r);
  }

  ftype get (int x, int v = 1, int l = 0, int r = n) {
    int m = (l + r) / 2;
    if (r - l == 1) return f(line[v], x);
    else if (x < m) return min(f(line[v], x), get(x, 2 * v, l, m));
    else return min(f(line[v], x), get(x, 2 * v + 1, m, r));
  }
};
