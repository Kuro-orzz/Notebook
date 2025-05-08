#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "../template.h"

void solve() {
	ll n; cin >> n;
	set<ll> s;
	for (ll i = 1; i*i <= n; i++) {
		s.insert(i);
		s.insert(n / i);
	}
	cout << s.size() << '\n';
	for (ll x : s) cout << x << " ";
}