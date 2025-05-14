// https://codeforces.com/contest/221/problem/D

#include "../../template.h"

int block_sz;
vector<int> a;
 
struct Query{
    int l, r, idx;
};
 
vector<Query> q;
 
bool cmp1(Query a, Query b){
    if(a.l/block_sz != b.l/block_sz)
        return a.l/block_sz < b.l/block_sz;
    return a.r < b.r;
}
 
bool cmp2(pair<ll, int> a, pair<ll, int> b){
    return a.se < b.se;
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
 
void query(){
    sort(q.begin(), q.end(), cmp1);
    int curL = 0, curR = 0;
    vector<pair<ll, int>> ans;
    for(int i = 0; i < (int)q.size(); i++){
        while(curL < q[i].l){
            remove(curL);
            curL++;
        }
        while(curL > q[i].l){
            curL--;
            insert(curL);
        }
        while(curR <= q[i].r){
            insert(curR);
            curR++;
        }
        while(curR > q[i].r+1){
            curR--;
            remove(curR);
        }
        ans.push_back({cnt, q[i].idx});
    }
    sort(ans.begin(), ans.end(), cmp2);
    for(auto it : ans)
        cout << it.fi << '\n';
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
    query();
}