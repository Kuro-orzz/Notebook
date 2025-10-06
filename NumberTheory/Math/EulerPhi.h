#include "../../template.h"

ll eulerPhi(ll n) {
    if (n == 0) return 0;
    ll ans = n;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            ans -= ans / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

vector<int> phi_from_1_to_n(int n) {
    vector<int> phi(n + 1);
    iota(all(phi), 0);
    
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
}

// phi(a * b) = phi(a) * phi(b) / phi(gcd(a, b)) * gcd(a, b)
// int gcd = __gcd(a, b);
// int phi[a*b] = (1ull * phi[a] * phi[b] / phi[gcd] * gcd) % mod;