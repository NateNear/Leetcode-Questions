class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxE=0;
        vector<bool> ans;
        for(int i=0; i<candies.size(); i++){
            if(candies[i]>maxE)
            maxE=candies[i];
        }

        for(int i=0; i<candies.size(); i++){
            if(candies[i]+extraCandies >= maxE)
            ans.push_back(true);

            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};