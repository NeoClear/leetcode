struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int t;
    void solve(TreeNode* par, TreeNode* cur, int& target) {
        if (cur->left)
            solve(cur, cur->left, target);
        if (cur->right)
            solve(cur, cur->right, target);
        if (cur->left == nullptr && cur->right == nullptr && cur->val == target) {
            if (par->left == cur)
                par->left = nullptr;
            if (par->right == cur)
                par->right = nullptr;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* head = new TreeNode(0);
        head->left = root;
        solve(head, root, target);
        return head->left;
    }
};
