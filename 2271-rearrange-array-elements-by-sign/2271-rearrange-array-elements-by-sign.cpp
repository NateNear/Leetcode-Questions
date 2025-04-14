class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }
        
        vector<int> res(nums.size());
        int i = 0, j = 0, k = 0;
        
        while(i < pos.size() && j < neg.size()) {
            res[k++] = pos[i++];
            res[k++] = neg[j++];
        }
        
        while(i < pos.size()) {
            res[k++] = pos[i++];
        }
        while(j < neg.size()) {
            res[k++] = neg[j++];
        }

        return res;
    }
};
