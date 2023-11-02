/**
 * Author:
 * Date:
 * License:
 * Source: KACTL :3
 * Description: 0-Indexed, Query type $[l, r)$. Handles range query on static arrays. 
 * Usage: SparseTable<int, op> table;
 * Time: $\mathcal{O}(n\lg n)$ to construct. \texttt{query} is $\mathcal{O}(1)$ if function is idempotent ($f \circ f = f$). Otherwise, use \texttt{lgQuery}, which is $\mathcal{O}(\lg n)$. 
 * Status:
 */
template<typename T, T (*op)(T, T)>
struct SparseTable {
  vector<vector<T>> t;
  SparseTable(const vector<T> &v) : t(1, v) {
    for (int j = 1; j <= __lg(sz(v)); ++j) {
      t.emplace_back(sz(v) - (1 << j) + 1);
      for (int i = 0; i < sz(t[j]); ++i) 
        t[j][i] = op(t[j - 1][i], 
          t[j - 1][i + (1 << (j - 1))]);
  } }
  T query(int l, int r) { assert(l < r);
    int k = __lg(r - l);
    return op(t[k][l], t[k][r - (1 << k)]);
  }
  T lgQuery(int l, int r) { assert(l < r);
    T ret = t[0][l++]; if (l == r) return ret;
    for (int j = __lg(r - l); j >= 0; --j) {
      if (l + (1 << j) - 1 < r) {
        ret = op(ret, t[j][l]);
        l += (1 << j);
    } } return ret;
  }
}; int op(int a, int b) { return min(a, b); }
