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

void segmentSieve(int l, int r){
    bool prime[r-l+1];
    memset(prime, true, sizeof(prime));
    for(int i = 2; i <= sqrt(r); i++){
        for(int j = max(i*i, (l+i-1)/i*i); j <= r; j+=i)
            prime[j-l] = false;
    }
    if(l <= 1)
        prime[1-l] = false;
    // for(int i = l; i <= r; i++)
    //     if(prime[i-l])
    //         cout << i << '\n';
    // cout << '\n';
}