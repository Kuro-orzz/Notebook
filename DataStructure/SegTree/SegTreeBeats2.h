#include "../../template.h"


struct Node {
    ll max1, max2, cntMax, sum, lazy;

    Node() {}

    Node(int val) {
        max1 = val;
        max2 = -1;
        cntMax = 1;
        sum = val;
        lazy = -1;
    }

    Node operator+(const Node &b) {
        Node res;
        res.max1 = max(max1, b.max1);
        res.max2 = max(max2, b.max2);
        if (res.max1 != max1) res.max2 = max(res.max2, max1);
        if (res.max1 != b.max1) res.max2 = max(res.max2, b.max1); 
        res.cntMax = 0;
        if (res.max1 == max1) res.cntMax += cntMax;
        if (res.max1 == b.max1) res.cntMax += b.cntMax;
        res.sum = sum + b.sum;
        res.lazy = -1;
        return res;
    }

    void setMin(int val) {
        if (val > max1) return;
        sum -= (max1 - val) * cntMax;
        max1 = val;
        lazy = val;
    }
};

// range chmin, sum
class SegTreeBeats {
public:
    vector<Node> tree;

    SegTreeBeats(int n): tree(4*n) {}

    void build(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u) return;
        if (u <= l && r <= v) {
            tree[id] = Node(val);
            return;
        }
        int mid = (l + r) >> 1;
        build(id*2, l, mid, u, v, val);
        build(id*2+1, mid+1, r, u, v, val);
        tree[id] = tree[id*2] + tree[id*2+1];
    }   

    void push(int id) {
        if (tree[id].lazy < 0) return;
        tree[id*2].setMin(tree[id].lazy);
        tree[id*2+1].setMin(tree[id].lazy);
        tree[id].lazy = -1;
    }

    void updateChmin(int id, int l, int r, int u, int v, int x) {
        if (l > v || r < u) return;
        if (tree[id].max1 <= x) return;
        if (u <= l && r <= v && tree[id].max2 < x) {
            tree[id].setMin(x);
            return;
        }
        push(id);
        int mid = (l + r) >> 1;
        updateChmin(id*2, l, mid, u, v, x);
        updateChmin(id*2+1, mid+1, r, u, v, x);
        tree[id] = tree[id*2] + tree[id*2+1];
    }

    ll getSum(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return tree[id].sum;
        push(id);
        int mid = (l + r) >> 1;
        ll t1 = getSum(id*2, l, mid, u, v);
        ll t2 = getSum(id*2+1, mid+1, r, u, v);
        return t1 + t2;
    }
};