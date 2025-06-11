#include "../../../template.h"


struct Node {
    ll Max, sum;

    Node() {}

    Node(int val) {
        Max = val;
        sum = val;
    }

    Node operator+(const Node &b) {
        Node res;
        res.Max = max(Max, b.Max);
        res.sum = sum + b.sum;
        return res;
    }
};

// range mod, sum query
// point assign query
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

    void updateMod(int id, int l, int r, int u, int v, int x) {
        if (l > v || r < u) return;
        if (tree[id].Max < x) return;
        if (l == r) {
            tree[id].Max %= x;
            tree[id].sum = tree[id].Max;
            return;
        }
        int mid = (l + r) >> 1;
        updateMod(id*2, l, mid, u, v, x);
        updateMod(id*2+1, mid+1, r, u, v, x);
        tree[id] = tree[id*2] + tree[id*2+1];
    }

    ll getSum(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return tree[id].sum;
        int mid = (l + r) >> 1;
        ll t1 = getSum(id*2, l, mid, u, v);
        ll t2 = getSum(id*2+1, mid+1, r, u, v);
        return t1 + t2;
    }
};