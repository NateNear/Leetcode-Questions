class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minD = INT_MAX;

        int maxD = 0;

        for(int i=0; i<prices.size(); i++){
            minD = min(prices[i], minD);
            maxD = max(maxD, prices[i]-minD);
        }
        return maxD;
    }
};