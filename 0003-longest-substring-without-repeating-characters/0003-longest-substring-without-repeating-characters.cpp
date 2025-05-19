class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;

        int l = 0;
        int maxL = 0;

        for (int r = 0; r < s.length(); ++r) {
            char currentChar = s[r];

            if (map.find(currentChar) != map.end() && map[currentChar] >= l) {

                l = map[currentChar] + 1;
            }

            map[currentChar] = r;
            maxL = max(maxL, r - l + 1);
        }

        return maxL;
    }
};