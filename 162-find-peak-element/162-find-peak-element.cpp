class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //if only 1 element is present
        if(nums.size() == 1)
            return 0;
        //1st element is peak
        if(nums[0] > nums[1])
            return 0; 
        //last element is peak
        if(nums[nums.size()-1] > nums[nums.size()-2])
            return nums.size()-1;
        
        for(int i=1; i<nums.size()-1; i++)
        {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
        }
        return -1;
    }
};