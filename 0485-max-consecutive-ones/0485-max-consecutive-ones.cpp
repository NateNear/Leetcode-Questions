class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int count = 0;
        int maxC = 0;

        for(int i=0; i<n; i++){
            if(nums[i]!=1){
                maxC = max(count, maxC);
                count = 0;
            }
            else count++;
        }
        maxC = max(count, maxC);
        return maxC;
    }
};