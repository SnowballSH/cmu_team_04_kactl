/**
 * Author: Codex
 * Date: 2024-05-27
 * License: CC0
 * Description: Mobius function sieve using least prime factors. $\mu(n)=0$ if $n$ is not square-free, otherwise $(-1)^{\Omega(n)}$.
 * Time: $O(\text{MAX\_SIZE})$
 */
#pragma once

#include "LPF.h"

int mobius[MAX_SIZE];

void buildMobius() {
	mobius[0] = 0, mobius[1] = 1;
	rep(i, 2, MAX_SIZE) {
		int p = lpf[i], x = i / p;
		mobius[i] = (x % p) ? -mobius[x] : 0;
	}
}
