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

TreeNode* printBst(vector<int> preorder, int mini, int maxi, int &i) {
    if(i>=preorder.size()) return NULL;

    if(preorder[i]>maxi || preorder[i]<mini) return NULL;

    TreeNode* root = new TreeNode(preorder[i++]);

    root->left = printBst(preorder, mini, root->val, i);
    root->right = printBst(preorder, root->val, maxi, i);

    return root;
}

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i=0;

        return printBst(preorder, mini, maxi, i);
    }
};