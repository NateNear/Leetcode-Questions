class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int rem = target - nums[i];
            if(mp.count(rem)){
                return {i, mp[rem]};
            }

            mp[nums[i]] = i;
        }
        return {};
    }
};