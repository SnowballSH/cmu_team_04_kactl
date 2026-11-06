/**
 * Author: USACO Guide
 * Description: Computes $\binom{n}{r}$ modulo mod. Also computes $n!$ and its inverse under mod.
 * Requires a prime mod; supports $0 \le n \le \min(10^6, mod-1)$.
 * Time: O(MAXN) precomputation, O(1) per query
 */
#pragma once

#include "../number-theory/ModularArithmetic.h"

const int MAXN = (int)min(1'000'000LL, mod - 1);
vector<Mod> fac(MAXN + 1, Mod(0)), inv(MAXN + 1, Mod(0));
void init() {
  fac[0] = Mod(1);
  for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i;
  inv[MAXN] = fac[MAXN] ^ (mod - 2);
  for (int i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i;
}
Mod choose(int n, int r) {
    if (r < 0 || r > n) return Mod(0);
    assert(n <= MAXN);
    return fac[n] * inv[r] * inv[n - r];
}