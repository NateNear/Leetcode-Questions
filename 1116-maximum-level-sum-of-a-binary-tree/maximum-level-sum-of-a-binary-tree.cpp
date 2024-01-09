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
    void solve(TreeNode* root,vector<int> &sum, int level){
        if(root==NULL) return;

        if(sum.size()==level)
            sum.push_back(root->val);
        
        else{
            sum[level] += root->val;
        }

        solve(root->left, sum, level+1);
        solve(root->right, sum, level+1);
    }
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        solve(root,sum,0);
        
        int maxLevel = 0;
        
        for (int i = 1; i < sum.size(); ++i) {
            if (sum[i] > sum[maxLevel]) {
                maxLevel = i;
            }
        }
        return maxLevel+1;
    }
};