/**
 * Author: Ruhan Habib 
 * Date:
 * License:
 * Source:
 * Description: Maths stuff. Modular operations assume that (mod - 1) * (mod - 1) fits in long long
 * Time: 
 * Status: untested
 */


// computes n! and the modular inverse of n! for n = 1, ..., nmax
// O(n)
long long fact[nmax + 10], fact_inv[nmax + 10];
void precal () {
   fact_inv[0] = fact[0] = 1;
   fact_inv[1] = fact[1] = 1;
   for (long long n = 2; n <= nmax; n++) {
      fact[n] = n * fact[n-1] % mod;
      fact_inv[n] = mod - (mod / n) * fact_inv[mod % i] % mod;
      fact_inv[n] %= mod;
   }
}

