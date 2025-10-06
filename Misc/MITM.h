#include "../template.h"



vector<ll> L, R;
 
void MITM(int i, ll sum, int end) {
    if (i >= end) R.push_back(sum);
    else {
        MITM(i+1, sum, end);
        MITM(i+1, sum + a[i], end);
    }
}

// MITM(0, 0, n/2);
// L = R;
// R.clear();
// MITM(n/2, 0, n);