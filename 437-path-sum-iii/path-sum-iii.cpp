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
    void solve(TreeNode* root, int targetSum, vector<int> &sum, int &count){
        if(root==NULL) return ;

        sum.push_back(root->val);

        long long int tot = 0;
        for(int i = sum.size() - 1; i >= 0; i--){
            tot += sum[i];
            if(tot == targetSum)
                count++;
        }

        solve(root->left, targetSum, sum, count);
        solve(root->right, targetSum, sum, count);

        sum.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> sum;
        int count=0;
        solve(root,targetSum, sum, count);
        return count;
    }
};