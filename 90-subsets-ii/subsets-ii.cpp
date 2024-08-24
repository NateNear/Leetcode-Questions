class Solution {
public:
    void subsetFunc(vector<int>& nums, int index, vector<vector<int>> &res, vector<int> &temp) {
        res.push_back(temp);

        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            subsetFunc(nums, i + 1, res, temp);
            
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());

        subsetFunc(nums, 0, res, temp);
        return res;
    }
};
