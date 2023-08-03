class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length(); 
        int l = max(m,n);
        string ans="";
        int i=0;
        
        while(i<l){
            if(i<m){
                ans.push_back(word1[i]);
            }
            if(i<n){
                ans.push_back(word2[i]);
            }
            i++;
        }
        return ans;
    }
};