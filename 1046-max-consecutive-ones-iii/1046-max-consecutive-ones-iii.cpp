class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int i = 0;
        int s = 0, e=0;
        int flip = 0;
        int maxLen = 0;

        while(e<nums.size()){
            if(nums[e] == 1){
                e++;
            }
            else if(nums[e] == 0 && flip<k){
                e++;
                flip++;
            }
            else{
                while(flip>=k){
                    if(nums[s]==0){
                        flip--;
                    }
                    
                    s++;
                }
            }
            maxLen = max(maxLen, e-s);
        }
        return maxLen;
    
    }
};