#include "../template.h"


// https://cp-algorithms.com/algebra/factorial-divisors.html
// Legendre's formula
// only for case k is prime
// n/k + n/(k^2) + n/(k^3) + ...
// return largest x that n! % k^x = 0
// O(logk (n))
int fact_pow(int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}