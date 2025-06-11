#include "../../template.h"


struct Node {
    int child[26], isEnd;

    Node() {
        memset(child, 0, sizeof child);
        isEnd = 0;
    }
};

class Trie {
public:
    int n, curVertex;
    vector<Node> tree;

    Trie() {}
    Trie(int _n): n(_n+1), curVertex(0) {
        tree.assign(n+1, Node());
    }

    void add(const string &s) {
        int u = 0;
        for (size_t i = 0; i < s.size(); i++) {
            int k = s[i] - 'a';
            if (!tree[u].child[k]) {
                tree[u].child[k] = ++curVertex;
            }
            u = tree[u].child[k];
        }
        tree[u].isEnd++;
    }

    bool search(const string &s) {
        int u = 0;
        for (size_t i = 0; i < s.size(); i++) {
            int k = s[i] - 'a';
            if (!tree[u].child[k]) {
                return 0;
            }
            u = tree[u].child[k];
        }
        return tree[u].isEnd;
    }

    void del(const string &s) {
        if (!search(s)) return;
        int u = 0;
        for (size_t i = 0; i < s.size(); i++) {
            int k = s[i] - 'a';
            u = tree[u].child[k];
        }
        tree[u].isEnd--;
    }

    // sort string
    void dfs(int pos, string &cur, vector<string> &res) {
        for (int i = 0; i < tree[pos].isEnd; i++) {
            res.push_back(cur);
        }
        for (int i = 0; i < 26; i++) {
            if (!tree[pos].child[i]) continue;
            cur += char(i + 'a');
            dfs(tree[pos].child[i], cur, res);
            cur.pop_back();
        }
    }

    vector<string> sort_string() {
        vecor<int> res;
        string s = "";
        dfs(0, s, res);
        return res;
    }

    string find_kth_string(int k) {
        
    }
};