#include "../../template.h"

vector<int> lps(const string &s) {
	int n = s.size();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> __KMP(const string &s, const string &t) {
	int n = s.size(), m = t.size();
	if (n == 0) return {};
	vector<int> pi = lps(s);
	int j = 0;
	vector<int> ans(m);
	for (int i = 0; i < m; i++) {
		while (j > 0 && t[i] != s[j]) {
			j = pi[j - 1];
		}
		if (t[i] == s[j]) j++;
		ans[i] = j;
		if (j == n) {
			j = pi[j - 1];
		}
	}
	return ans;
}