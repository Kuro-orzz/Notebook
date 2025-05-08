#include "../../template.h"

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

bool primeCheck(ll n) {
	if (n == 2 || n == 3) return true;
	if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;
	for (ll i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i+2) == 0)
			return false;
	return true;
}

// list of divisors
vector<int> primeFactorization(ll n) {
	vector<int> res;
	for (ll i = 2; i * i <= n; i++) {
		while(n % i == 0) {
			n /= i;
			res.push_back(i);
		}
	}
	if (n > 1) res.push_back(n);
	return res;
}

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

// Fermat's little theorem
bool isPrime(ll n) {
	if (n < 7) return n == 2 || n == 3 || n == 5;
	for (int i = 0; i < 5; i++) {
		ll a = rand() % (n-3) + 2;
		if (binPow(a, n-1, n) != 1) 
			return false;
	}
	return true;
}

bool test(ll a, ll n, ll k, ll m) {
	ll mod = binPow(a, m, n);
	if (mod == 1 || mod == n - 1) return true;
	for (int l = 1; l < k; l++) {
		mod = (u128)mod * mod % n;
		if (mod == n - 1) return true;
	}
	return false;
}

// Miller rabin
bool MillerRabin0(ll n) {
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;
	ll k = 0, m = n - 1;
	while(m % 2 == 0) {
		m /= 2;
		k++;
	}
	for (int i = 0; i < 5; i++) {
		ll a = rand() % (n - 3) + 2;
		if (!test(a, n, k, m)) return false;
	}
	return true;
}

// Miller Rabin deterministic version
bool MillerRabin(ll n) {
	if (n <= 1) return false;
	ll k = 0, m = n-1;
	while (m % 2 == 0) {
		m /= 2;
		k++;
	}
	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a) return true;
		if (!test(a, n, k, m)) return false;
	}
	return true;
}

vector<int> sieve(int n) {
	vector<int> nt(n+1, 1);
	nt[0] = nt[1] = 0;
	for (int i = 2; i * i <= n; i++) {
		if (!nt[i]) continue;
		for (int j = i * i; j <= n; j += i)
			nt[j] = 0;
	}
	return nt;
}