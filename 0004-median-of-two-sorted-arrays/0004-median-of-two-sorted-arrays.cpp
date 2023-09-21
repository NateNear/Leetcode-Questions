class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final;

        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans;
        for(int i=0; i<n1; i++){
            ans = nums1[i];
            final.push_back(ans);
        }

        for(int i=0; i<n2; i++){
            ans = nums2[i];
            final.push_back(ans);
        }

        sort(final.begin(), final.end());

        int n = final.size();
        double median;

        if(n%2 == 0){
            median = (double)(final[n/2] + final[(n/2)-1]) / 2.0;
        }
        else{
            median = final[n/2];
        }
        return median;
    }
};