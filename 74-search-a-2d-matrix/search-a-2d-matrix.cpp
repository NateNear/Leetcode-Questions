class Solution {
public:

    bool bs(vector<int> nums, int target){
        int low = 0;
        int n = nums.size();
        int high = n-1;

        while(low<=high){
            int mid = (high+low)/2;

            if(nums[mid] == target){
                return true;
            }else if(nums[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i=0; i<rows; i++){
            if(target<= matrix[i][cols-1] && target>= matrix[i][0]){
                return bs(matrix[i], target);
            }
        }

        return false;
    }
};