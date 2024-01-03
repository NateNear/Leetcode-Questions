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
    pair<bool,int> balance(TreeNode* root){
        if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
        }

        pair<bool,int> left = balance(root->left);
        pair<bool,int> right = balance(root->right);

        bool lans = left.first;
        bool rans = right.first;

        bool diff = abs(left.second - right.second)<=1;

        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(lans && rans && diff)
        ans.first = true;
        else
        ans.first = false;

        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return balance(root).first;
    }
};