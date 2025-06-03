class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<char> st;

        for(char c:s){
            if(c == '('){
                st.push(c);
            }
            else if( c == ')' && !st.empty()){
                st.pop();
            }
            else{
                cnt++;
            }
        }

        return st.size() + cnt;
    }
};