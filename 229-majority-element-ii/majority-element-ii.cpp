class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = 0, el2 = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(cnt1 == 0 && nums[i] != el2){
                cnt1++;
                el1 = nums[i];
            }else if(cnt2 == 0 && nums[i] != el1){
                cnt2++;
                el2 = nums[i];
            }
            else if(el1 == nums[i]){
                cnt1++;
            }
            else if( el2 == nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> result;
        int threshold = nums.size() / 3;

        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (el1 == nums[i]) {
                cnt1++;
            } else if (el2 == nums[i]) {
                cnt2++;
            }
        }
        if (cnt1 > threshold) {
            result.push_back(el1);
        }
        if (cnt2 > threshold) {
            result.push_back(el2);
        }

        return result;

    }
};