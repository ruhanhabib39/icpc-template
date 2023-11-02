/**
 * Author: Ruhan Habib
 * Date:
 * License: 
 * Source:
 * Description: Point Update Range Query Segment Tree, 0-based indexing, query [l, r)
 * Time: $O(\log n)$ per query and update, $O(n)$ to build
 * Status: Tested
 */


template<class T>
class SegTree {
   int n;
   vector<T> tree;

public:
   SegTree(int n_) : n(n_), tree(2 * n) {}

   SegTree(vector<T> vec) : n(vec.size()), tree(2 * n) {
      copy(vec.begin(), vec.end(), tree.begin() + n);

      for(int i = n - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[(i << 1) | 1];
   }

   void update(int i, T val) {
      int j = i + n;
      for(tree[j] = val; j > 1; j >>= 1) tree[j >> 1] = tree[j] + tree[j ^ 1];
   }

   T query(int l, int r) const {
      T res = {};
      for(int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
         if(i & 1) res = res + tree[i++];
         if(j & 1) res = res + tree[--j];
      }
      return res;
   }
};
