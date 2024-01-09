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
    void solve(TreeNode* root, int &maxi, int &finalLev){
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int sum=0;
            int Qsize = q.size();
            for(int i=0; i<Qsize; i++){
                TreeNode* temp = q.front();
                sum += temp->val;
                
                if(temp->left){
                    q.push(temp->left);
                }
                
                if(temp->right){
                    q.push(temp->right);
                }
                
                q.pop();
            }
            if(sum>maxi){
                maxi = sum;
                finalLev = level;
            }
            level++;
        }
    }
public:
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        int maxi = INT_MIN;
        int finalLev=0;
        solve(root, maxi, finalLev);

        return finalLev;
    }
};