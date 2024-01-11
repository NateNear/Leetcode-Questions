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
    void solve(TreeNode* root, vector<int> &inorder){
        if(root==NULL) return ;

        solve(root->left, inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        solve(root, inorder);
        int i=0, j= inorder.size()-1;

        while(i<j){
            int sum = inorder[i] + inorder[j];
            if(sum == k) return true;

            else if(sum>k) j--;
            else i++;
        }
        return false;
    }
};