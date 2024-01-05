class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> umap1, umap2;

        for (int i = 0; i < s.size(); i++) {
            if (umap1[s[i]] != umap2[t[i]])
                return false;

            umap1[s[i]] = i + 1;
            umap2[t[i]] = i + 1;
        }

        return true;
    }
};