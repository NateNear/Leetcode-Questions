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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;

        map<int,map<int,vector<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> que;

        que.push(make_pair(root,make_pair(0,0)));

        while(!que.empty()){
            pair<TreeNode*,pair<int,int>> temp = que.front();
            que.pop();
            TreeNode*tempNode = temp.first;

            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(tempNode->val);

            if(tempNode->left)
                que.push(make_pair(tempNode->left, make_pair(hd-1, lvl+1)));

            if(tempNode->right)
                que.push(make_pair(tempNode->right, make_pair(hd+1, lvl+1)));
        }

        for(auto i:nodes){
            vector<int> ans;
            for(auto j:i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};