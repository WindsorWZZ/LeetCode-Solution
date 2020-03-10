# KMP Algorithm
## Introduction
Given a problem of matching the substring of a string with a pattern string:  
```
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
```

## Algorithm
1. Brutal force
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
        int len = needle.size();
        int pos = len - 1;
        while (pos < haystack.size()) {
            if (haystack.substr(pos - len + 1, len) == needle)
                return pos - len + 1;
            pos++;
        }
        return -1;
    }
};
```
2. KMP  
When the two strings are matched until position i in substring and j in the pattern, brutal force will set i and j back to the start, increase i with 1 and restart matching. The time complexity is O(m * n)  
While in KMP, we first record the length of the longest common prefix and postfix of each substring of pattern string, in the array next[]. next[j] = longest prefix length - 1.  
When conducting matching and meeting with the unmatch at i and j, we only need to trace back j using the next[]. If next[j] = n, it means that 0 ~ n is equal to j-n+1 ~ j, and i-n ~ i-1 is equal to them. So we can start to move j back to j-n+1 and match j with i again.  
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int next[needle.size()];
        cal_next(needle, next);
        return match(haystack, needle, next);
    }
    void cal_next(string s, int *next) {
        next[0] = -1;
        int k = -1;
        int q;
        for (q = 1; q < s.length(); q++) {
            while (k > -1 && s[k + 1] != s[q]) 
                k = next[k];
            if (s[k + 1] == s[q])
                k++;
            next[q] = k;
        }
    }
    int match(string haystack, string needle, int *next) {
        int j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > -1 && needle[j + 1] != haystack[i])
                j = next[j];
            if (needle[j + 1] == haystack[i]) 
                j = j + 1;
            if (j == needle.size() - 1)
                return i - j;
        }
        return -1;
    }
};
```
