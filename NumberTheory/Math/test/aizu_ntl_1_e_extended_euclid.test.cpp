#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "../../../template.h"
#include "../Extended_euclid.h"

void solve() {
	int a, b; cin >> a >> b;
	int x, y;
	int g = extended2(a, b, x, y);
	cout << x << " " << y << '\n';
}