class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int count=0, i=0, j=nums.size()-1;

        while(i<j){
            if(nums[i]+nums[j] == k){
                i++;
                j--;
                count++;
            }
            else if(nums[i] + nums[j] < k){
                i++;
            }
            else{
                j--;
            }
        }
        return count;
    }
};