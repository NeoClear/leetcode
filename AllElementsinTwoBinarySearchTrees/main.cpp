#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        queue<TreeNode *> q;
        if (root1)
            q.push(root1);
        if (root2)
            q.push(root2);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            ans.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};