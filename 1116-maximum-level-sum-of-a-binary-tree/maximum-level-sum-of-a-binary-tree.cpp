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
    int maxi=INT_MIN;
    queue<TreeNode*> q;
    int  ans=1;
    void helpmaxLevelSum(TreeNode* root){
        if(root==NULL){
            return;
        }
        TreeNode* temp= root;
        q.push(temp);
        int level=1;
        while(!q.empty()){
            int sum = 0;
            int size=q.size();
            for (int i=0;i<size;i++) {
                TreeNode* item = q.front();
                sum+=item->val;
                if(item->left!=NULL){
                    q.push(item->left);
                }
                if(item->right!=NULL){
                    q.push(item->right);
                }
                q.pop();
            }
            
            if(sum>maxi){
                maxi=sum;
                ans=level;
            }

            level++;
        }
    }
    int maxLevelSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        helpmaxLevelSum(root);
        return ans;
    }
};