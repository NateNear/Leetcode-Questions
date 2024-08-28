class Solution {
public:
    bool isPalindrome(string s) {
        int beg = 0, end = s.size() - 1;
        while (beg < end) {
            if (s[beg] != s[end]) return false;
            beg++; end--;
        }
        return true;
    }

    void solve(string s, vector<string>& temp, vector<vector<string>>& res, int ind) {
        if (ind == s.length()) {
            res.push_back(temp);
            return;
        }

        for (int i = ind; i < s.length(); i++) {
            if (isPalindrome(s.substr(ind, i - ind + 1))) {
                temp.push_back(s.substr(ind, i - ind + 1));
                solve(s, temp, res, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        solve(s, temp, res, 0);
        return res;
    }
};
