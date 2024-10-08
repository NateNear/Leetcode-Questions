class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(cnt == 0){
                el = nums[i];
                cnt++;
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return el;
    }
};