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
    void check(TreeNode*root, int targetSum,vector<int> &sum,int &count){
        if(root==NULL)
        return ;

        sum.push_back(root->val);
        long long int currSum=0;
        for(int i=sum.size()-1;i>=0;i--){
            currSum += sum[i];
            if(targetSum==currSum)
            count++;
        }
        check(root->left, targetSum, sum, count);
        check(root->right, targetSum, sum, count);
        sum.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count =0;
        vector<int> sum;
        check(root, targetSum, sum, count);
        return count;
    }
};