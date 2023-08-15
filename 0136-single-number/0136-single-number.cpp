class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if (i == n - 1 || nums[i] != nums[i + 1]) {
                ans = nums[i];
                break;
            }
            i++;
        }
        return ans;
    }
};
