/**
 * Author: Arman Ferdous
 * Date:
 * License: 
 * Source: Self work
 * Description: Given weighted graph \texttt{g} with nodes $\in [1,n]$, makes a new binary tree \texttt{T} with nodes $\in [0,$\texttt{nnode}$)$ such that distance is maintained. Adds at-most $2(N-1)$ nodes (actually much less than that). Only call \texttt{build(n)}, and $g$ must have $(w,v)$ pairs.
 * Time: 
 * Status: Tested
 */


struct BinaryTree {
  int nnode; vector<vii> T;
  void build(int n) {
    nnode = n + 1; int req = n;
    g[1].pb({0, 0}); g[0].pb({0, 1});
    for (int i = 1; i <= n; ++i)
      req += max(sz(g[i]) - 3, 0);
    T.resize(req + 1, vii());
    dfs(0, -1); binarize(0, -1, 0);
  }
  void dfs(int u, int f) {
    for (auto &e : g[u])
      e.se == f ? swap(e, g[u][0]) : dfs(e.se,u);
  }
  void binarize(int u, int f, int prev_w) {
    if (sz(g[u]) <= 3) {
      if (f != -1) T[u].pb({prev_w, f});
      for (auto [w, v] : g[u]) 
        if (f == -1 || v != g[u][0].se)
          T[u].pb({w, v}), binarize(v, u, w);
      return;
    }  T[u].pb({prev_w, f}); T[u].pb(g[u][1]);   
    binarize(g[u][1].se, u, g[u][1].fi);
    int last = u;
    for (int i = 2; i + 1 < sz(g[u]); ++i) {
      T[last].pb({0, nnode}); T[nnode].pb({0, last});
      last = nnode++; T[last].pb(g[u][i]);
      binarize(g[u][i].se, last, g[u][i].fi);
    }
    T[last].pb(g[u].back());
    binarize(g[u].back().se, last, g[u].back().fi);
  }
}BT;
