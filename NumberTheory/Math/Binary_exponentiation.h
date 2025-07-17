#include "../../template.h"

using u128 = __uint128_t;
using i128 = __int128;

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
        if (b & 1) res = (i128)res * a % M;
        a = (i128)a * a % M;
        b /= 2;
    }
    return res;
}