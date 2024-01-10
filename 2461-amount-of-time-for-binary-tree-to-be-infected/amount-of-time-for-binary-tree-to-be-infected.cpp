class Solution {
    TreeNode* findTarget(TreeNode* root, int start, map<TreeNode*, TreeNode*>& nodeToParent) {
        TreeNode* target;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front->val == start) {
                target = front;
            }
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return target;
    }

    int solve(TreeNode* root, map<TreeNode*, TreeNode*>& nodeToParent) {
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        visited[root] = true;

        while (!q.empty()) {
            int flag = 0;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    visited[front->left] = true;
                    q.push(front->left);
                    flag = 1;
                }

                if (front->right && !visited[front->right]) {
                    visited[front->right] = true;
                    q.push(front->right);
                    flag = 1;
                }

                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                    flag = 1;
                }
            }
            if (flag == 1) {
                ans++;
            }
        }
        return ans;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* target = findTarget(root, start, nodeToParent);
        int ans = solve(target, nodeToParent);
        return ans;
    }
};
