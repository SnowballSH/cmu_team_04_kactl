#include "../utilities/template.h"

#include "../../content/number-theory/ModSum.h"

ll rmod(ll x, ll m) {
	x %= m;
	return x < 0 ? x + m : x;
}

ll rdiv(ll x, ll y) {
	x -= rmod(x, y);
	return x / y;
}

ll modsum_naive(ll to, ll c, ll k, ll m) {
	ll res = 0;
	for (int i = 0; i < (int)to; ++i)
		res += rmod(c + k * i, m);
	return res;
}

ll divsum_naive(ll to, ll c, ll k, ll m) {
	ll res = 0;
	for (int i = 0; i < (int)to; ++i)
		res += rdiv(c + k * i, m);
	return res;
}

void compare() {
	rep(to,0,30) {
		rep(c,-30,30) {
			rep(k,-30,30) {
				rep(m,1,30) {
					ll a = modsum(to, c, k, m);
					ll b = modsum_naive(to, c, k, m);
					if (a != b) {
						cout << "differ! " << to << ' ' << c << ' ' << k << ' ' << m << ": " << a << " vs " << b << endl;
						assert(false);
					}
				}
			}
		}
	}
}

void compare2() {
	rep(to,0,30) {
		rep(c,0,30) {
			rep(k,0,30) {
				rep(m,1,30) {
					ll a = divsum(to, c, k, m);
					ll b = divsum_naive(to, c, k, m);
					if (a != b) {
						cout << "differ! " << to << ' ' << c << ' ' << k << ' ' << m << ": " << a << " vs " << b << endl;
						assert(false);
					}
				}
			}
		}
	}
}

int main() {
	compare(); compare2();
	assert(modsum((ll)1e18, 1, 2, 3) == (ll)1e18);
	rep(i,0,50) {
		ll t = (ll)rand() << 3;
		ll c = (ll)rand() << 2;
		ll k = (ll)rand() << 2;
		ll m = (ll)rand() >> 2;
		// Exact independent floor-sum oracle; libc rand sequences differ.
		__uint128_t n = t, a = k, b = c, mod = m, floors = 0;
		while (true) {
			floors += n * (n - 1) / 2 * (a / mod) + n * (b / mod);
			a %= mod; b %= mod;
			__uint128_t y = a * n + b;
			if (y < mod) break;
			n = y / mod; b = y % mod;
			swap(mod, a);
		}
		__uint128_t expected = (__uint128_t)t * c
			+ (__uint128_t)k * t * (t - 1) / 2 - floors * m;
		assert((__uint128_t)modsum(t, c, k, m) == expected);
	}
	cout<<"Tests passed!"<<endl;
	return 0;
}
