class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string word = "";

        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(word.size()!=0){
                    
                    ans.push_back(word);

                }   
                    word="";
            }
            else{
                word += s[i];
            }
        }
        if(word.size()>0 and word[0]!=' ')
            ans.push_back(word);
        string out = "";

        for(int i=ans.size()-1; i>0; i--){
            out += ans[i];
            out += ' '; 
        }
        return out+ans[0];
    }
};