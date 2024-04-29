class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int s = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for(int e=0; e<nums.size(); e++) {
            if (nums[e] == 0) {
                zeroCount++;

                while (zeroCount > 1) {
                    if (nums[s] == 0) {
                        zeroCount--;
                    }
                    s++;
                }

        }
            maxLen = max(maxLen, e - s);
    }
    return maxLen;
    }
};
