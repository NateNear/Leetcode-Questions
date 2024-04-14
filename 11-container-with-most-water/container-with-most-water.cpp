class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxar = INT_MIN;
        int temp = 0;

        while(i<j){
            int mini = min(height[i], height[j]);
            int diff = j-i;
            temp = mini*diff;
            maxar = max(temp, maxar);
            
            if(height[i]>height[j])
            j--;
            else{
                i++;
            }
        }
        return maxar;
    }
};