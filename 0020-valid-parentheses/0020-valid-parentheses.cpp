class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp = {
            {']','['},
            {')','('},
            {'}','{'}
        };

        stack<char> st;

        for(int i=0; i<s.length(); i++){

            if(s[i] == '}' || s[i] == ')' || s[i]==']'){
                if(st.empty() || mp[s[i]] != st.top() ){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        return st.empty();;
    }
};