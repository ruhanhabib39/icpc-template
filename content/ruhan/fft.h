/**
 * Author: CPAlgo, with edits by Arman
 * Date:
 * License: 
 * Source: https://cp-algorithms.com/algebra/fft.html#improved-implementation-in-place-computation
 * Description: FFT
 * Time: $O(n \log n)$
 * Status:
 */


once_flag onceFlag;
vector<cd> w;

// fft does not recalculate w even if n changes
// so if n changes, handle that 
void fft(vector<cd> & a, bool invert) {
  int n = a.size();
 
  call_once(onceFlag, [&]() {
    w.resize(n);
    w[0] = cd(1);
    for (int i = 1; i < n; ++i)
      w[i] = cd(cos((2*PI*i)/n), sin((2*PI*i)/n));
  });
 
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;
 
    if (i < j)
      swap(a[i], a[j]);
  }
 
  for (int len = 2; len <= n; len <<= 1) {
    int jump = n / len * (invert ? -1 : 1), idx = 0;
 
    for (int i = 0; i < n; i += len) {
      idx = 0;
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i+j], v = a[i+j+len/2] * w[idx];
        a[i+j] = u + v;
        a[i+j+len/2] = u - v;
 
        idx += jump;
        if (idx >= n) idx -= n;
        else if (idx < 0) idx += n;
      }
    }
  }
 
  if (invert) {
    for (cd & x : a)
      x /= n;
  }
}
 
vector<cd> multiply(vector<cd> const& a, vector<cd> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < sz(a) + sz(b)) 
    n <<= 1;
  fa.resize(n);
  fb.resize(n);
 
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++)
    fa[i] *= fb[i];
  fft(fa, true);
 
  for (auto &c : fa)
    if (fabs(c.imag()) <= eps)
      c.imag(0);
  return fa;
}
