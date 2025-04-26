class Solution {
public:
    long long calc_total_hrs(vector<int>& piles, int bananas) {
        long long totalH = 0;
        int n = piles.size();
        for(int i = 0; i<n; i++) {
            totalH += (piles[i] + bananas - 1) / bananas;
        }
        return totalH;
    }

    int find_max_ele(vector<int>& piles) {
        int n = piles.size();
        int max_ele = INT_MIN;
        for(int i = 0; i<n; i++) {
            if(piles[i]>max_ele) max_ele = piles[i];
        }
        return max_ele;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = find_max_ele(piles), ans = INT_MIN;
        while(low<=high) {
            int mid = (low+high)/2;
            long long total_hrs = calc_total_hrs(piles, mid);
            if(total_hrs<=h) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};