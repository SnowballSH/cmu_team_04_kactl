/**
 * Author: USACO Guide
 * Description: Computes $\binom{n}{r}$ modulo mod. Also computes $n!$ and its inverse under mod.
 * Time: O(MAXN) precomputation, O(1) per query
 */
#pragma once

const int MAXN = 1e6;
Mod fac[MAXN + 1], inv[MAXN + 1];
void init() {
  fac[0] = Mod(1);
  for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i;
  inv[MAXN] = fac[MAXN] ^ (mod - 2);
  for (int i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i;
}
Mod choose(int n, int r) {
    if (r < 0 || r > n) return Mod(0);
    return fac[n] * inv[r] * inv[n - r];
}