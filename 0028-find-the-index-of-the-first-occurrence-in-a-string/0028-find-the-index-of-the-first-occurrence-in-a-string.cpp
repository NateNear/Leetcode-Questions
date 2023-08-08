class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int N = haystack.size();

        if (n == 0) {
            return 0;
        }

        for (int i = 0; i <= N - n; i++) {
            if (haystack[i] == needle[0]) {
                bool found = true;
                for (int j = 0; j < n; j++) {
                    if (haystack[i + j] != needle[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return i;
                }
            }
        }

        return -1;
    }
};
