class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0;
        int count = 0;
        int maxCount = INT_MIN;
        while(i < nums.size()){
            if(nums[i]==0){
                maxCount = max(maxCount, count);
                count = 0;
            }
            else{
                count++;
            }
            i++;
        }
        return max(maxCount, count);;
    }
};