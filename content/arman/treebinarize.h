/**
 * Author: Arman Ferdous
 * Date:
 * License: 
 * Source: Self work
 * Description: Given weighted graph \texttt{g} with nodes $\in [1,n]$, makes a new binary tree \texttt{T} with nodes $\in [1,$\texttt{nnode}$)$ such that distance is maintained. Adds at-most $2(N-1)$ nodes (actually much less than that).$g$ must have $(w,v)$ pairs.
 * Time: 
 * Status: Tested
 */


struct BinaryTree {
  int nnode;
  V<V<pii>> T;
  void dfs(int u, int f) {
    for (auto &e : T[u])
      e.second == f ? swap(e, T[u][0]) : dfs(e.second, u);
  }
  BinaryTree(V<V<pii>> &g, int I = 1) : T(g) {
    dfs(I, -1); int n = sz(T);
    for (int u = I; u < n; ++u) {
      for (int i = 2 - (u == I), x = u; i+1 < sz(T[u]); ++i) {
        T.push_back({{0, x}, T[u][i], T[u][i+1]});
        int v1 = T[u][i].second, v2 = T[u][i+1].second;
        T[v1][0] = T[v2][0] = {1, sz(T) - 1};
        T[x][2 - (x == I)] = {0, sz(T) - 1};
        x = sz(T) - 1;
      }
      if (sz(T[u]) > 3 - (u == I))
        T[u].resize(3 - (u == I));
    }
    nnode = sz(T) - 1;
  }
};
