#include "../template.h"

vector<int> Z_function(const string &s) {
	int n = s.size();
	vector<int> z(n);
	z[0] = (int)s.size();
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) {
			z[i] = min(r-i+1, z[i-l]);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}