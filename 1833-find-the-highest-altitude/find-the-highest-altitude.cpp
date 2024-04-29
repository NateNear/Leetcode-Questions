class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int s=0;
        int maxi=0;
        for(int i=0;i<gain.size();i++)
        {
            s+=gain[i];
            maxi=max(maxi,s);
        }
        return maxi;
    }
};