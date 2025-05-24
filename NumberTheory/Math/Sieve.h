#include "../../template.h"

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

vector<int> segmentSieve(int l, int r){
	vector<int> prime(r-l+1, 1);
	for(ll p = 2; p*p <= r; p++){
		ll lim = max(p*p, (l+p-1)/p*p);
		for(ll j = lim; j <= r; j += p)
			if (j-l >= 0) prime[j-l] = 0;
	}
	if (l == 0) prime[0] = 0;
	if (l == 0 && r > l) prime[1] = 0;
	if (l == 1) prime[1-l] = 0;
	return prime;
}

vector<int> listPrime(int l, int r) {
	vector<int> prime = segmentSieve(l, r);
	vector<int> listPi;
	for (int i = l; i <= r; i++) {
		if (prime[i-l]) listPi.push_back(i);
	}
	return listPi;
}