class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr;
        int sum =0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                sum = nums[i]+nums[j];
                if (sum == target){
                    arr.push_back(i);
                    arr.push_back(j);
                    break;
                }

            }
        }
        return arr;
    }
};