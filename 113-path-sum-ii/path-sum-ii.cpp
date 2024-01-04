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
    void sum(TreeNode* root, int targetSum, vector<int>&ans, vector<vector<int>> &out){
        if(root == NULL)
        {
            return ;
        }

        ans.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val - targetSum == 0)
        {
            out.push_back(ans);
        }
        sum(root->left,targetSum - root->val, ans, out);
        sum(root->right, targetSum-root->val, ans, out);

        ans.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ans;
        vector<vector<int>> out;
        sum(root, targetSum, ans, out);
        return out;
    }
};