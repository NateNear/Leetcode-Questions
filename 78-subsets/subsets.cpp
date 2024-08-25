class Solution {
public:

    void solve(vector<int>& nums, vector<int> temp, vector<vector<int>>& res, int i){
        if(i>=nums.size()){
            res.push_back(temp);
            return ;
        }

        solve(nums, temp, res, i+1);

        temp.push_back(nums[i]);
        solve(nums, temp, res, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;

        solve(nums,temp, res, 0);
        return res;
    }
};