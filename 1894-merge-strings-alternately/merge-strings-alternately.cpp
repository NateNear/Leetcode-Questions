class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = word1.length();
        int j = word2.length();
        int k = max(i,j);
        string ans = "";

        int x=0;

        while(x<k){
            if(x<i)
            ans.push_back(word1[x]);
            
            if(x<j)
            ans.push_back(word2[x]);

            x++;
        }
        return ans;
    }
};