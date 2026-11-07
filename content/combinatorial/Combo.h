/**
 * Author: USACO Guide
 * Description: Factorials, inverse factorials and $\binom{n}{r}$ modulo a prime
 * mod, for $0 \le n \le$ MAXN $= \min(10^6, mod-1)$. Set mod to the prime
 * first, and call init() once before use.
 * Usage: init(); choose(5, 2).x; // 10
 * Time: O(MAXN) precomputation, O(1) per query
 * Status: stress-tested
 */
#pragma once

#include "../number-theory/ModularArithmetic.h"

const int MAXN = (int)min(1'000'000LL, mod - 1);
vector<Mod> fac(MAXN + 1, 1), ifac(MAXN + 1, 1);
void init() {
	rep(i,1,MAXN+1) fac[i] = fac[i-1] * i;
	ifac[MAXN] = fac[MAXN] ^ (mod - 2);
	for (int i = MAXN; i; i--) ifac[i-1] = ifac[i] * i;
}
Mod choose(int n, int r) {
	if (r < 0 || r > n) return 0;
	assert(n <= MAXN);
	return fac[n] * ifac[r] * ifac[n-r];
}
