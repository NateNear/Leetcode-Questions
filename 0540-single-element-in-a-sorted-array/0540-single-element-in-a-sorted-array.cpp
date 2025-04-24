class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0;
        while(i<nums.size()-1){
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
            i+=2;
        }
        return nums[i];
    }
};