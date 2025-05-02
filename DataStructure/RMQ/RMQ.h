#include "../../template.h"

template <typename T>
struct RMQ {
	int n;
	vector<vector<T>> mn, mx, sum;

	RMQ() {}
	RMQ(int _n): n(_n) {
		mn = mx = sum = vector<vector<T>>(20, vector<T>(_n+1));
	}

	void preprocess(vector<T> &a) {
		for (int i = 1; i <= n; i++) {
			mn[0][i] = mx[0][i] = sum[0][i] = a[i];
		}
		for (int i = 1; i < 20; i++) {
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				mn[i][j] = min(mn[i-1][j], mn[i - 1][j + (1 << (i-1))]);
				mx[i][j] = max(mx[i-1][j], mx[i - 1][j + (1 << (i-1))]);
				sum[i][j] = sum[i-1][j] + sum[i - 1][j + (1 << (i-1))];
			}
		}
	}

	T queryMin(int l, int r) {
		int k = __lg(r-l+1);
		return min(mn[k][l], mn[k][r - (1 << k) + 1]);
	}

	T queryMax(int l, int r) {
		int k = __lg(r-l+1);
		return max(mx[k][l], mx[k][r - (1 << k) + 1]);
	}

	T querySum(int l, int r) {
		int len = r-l+1;
		T ans = 0;
		for (int i = 0; (1 << i) <= len; i++) {
			if (len >> i & 1) {
				ans += sum[i][l];
				l += (1 << i);
			}
		}
		return ans;
	}
};