/**
 * Author: Arman Ferdous
 * Date:
 * License:
 * Source:
 * Description: 
 * Usage: Call hashing on a 0-indexed string. eval intervals are $[l, r]$. Shouldn't overflow with given mods.
 * Time: 
 * Status: Tested
 */

template<const int M, const int B> struct Hashing {
  int n; V<int> h, pw;
  Hashing(const string &s) : n(sz(s)), h(n+1), pw(n+1) {
    pw[0] = 1; // ^^ s is 0 indexed
    for (int i = 1; i <= n; ++i)
      pw[i] = (pw[i-1] * 1LL * B) % M,
      h[i] = (h[i-1] * 1LL * B + s[i-1]) % M;
  }
  int eval(int l, int r) { assert(l <= r); // [l, r]
    return (h[r+1] - ((h[l] * 1LL * pw[r-l+1]) % M) + M) % M;
  }
};

struct Double_Hash {
  using H1 = Hashing<916969619, 101>;
  using H2 = Hashing<285646799, 103>;
  H1 h1; H2 h2;
  Double_Hash(const string &s) : h1(s), h2(s) {}
  pii eval(int l, int r) { return {h1.eval(l,r), h2.eval(l,r)}; }
};
