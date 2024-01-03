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
    public:
bool rootToLeafPathSum(TreeNode* root, int targetSum, int sum){
        if(root == nullptr)
            return false;
        if(root -> left == nullptr && root -> right == nullptr){
            sum = sum + root -> val;
            if(sum == targetSum)
                return true;   
        }
        return rootToLeafPathSum(root -> left, targetSum, sum + root -> val) || rootToLeafPathSum(root -> right, targetSum, sum + root -> val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return rootToLeafPathSum(root, targetSum, sum);
    }
};
