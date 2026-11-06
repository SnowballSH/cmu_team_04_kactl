#include "../utilities/template.h"
#include "../../content/combinatorial/Combo.h"

int main() {
	init();
	const int N = min(MAXN, 100);
	vector<vi> pascal(N + 1, vi(N + 1));
	rep(n, 0, N + 1) {
		pascal[n][0] = pascal[n][n] = 1;
		rep(r, 1, n) pascal[n][r] = (pascal[n-1][r-1] + pascal[n-1][r]) % mod;
		rep(r, 0, n + 1) assert(choose(n, r).x == pascal[n][r]);
		assert(choose(n, -1).x == 0 && choose(n, n+1).x == 0);
	}
	cout << "Tests passed!" << endl;
}
