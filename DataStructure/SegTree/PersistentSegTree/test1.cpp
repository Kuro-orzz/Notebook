// https://cses.fi/problemset/task/1737/

#include "../../../template.h"
#include "PersistentSegTree.h"

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    PersistentSegTree PST(n);
    Node *root = new Node(NULL, NULL, 0);
    PST.build(root, 1, n, a);

    int cntVer = 1;
    PST.ver[cntVer] = root;
    
    vector<int> arr = {0, 1};

    while (q--) {
        int tv; cin >> tv;
        if (tv == 1) {
            int k, pos, x; cin >> k >> pos >> x;

            PST.ver[++cntVer] = new Node(NULL, NULL, 0);
            Node *prev = PST.ver[arr[k]];
            Node *newRoot = PST.ver[cntVer];
            
            PST.update(prev, newRoot, 1, n, pos, x);
            arr[k] = cntVer;
        } else if (tv == 2) {
            int k, a, b; cin >> k >> a >> b;
            cout << PST.getSum(PST.ver[arr[k]], 1, n, a, b) << '\n';
        } else if (tv == 3) {
            int k; cin >> k;
            arr.push_back(arr[k]);
        }
    }
}