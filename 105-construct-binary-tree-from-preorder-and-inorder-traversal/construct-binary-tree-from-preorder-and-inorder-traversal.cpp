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

    void mapped(vector<int>& inorder, map<int,int> &mp){
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &ind,int inStart,int inEnd, int n, map<int,int> &mp){

        if(ind>=n || inStart >inEnd){
            return NULL;
        }

        int elem = preorder[ind++];
        TreeNode* root = new TreeNode(elem);

        int pos = mp[elem];

        root->left = solve(preorder, inorder, ind, inStart, pos-1, n, mp);
        root->right = solve(preorder, inorder, ind, pos+1, inEnd, n, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind=0;
        int n = inorder.size();
        map<int,int> mp;
        mapped(inorder, mp);
        TreeNode* temp = solve(preorder, inorder, ind, 0, n-1, n, mp);
        return temp;
    }
};