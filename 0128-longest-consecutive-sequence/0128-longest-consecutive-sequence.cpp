class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;

        int res = 1;
        int maxi = 1;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=1; i<n; i++){

            if(nums[i] == nums[i-1]) continue;

            if(nums[i] == nums[i-1] + 1){
                res++;
            }
            else{
                maxi = max(res, maxi);
                res = 1;
            }
        }
        maxi = max(res, maxi);
        return maxi;
    }
};