#include "../../template.h"

using u128 = __uint128_t;

ll binMul(ll a, ll b, ll M) {
	a = a % M;
	ll res = 0;
	while (b) {
		if (b & 1) res = (res + a) % M;
		a = a * 2 % M;
		b /= 2;
	}
	return res;
}

ll binPow(ll a, ll b, ll M) {
	a %= M;
	ll res = 1;
	while (b) {
		if (b & 1) res = (u128)res * a % M;
		a = (u128)a * a % M;
		b /= 2;
	}
	return res;
}