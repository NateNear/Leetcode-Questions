class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        int n = needle.size();
        int N = haystack.size();

        while (j < N) {
            if (haystack[j] == needle[i]) {
                i++;
                j++;
                if (i == n) {
                    return j - n;
                }
            } else {
                j = j - i + 1;
                i = 0;
            }
        }

        return -1;
    }
};
