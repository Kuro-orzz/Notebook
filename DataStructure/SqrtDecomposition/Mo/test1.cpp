// https://codeforces.com/contest/221/problem/D

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

unordered_map<int, int> fre;
int cnt = 0;

void insert(int i){
    if(fre[a[i]] == a[i]) cnt--;
    fre[a[i]]++;
    if(fre[a[i]] == a[i]) cnt++;
}
 
void remove(int i){
    if(fre[a[i]] == a[i]) cnt--;
    fre[a[i]]--;
    if(fre[a[i]] == a[i]) cnt++;
}
 
vector<int> query(){
    sort(q.begin(), q.end(), cmp);
    int curL = 0, curR = 0;
    vector<int> ans((int)q.size());
    for(int i = 0; i < (int)q.size(); i++){
        auto [L, R, idx] = q[i];
        while(curL < L) remove(curL++);
        while(curL > L) insert(--curL);
        while(curR <= R) insert(curR++);
        while(curR > R+1) remove(--curR);
        ans[idx] = cnt;
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
    vector<int> ans = query();
    for(auto it : ans) cout << it << '\n';
}