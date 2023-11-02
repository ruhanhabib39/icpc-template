/**
 * Author: Ruhan Habib
 * Date:
 * License: 
 * Source:
 * Description: Sparse DSU using map.
 *              T must be comparable.
 * Time: Amorized $O(comp_T \log n)$ operations, where $O(comp_T)$ is the comparison
 *       time complexity for T. Ignoring the inverse-ackermann factor.
 * Status: Tested
 */

template<class T>
class SparseDSU {
   map<T,T> par;
   map<T,int> cc;
public:
   SparseDSU() {}

   T find(T u) {
      auto it = par.find(u);
      if(it == par.end()) return u;

      return it->second = find(it->second);
   }

   void merge(T u, T v) {
      u = find(u);
      v = find(v);

      if(u == v) return;

      auto it = cc.find(u);
      auto jt = cc.find(v);

      if(it == cc.end() && jt == cc.end()) {
         par[v] = u;
         cc[u] = 2;
      } else if(it == cc.end()) {
         par[u] = v;
         jt->second++;
      } else if(jt == cc.end()) {
         par[v] = u;
         it->second++;
      } else if(it->second < jt->second) {
         par[u] = v;
         jt->second += it->second;

         // the following line is not strictly necessary
         // it's only to conserve memory
         cc.erase(it);
      } else {
         par[v] = u;
         it->second += jt->second;

         // the following line is not strictly necessary
         // it's only to conserve memory
         cc.erase(jt);
      }
   }
};
