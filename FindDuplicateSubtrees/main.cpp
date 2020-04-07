#include <bits/stdc++.h>

using namespace std;
    struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<uint64_t, uint32_t> id_;
    unordered_map<uint32_t, uint32_t> count_;
    vector<TreeNode *> ans_;
    uint32_t getID(TreeNode *root) {
        if (root == NULL) return 0;
        uint64_t sig = (static_cast<uint64_t>(root->val) << 32) |
                       (getID(root->left) << 16) |
                       getID(root->right);
        int id;
        auto it = id_.find(sig);
        if (it == id_.end()) {
            id = id_.size() + 1;
            id_[sig] = id;
        } else
            id = it->second;
        if (++count_[id] == 2)
            ans_.push_back(root);
        return id;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        getID(root);
        return ans_;
    }
};

int main()
{
    return 0;
}
