#include "../../template.h"
#include "Binary_exponentiation.h"

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