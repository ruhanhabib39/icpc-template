/**
 * Author: Arman Ferdous
 * Date:
 * License: 
 * Source: Self work, Folklore
 * Description: Builds the Centroid Tree of the tree \texttt{adj}. For each centroid \texttt{c}, calculates its parent \texttt{C[c].p}, all outgoing children in \texttt{C[c].out} and the (index of \texttt{C[parent of c].out} which points to \texttt{c} itself) in \texttt{C[c].p\_idx}. Just call \texttt{build()}. Parent of \texttt{ROOT} = -1.
 * Time: \texttt{build()} in $\mathcal{O}(n \lg n)$.
 * Status: Tested
 */

struct centroidDecomp {
  struct centroid {
    int p, p_idx; vi out;
    centroid() { p = p_idx = -1; };
  }; 
  int ROOT; vector<centroid> C;
  vector<bool> done; vi siz;
  void build() {
    C.resize(sz(adj)); done.resize(sz(adj), false); 
    siz.resize(sz(adj)); ROOT = build_tree(1, -1);
  }
  int dfs(int u, int f) { 
    siz[u] = 1;
    for (int v : adj[u]) if (v != f && !done[v])
        siz[u] += dfs(v, u); 
    return siz[u];
  }
  int find_centroid(int u, int f, int lim) {
    for (int v : adj[u]) 
      if (v != f && !done[v] && 2*siz[v] > lim)
        return find_centroid(v, u, lim);
    return u;
  }
  int build_tree(int u, int f, int lev = 0) {
    dfs(u, f); if (siz[u] == 1) return u;
    int c = find_centroid(u, f, siz[u]);
    done[c] = true;
    for (int v : adj[c]) if (!done[v]) {
      int next_c = build_tree(v, c);
      // next_c is the next centroid after c.
      C[next_c].p = c;
      C[next_c].p_idx = sz(C[c].out);
      C[c].out.pb(next_c);
    } return c;
} }cd;
