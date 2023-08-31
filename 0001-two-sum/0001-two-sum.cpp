class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
   
    vector<int>arr(2);
    
    int n= nums.size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n;j++)
        {
        if(i==j){
            continue;
        }
            
        if((nums[i]+nums[j])==target)
        {
            
            arr[0]=i;
            arr[1]=j;
            return arr;
        }
        }
    }
    return arr;
	}
};