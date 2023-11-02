/**
 * Author: Sabbir Bhai
 * Date:
 * License:
 * Source:
 * Description: lazy segment tree
 * Time:
 * Status: Tested
 */
const int nmax = set_it;
ll tree[4*nmax];
ll lazy[4*nmax];
ll arr[nmax];

/// O(n)
void build(int id, int l, int r){
    lazy[id] = lazy_identity; /// lazy_identity
    if(l==r){
        initialize    ///tree[id] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    tree[id] = op(tree[2*id] , tree[2*id+1]); ///merge
    return;
}

/// O(1)
void propagate(int id, int l, int r){
    if(lazy[id] == lazy_identity) return;   /// lazy_identity
    tree[id] ?      /// update tree[id] with propagated accumulation    tree[id] += (r-l+1) * lazy[id];
    if(l!=r){
        lazy[2*id] ? /// apply lazy to child    lazy[2*id] += lazy[id];
        lazy[2*id+1] ? /// apply lazy to child    lazy[2*id+1] += lazy[id];
    }
    lazy[id] = lazy_identity;    /// lazy_identity
}

/// O(log n)
void update(int id, int l, int r, int a, int b, ll k){
    propagate(id, l, r);
    if(b<l || r<a){ ///disjoint case
        return;
    }
    if(a<=l && r<=b){
        lazy[id] ?     /// apply to lazy    lazy[id] += k;
        propagate(id, l, r);
        return;
    }

    int mid = (l+r)/2;
    update(2*id, l, mid, a, b, k);
    update(2*id+1, mid+1, r, a, b, k);
    tree[id] = op(tree[2*id] , tree[2*id+1]);    /// merge
    return;
}
/// O(log n)
ll query(int id, int l, int r, int a, int b){
    propagate(id, l, r);
    if(b<l || r<a) ///disjoint case
        return identity;   /// tree_identity
    if(a<=l && r<=b)
        return tree[id];
    int mid = (l+r)/2;
    ll p = query(id*2, l, mid, a, b);
    ll q = query(id*2+1, mid+1, r, a, b);
    return op(p,q);   /// merge
}
/// range query : sum?
/// range update : add x to range
