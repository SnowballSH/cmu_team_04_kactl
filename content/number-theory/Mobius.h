/**
 * Author: Codex
 * Date: 2024-05-27
 * License: CC0
 * Description: Mobius function sieve for $0 \le n <$ MAX\_SIZE (calls buildLPF).
 * $\mu(n)=0$ if $n$ is not square-free, otherwise $(-1)^k$ where $k$ is the
 * number of prime factors of $n$. $\mu(0)$ is set to $0$.
 * Time: O(\text{MAX\_SIZE})
 * Status: tested against trial division up to $10^6$
 */
#pragma once

#include "LPF.h"

int mobius[MAX_SIZE];

void buildMobius() {
	buildLPF();
	mobius[0] = 0, mobius[1] = 1;
	rep(i,2,MAX_SIZE) {
		int p = lpf[i], x = i / p;
		mobius[i] = x % p ? -mobius[x] : 0;
	}
}
