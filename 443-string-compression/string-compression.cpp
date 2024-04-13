class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()<2){
            return chars.size();
        }
        vector<char> ans;
        int count = 1;
        int i=1;
        char letter = chars[0];
        
        while(i<chars.size()){

            if(letter == chars[i]){
                count++;
            }
            else{
                ans.push_back(letter);
                if(count > 1){
                    string countStr = to_string(count);
                    for(char c : countStr){
                        ans.push_back(c);
                    }
                }
                count = 1;
                letter = chars[i];
            }
            i++;
        }

        ans.push_back(letter);
        if(count > 1){
            string countStr = to_string(count);
            for(char c : countStr){
                ans.push_back(c);
            }
        }

        int n = ans.size();
        chars = ans;

        return n;
    }
};