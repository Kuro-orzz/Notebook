#include "../template.h"

vector<int> maxRange(const vector<int>& a, int k) {
	deque<int> dq;
	vector<int> res;
	for(size_t i = 0; i < a.size(); i++) {
		while(!dq.empty() && a[dq.back()] <= a[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		if(dq.front() + k <= i) dq.pop_front();
		if(i >= k-1) res.push_back(a[dq.front()]);
	}
	return res;
}

vector<int> minRange(const vector<int>& a, int k) {
	deque<int> dq;
	vector<int> res;
	for(size_t i = 0; i < a.size(); i++) {
		while(!dq.empty() && a[dq.back()] >= a[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		if(dq.front() + k <= i) dq.pop_front();
		if(i >= k-1) res.push_back(a[dq.front()]);
	}
	return res;
}