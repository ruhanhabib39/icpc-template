/**
 * Author: Arman Ferdous
 * Date:
 * License: 
 * Source: Internet
 * Description: Call \texttt{build()} with weighted tree \texttt{g}. And \texttt{g} has pairs \texttt{(w, v)}, nodes $\in [0/1,n]$. \textbf{Requires \texttt{SparseTable}}. 
 * Time: build() in $\mathcal{O}(n \lg n)$, lca() in $\mathcal{O}(1)$.
 * Status: Tested
 */

inline ii op(ii a, ii b) {return a.fi<b.fi ? a : b;}
struct FastLCA {
  vii L; vi pos, dis; SparseTable<ii, op> rmq;
  void build(int root = 1) { L.clear();
    pos.assign(sz(g),0); dis.assign(sz(g),0); 
    dfs(root, -1, 0); rmq = SparseTable<ii, op>(L);
  }
  void dfs(int u, int f, int lev) {
    pos[u] = sz(L); L.pb({lev, u});
    for (auto [w, v] : g[u]) if (v ^ f) {
      dis[v] = dis[u] + w;
      dfs(v, u, lev + 1);
      L.pb({lev, u});
  } }
  inline int lca(int u, int v) {
    if (pos[u] > pos[v]) swap(u, v);
    return u == v ? u : rmq.query(pos[u], pos[v]).se;
  }
  inline int dist(int u, int v)
    { return dis[u] + dis[v] - 2*dis[lca(u, v)]; }
}fast;
