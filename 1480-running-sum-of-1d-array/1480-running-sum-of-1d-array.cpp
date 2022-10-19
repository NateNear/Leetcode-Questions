class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n = nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            nums[i] = nums[i] + ans;
            ans = nums[i];
        }
        return nums;
    }
};