#include "../../template.h"

struct Node {
	Node *child[26];
	bool isEnd;

	Node() {
		memset(child, 0, sizeof child);
		isEnd = false;
	}
};

class Trie {
	Node *r = new Node();

	Trie() {}

	void add(const string &s) {
		Node *u = r;
		for (size_t i = 0; i < s.size(); i++) {
			int k = s[i] - 'a';
			if (!u->child[k]) {
				u->child[k] = new Node();
			}
			u = u->child[k];
		}
		u->isEnd = true;
	}

	bool search(const string &s) {
		Node *u = r;
		for (size_t i = 0; i < s.size(); i++) {
			int k = s[i] - 'a';
			if (!u->child[k]) {
				return false;
			}
			u = u->child[k];
		}
		return u->isEnd;
	}
};