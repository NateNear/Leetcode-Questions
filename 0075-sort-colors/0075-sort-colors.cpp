class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zer =0;
        int one = 0;
        int two = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) zer++;
            else if(nums[i] == 1) one++;
            else two++;
        }

            int i=0;
            while(zer!=0){
                nums[i] = 0;
                i++;
                zer--;
            }
            while(one!=0){
                nums[i] = 1;
                i++;
                one--;
            }
            while(two!=0){
                nums[i] = 2;
                i++;
                two--;
            }
        
    }
};