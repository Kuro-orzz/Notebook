#include "../template.h"

template <typename T>
struct Compress {
    int cnt = 1;
    map<T, int> compressed;
    vector<T> decompress;

    Compress(const vector<T> &a) {
        decompress.push_back(T(0));
        vector<T> b = a;
        sort(all(b));
        unique(b);
        for (T x : b) {
            compressed[x] = cnt++;
            decompress.push_back(x);
        }
    }

    int operator[] (const T &x) const { assert(compressed.count(x)); return compressed[x]; }

    T getDecomp(int i) const { return decompress[i]; }
};