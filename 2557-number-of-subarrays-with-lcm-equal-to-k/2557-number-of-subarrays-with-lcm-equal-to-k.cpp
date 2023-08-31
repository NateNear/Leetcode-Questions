class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            int num=nums[i];
            if(num==k){
                count++;
            }
            for(int j=i+1; j<n; j++){
                num=lcm(num, nums[j]);
                if(num==k){
                    count++;
                }
                if(num>k){
                    break;
                }
            }
        }
        return count;
    }
};