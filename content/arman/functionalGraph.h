/**
 * Author: Arman Ferdous
 * Date:
 * License:
 * Source: self work
 * Description: Functional graph essentials. $f: [0, n) \rightarrow [0, n)$. lev: distance from entering cycle, 0 if on cycle. pos: gives an ordering of nodes on same cycle. clen: no. of nodes on the cycle containing u, -1 if not on one. dsu: merges all edges as bidirectional. sub: merges all but cycle edges, parents are on cycle.
 * Time: Linear
 * Status: Tested
 */

struct DSU {
  vi e;
  DSU (int n) : e(n, -1) {}
  int size (int x) { return -e[find(x)]; }
  int find (int x) {
    if (e[x] < 0) return x;
    return e[x] = find(e[x]);
  }
  bool join (int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

struct fGraph {
  int n;
  V<int> f, lev, pos, clen;
  DSU dsu, sub;

  fGraph (const V<int> &ff) : n(sz(ff)), f(ff),
  lev(n, 0), dsu(n), sub(n) {
    for (int i = 0; i < n; ++i) lev[f[i]]++;
    queue<int> q; stack<int> rev;
    for (int i = 0; i < n; ++i)
      if (!lev[i]) q.push(i);
    while (!q.empty()) {// from leaves to cycle
      int u = q.front(); q.pop();
      rev.push(u);
      if (!--lev[f[u]]) q.push(f[u]);
    }
    for (int i = 0; i < n; ++i) {
      dsu.join(f[i], i);
      if (!lev[i]) sub.join(f[i], i);
      lev[i] = (lev[i] == 0 ? -1 : 0);
    }
    while (!rev.empty()) {
      int u = rev.top(); rev.pop(); // top to leaves
      lev[u] = lev[f[u]] + 1;
    }
    pos.assign(n, -1);
    clen.assign(n, -1);
    for (int i = 0; i < m; ++i)
      if (pos[i] == -1 && !lev[i]) {
        int len = 0; // iterates on cycle
        for (int u = i; pos[u] == -1; u = f[u])
          pos[u] = len++;
        for (int u = i; clen[u] == -1; u = f[u])
          clen[u] = len;
      }
  }
  bool connected (int u, int v)
    { return dsu.find(u) == dsu.find(v); }
  bool sameTree (int u, int v)
    { return sub.find(u) == sub.find(v); }
};
