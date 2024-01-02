class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> umap;
        int cnt = 0;

        for (int c : nums) {
            umap[c]++;
            cnt = max(cnt, umap[c]);
        }

        vector<vector<int>> ans(cnt);

        for (auto a : umap) {
            int num = a.first;
            int freq = a.second;

            for (int i = 0; i < freq; i++) {
                ans[i].push_back(num);
            }
        }

        return ans;
    }
};
