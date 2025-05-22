// https://codeforces.com/contest/86/problem/D

#include "../../template.h"

int block_sz;
vector<int> a;

struct Query{
    int l, r, idx;
};

vector<Query> q;

bool cmp(Query a, Query b){
    if(a.l/block_sz != b.l/block_sz)
        return a.l/block_sz < b.l/block_sz;
    return a.r < b.r;
}

vector<int> fre;
ll sum = 0;

void insert(int i) {
	sum += (2*fre[a[i]]+1)*a[i];
	fre[a[i]]++;
}

void remove(int i) {
	sum -= (2*fre[a[i]]-1)*a[i];
	fre[a[i]]--;
}

vector<ll> query(){
    sort(q.begin(), q.end(), cmp);
    int curL = 0, curR = 0;
    fre.resize(1e6+1, 0);
    vector<ll> ans((int)q.size());
    for(int i = 0; i < (int)q.size(); i++){
        auto [L, R, idx] = q[i];
        while(curL < L) remove(curL++);
        while(curL > L) insert(--curL);
        while(curR <= R) insert(curR++);
        while(curR > R+1) remove(--curR);
        ans[idx] = sum;
    }
    return ans;
}

void solve(){
    int n, t; cin >> n >> t;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < t; i++){
        int l, r; cin >> l >> r;
        q.push_back({l-1, r-1, i});
    }
    block_sz = sqrt(n);
    vector<ll> ans = query();
    for(ll x : ans) cout << x << '\n';
}