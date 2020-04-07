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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<int> ans;
        vector<TreeNode *> vec;
        vec.push_back(root);
        while (!vec.empty()) {
            auto cur = vec.back();
            vec.pop_back();
            ans.push_back(cur->val);
            if (cur->right)
                vec.push_back(cur->right);
            if (cur->left)
                vec.push_back(cur->left);
        }
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    Solution ins;
    for (const auto& it : ins.preorderTraversal(root))
        cout<< it<< endl;
    return 0;
}
