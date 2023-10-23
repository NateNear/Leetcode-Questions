class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int s = 0;
        int e = n-1;
        int x;
        int minH = 0;
        int maxA = INT_MIN;
        int area;
         while(s<e){
            minH = min(height[s], height[e]);
            x = e-s;
            area = minH*x;
            maxA = max(area, maxA);

            if(height[s]<height[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return maxA;
    }
};