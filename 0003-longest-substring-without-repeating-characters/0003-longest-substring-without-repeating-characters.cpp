class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right =0;
        unordered_set<char> stt;
        int len =0;
        while(right!=s.size()){
            char temp =s[right];
            char temp2= s[left];
            if(stt.find(temp)==stt.end()){
                stt.insert(temp);
                right++;
            }else{
                stt.erase(temp2);
                left++;
            }
            len=max(len,right-left);
            cout<<len;
        }
        return len;
    }
};