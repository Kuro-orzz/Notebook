#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "../template.h"

template <typename T>
class custom_set {
public:
    set<T> s;

    void insert(T k) {
        s.insert(k);
    }

    void erase(T k) {
        s.erase(k);
    }

    bool contain(T k) {
        return s.count(k);
    }

    T find_next(T k) {
        auto it = s.lower_bound(k);
        if (it == s.end())
            return -1;
        return *it;
    }

    T find_prev(T k) {
        auto it = s.upper_bound(k);
        if (it == s.begin())
            return -1;
        return *prev(it);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    string str; cin >> str;
    custom_set<int> s;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '1')
            s.insert(i);
    }
    while (q--) {
        int tv, k; cin >> tv >> k;
        if (tv == 0) {
            s.insert(k);
        } else if (tv == 1) {
            s.erase(k);
        } else if (tv == 2) {
            cout << (s.contain(k) ? 1 : 0) << '\n';
        } else if (tv == 3) {
            cout << s.find_next(k) << '\n'; 
        } else if (tv == 4) {
            cout << s.find_prev(k) << '\n';
        }
    }
}