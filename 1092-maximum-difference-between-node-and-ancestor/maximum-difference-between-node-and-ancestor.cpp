/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, int maxi, int mini, int &ans){
        if(root==NULL) return;
        
        maxi = max(maxi,root->val);
        mini = min(mini, root->val);

        ans = max(ans, maxi-mini);

        solve(root->left,maxi, mini, ans);
        solve(root->right, maxi, mini, ans);    
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int mini , maxi ;
        mini = maxi = root->val;
        int ans = 0;
        solve(root, mini, maxi, ans);
        return ans;
    }
};