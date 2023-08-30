class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> s;

        int i=1, j=0;

        while(i<=n && j<target.size()){
            s.push(i);
            i++;
            ans.push_back("Push");

            if(target[j]==s.top()){
                j++;
            }
            else{
                s.pop();
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};