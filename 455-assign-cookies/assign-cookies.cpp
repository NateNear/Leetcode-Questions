class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int count = 0;

        int child = g.size()-1;
        int nco = s.size()-1;

        while(child>=0  && nco>=0){
            if(s[nco]>=g[child]){
                count++;
                nco--;
                child--;
            }
            else{
                child--;
            }
        }

        return count;
    }
};