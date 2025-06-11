#include "../../template.h"


vector<ll> primeFactor(ll n) {
    vector<ll> factor;
    for (int i : {2, 3, 5}) {
        while (n % i == 0) {
            n /= i;
            factor.push_back(i);
        }
    }
    int inc[] = {4, 2, 4, 2, 4, 6, 2, 6};
    int j = 0;
    for (ll i = 7; i * i <= n; i += inc[j%8], j++) {
        while(n % i == 0) {
            n /= i;
            factor.push_back(i);
        }
    }
    if (n > 1) factor.push_back(n);
    return factor;
}