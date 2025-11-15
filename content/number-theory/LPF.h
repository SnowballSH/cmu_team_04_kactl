/**
 * Author: Codex
 * Date: 2024-05-27
 * License: CC0
 * Description: Least prime factor sieve filling $lpf[i]$ for $0 \le i < \text{MAX\_SIZE}$.
 * Time: $O(\text{MAX\_SIZE})$
 */
#pragma once

const int MAX_SIZE = 1'000'001;
int lpf[MAX_SIZE];

void buildLPF() {
	memset(lpf, 0, sizeof(lpf));
	lpf[1] = 1;
	rep(i, 2, MAX_SIZE) if (!lpf[i])
		for (int j = i; j < MAX_SIZE; j += i)
			if (!lpf[j]) lpf[j] = i;
}
