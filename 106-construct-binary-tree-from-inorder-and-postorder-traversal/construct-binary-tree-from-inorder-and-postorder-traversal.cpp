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

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int &ind,int inStart,int inEnd, int n, map<int,int> &mp){

        if(ind<0 || inStart >inEnd){
            return NULL;
        }

        int elem = postorder[ind--];
        TreeNode* root = new TreeNode(elem);

        int pos = mp[elem];

        root->right = solve(postorder, inorder, ind, pos+1, inEnd, n, mp);
        root->left = solve(postorder, inorder, ind, inStart, pos-1, n, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int ind=n-1;
        map<int,int> mp;
        mapped(inorder, mp);
        TreeNode* temp = solve(postorder, inorder, ind, 0, n-1, n, mp);
        return temp;
    }
};