class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;

        if(nums.empty()){
            return 0;
        }

        for(int i = 0; i<nums.size(); i++){
            if(i==nums.size()-1 || nums[i]!=nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        nums = ans;
        return ans.size();
    }
};