/**
 * Author: Codex
 * Date: 2024-05-27
 * License: CC0
 * Description: Linear sieve. Fills $lpf[i]$, the least prime factor of $i$, for
 * $2 \le i <$ MAX\_SIZE ($lpf[0] = 0$, $lpf[1] = 1$), and lists the primes in primes.
 * Factor $x$ by repeatedly dividing by $lpf[x]$ while $x > 1$.
 * Time: O(\text{MAX\_SIZE})
 * Status: tested against trial division up to $10^6$
 */
#pragma once

const int MAX_SIZE = 1'000'001;
int lpf[MAX_SIZE];
vi primes;

void buildLPF() {
	fill(lpf, lpf + MAX_SIZE, 0), primes.clear();
	lpf[1] = 1;
	rep(i,2,MAX_SIZE) {
		if (!lpf[i]) lpf[i] = i, primes.push_back(i);
		for (int p : primes) {
			if (p > lpf[i] || (ll)i * p >= MAX_SIZE) break;
			lpf[i * p] = p;
		}
	}
}
