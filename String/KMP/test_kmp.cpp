#include "../../template"
#include "Kmp.h"

// AC: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        vector<int> res = __KMP(needle, haystack);
        for (size_t i = 0; i < n; i++) {
            if (res[i] == m) return i - m + 1;
        }
        return -1;
    }
};