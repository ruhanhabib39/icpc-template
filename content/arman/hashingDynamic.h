/**
 * Author: Arman Ferdous
 * Description: Hashing with point updates on string (0-indexed). upd function adds c_add to the pos (0-indexed) th character.
 */

template<const int M, const int B> struct Dynamic_Hashing {
  int n; V<ll> h, pw;

  void upd(int pos, int c_add) {
    for (int i = ++pos; i <= n; i += i&-i)
      h[i] = (h[i] + c_add * 1LL * pw[i - pos]) % M;
  }
  int get(int pos, int r = 0) {
    for (int i = ++pos, j = 0; i; i -= i&-i) {
      r = (r + h[i] * 1LL * pw[j]) % M;
      j += i&-i;
    } return r;
  }
  Dynamic_Hashing(const string &s) : n(sz(s)), h(n+1), pw(n+1) {
    pw[0] = 1; // ^^ s is 0 indexed
    for (int i = 1; i <= n; ++i) pw[i] = (pw[i-1] * 1LL * B) % M;
    for (int i = 0; i < n; ++i) upd(i, s[i]);
  }
  ll eval(int l, int r) { assert(l <= r);
    return (get(r) - ((get(l-1) * 1LL * pw[r-l+1]) % M) + M) % M;
  }
};

struct Double_Dynamic {
  using DH1 = Dynamic_Hashing<916969619, 571>;
  using DH2 = Dynamic_Hashing<285646799, 953>;
  DH1 h1; DH2 h2;
  Double_Dynamic(const string &s) : h1(s), h2(s) {}
  void upd(int pos, int c_add) {
    h1.upd(pos, c_add);
    h2.upd(pos, c_add);
  }
  pll eval(int l, int r) { return {h1.eval(l,r), h2.eval(l,r)}; }
};

/*
 * upd(pos, c_add):
 * adds c_add to the pos-th character.          *
 * if you want to change s[i] into a new character ch
 * you need to call upd(i, ch - s[i])

 * get(pos):
 * returns the hash value of the prefix upto pos
 *
 * Code can be used with/without Double_Dynamic
 */