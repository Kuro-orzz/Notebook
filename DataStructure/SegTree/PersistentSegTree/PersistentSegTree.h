#include "../../../template.h"

// Tested:
// - AC: https://cses.fi/problemset/task/1737/
// - AC: https://www.spoj.com/problems/PSEGTREE/

struct Node {
    Node *left, *right;
    ll sum;
    Node() {}
    Node(ll _sum): left(NULL), right(NULL), sum(_sum) {}
    Node(Node *l, Node *r, ll _sum): left(l), right(r), sum(_sum) {}
    ~Node() {
        delete left;
        delete right;
    }
};

class PersistentSegTree {
public:
    vector<Node*> ver;

    PersistentSegTree() {}
    PersistentSegTree(int n): ver(n+1) {}

    void build(Node *cur, int l, int r, const vector<int> &a) {
        if (l == r) {
            cur->sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        cur->left = new Node(NULL, NULL, 0);
        cur->right = new Node(NULL, NULL, 0);
        build(cur->left, l, mid, a);
        build(cur->right, mid+1, r, a);
        cur->sum = cur->left->sum + cur->right->sum;
    }

    void update(Node *prev, Node *cur, int l, int r, int pos, ll x) {
        if (l == r) {
            cur->sum = x;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            cur->right = prev->right;
            cur->left = new Node(NULL, NULL, 0);
            update(prev->left, cur->left, l, mid, pos, x);
        } else {
            cur->left = prev->left;
            cur->right = new Node(NULL, NULL, 0);
            update(prev->right, cur->right, mid+1, r, pos, x);
        }
        cur->sum = cur->left->sum + cur->right->sum;
    }

    ll getSum(Node *cur, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return cur->sum;
        int mid = (l + r) >> 1;
        return getSum(cur->left, l, mid, u, v) + getSum(cur->right, mid+1, r, u, v);
    }
};