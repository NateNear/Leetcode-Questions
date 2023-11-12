class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxC = 0;

        for(int i=0; i<candies.size(); i++){
            maxC = max(maxC, candies[i]);
        }

        vector<bool> ans;
        for(int i=0; i<candies.size(); i++){
           int plus = candies[i] + extraCandies; 
            if(plus>=maxC){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }

        }
        return ans;
    }
};