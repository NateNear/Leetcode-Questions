class Solution {
public:
    string reverseVowels(string s) {
        
        vector<char> v;
        for(int i = 0 ; i < s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
              || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U')
                v.push_back(s[i]);
        }
        reverse(v.begin(), v.end());
        int rev = 0;
        for(int i = 0 ; i < s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
              || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U'){
                s[i] = v[rev];
                rev++;
            }
        }
        return s;
    }
};