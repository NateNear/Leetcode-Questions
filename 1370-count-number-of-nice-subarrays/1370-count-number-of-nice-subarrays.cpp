class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0;
        int cnt = 0;
        int ans = 0;
        int prefix = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0)
                cnt++;

            if (cnt > k) {

                while (cnt > k) {
                    if (nums[l] % 2 != 0)
                        cnt--;
                    l++;
                }
                prefix = 0;
            }

            while (cnt == k && nums[l] % 2 == 0) {
                prefix++;
                l++;
            }

            if (cnt == k)
                ans += (prefix + 1);
        }
        return ans;
    }
};
