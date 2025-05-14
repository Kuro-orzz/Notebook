#include "../../template.h"

class SimpleSqrt {
public:
	int n, block_sz;
	vector<ll> a, block;

	SimpleSqrt() {}

	SimpleSqrt(int _n): n(_n), a(_n, 0) {
		block_sz = sqrt(_n);
		block.resize(n / block_sz + 1);
	}

	SimpleSqrt(int _n, vector<ll> &arr): n(_n), a(arr) {
    	block_sz = sqrt(n);
    	block.resize(n / block_sz + 1);
    	int cnt = -1;
    	for(int i = 0; i < n; i++) {
        	if(i % block_sz == 0) cnt++;
        	block[cnt] += arr[i];
    	}
	}

	ll query(int l, int r) {
	    ll sum = 0;
	    for(int i = l; i <= r;) {
	        if(i % block_sz == 0 && i+block_sz-1 <= r) {
	            sum += block[i/block_sz];
	            i += block_sz;
	        } else {
	            sum += a[i];
	            i++;
	        }
	    }
	    return sum;
	}

	void add(int pos, int val) {
		int idx = pos / block_sz;
	    block[idx] += val;
	    a[pos] += val;
	}
};