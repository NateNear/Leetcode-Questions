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

        for(int j=ans.size()-1; j>0; j--){
            out += ans[j];
            out += ' ';
        }
        return out+ans[0
        ];
    }
};