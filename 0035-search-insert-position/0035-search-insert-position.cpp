class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;

        while(s<=e){
            int m = (s+e)/2;
            
            if(nums[m] == target)
                return m;
            
            else if(nums[m]<target)
                s = m+1;

            else e = m-1;
        }
        return s;

    }
};
