class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0; 
        int zeroCnt = 0;
        int maxL = 0;

        for(int r=0; r<nums.size(); r++){
            if(nums[r] == 0)
                zeroCnt++;

            while(zeroCnt > k){
                if(nums[l] == 0)
                    zeroCnt--;
                l++;
            }

            maxL = max(maxL, r-l+1);
        }
        return maxL;
    }
};