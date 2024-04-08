class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count=0, index=0, total=1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                count++;
                index = i;
                if (count > 1)
                    break;
            }
            else{
                total *= nums[i];
            }
        }

        vector<int> ans(nums.size(), 0);

        for(int i=0; i<nums.size(); i++){
            if(count>1)
                return ans;
            
            else if(count==1){
                ans[index] = total;
                
            }

            else{
                ans[i] = total/nums[i];
            }
        }
        return ans;
    }
};