/**
 * Author: Arman Ferdous (inspiration: tourist, atcoder library)
 * Date:
 * License: 
 * Source:
 * Description:
 * Time:
 * Status: Tested
 */
 
template<class S> struct segtree {
	int n; vector<S> t;
	void init(int _) { n = _; t.assign(n+n-1, S()); }
	void init(const vector<S>& v) { 
		n = sz(v); t.assign(n + n - 1, S()); 
		build(0,0,n-1,v); 
	} template <typename... T>
	void upd(int l, int r, const T&... v) {
	  assert(0 <= l && l <= r && r < n);
	  upd(0, 0, n-1, l, r, v...);
	}
	S get(int l, int r) {
    assert(0 <= l && l <= r && r < n);
    return get(0, 0, n-1, l, r);
  }
private:
	inline void push(int u, int b, int e) {
		if (t[u].lazy == 0) return;
		int mid = (b+e)>>1, rc = u+((mid-b+1)<<1);
		t[u+1].upd(b, mid, t[u].lazy);
		t[rc].upd(mid+1, e, t[u].lazy);
		t[u].lazy = 0;
	}
	void build(int u, int b, int e, const vector<S>& v) {
		if (b == e) return void(t[u] = v[b]);
		int mid = (b+e)>>1, rc = u+((mid-b+1)<<1);
		build(u+1, b, mid, v); build(rc, mid+1, e, v);
		t[u] = t[u+1] + t[rc];
	} template<typename... T>
	void upd(int u, int b, int e, int l, int r, const T&... v) {
		if (l <= b && e <= r) return t[u].upd(b, e, v...);
		push(u, b, e);
		int mid = (b+e)>>1, rc = u+((mid-b+1)<<1);
		if (l <= mid) upd(u+1, b, mid, l, r, v...);
		if (mid < r) upd(rc, mid+1, e, l, r, v...);
		t[u] = t[u+1] + t[rc];
	}
	S get(int u, int b, int e, int l, int r) {
		if (l <= b && e <= r) return t[u];
		push(u, b, e); 
		S res; int mid = (b+e)>>1, rc = u+((mid-b+1)<<1);
		if (r <= mid) res = get(u+1, b, mid, l, r);
		else if (mid < l) res = get(rc, mid+1, e, l, r);
		else res = get(u+1, b, mid, l, r) + get(rc, mid+1, e, l, r);
		t[u] = t[u+1] + t[rc]; return res;
	}
};


/* Segment Tree
===============
Inspiration: tourist, atcoder library

(1) Declaration:
	Create a node class (sample below).
	node class must have the following:

	* A constructor (to create empty nodes and also to make inplace nodes).
	* + operator: returns a node which contains the merged information of two nodes.
	* upd(b, e, ...): updates this node representing the range [b, e] using information from ...

	Now, segtree<node> T; declares the tree.
	You can use T.init(100) to create an empty tree of 100 nodes in [0, 100) range.
	You can also make a vector<node> v; Then put values in the vector v and make the tree using
	 v by, T.init(v); This works in linear time and is faster than updating each individually.
	
(2) Usage:
	(2.1) init(int siz) or init(vector):
		Described above

	(2.2) upd(l, r, ...v):
		Update the range [l, r] with the information in ...
		Make sure the number of elements and the order of them you put here is the exact same
		as you declared in your node.upd() function.
*/


struct node {
	ll sum;
	ll lazy;

	node(ll _a = 0, ll _b = 0) : sum(_a), lazy(_b) {}

	node operator+(const node &obj) {
		return {sum + obj.sum, 0};
	}

	void upd(int b, int e, ll x) {
		sum += (e - b + 1) * x;
		lazy += x;
	}
};

