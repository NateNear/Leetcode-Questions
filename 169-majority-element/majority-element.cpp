class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int temp = nums[i];
            map[temp] ++;

            if(map[temp] > n/2){
                return temp;
            }
        }
        return 0;
    }
};