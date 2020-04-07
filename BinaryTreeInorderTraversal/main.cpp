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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans;
        vector<TreeNode *> stack;
        stack.push_back(root);
        bool back = false;
        while (!stack.empty()) {
            if (stack.back() == NULL) {
                stack.pop_back();
                back = true;
                continue;
            }
            if (!back) {
                stack.push_back(stack.back()->left);
                continue;
            } else {
                auto cur = stack.back();
                ans.push_back(cur->val);
                stack.pop_back();
                stack.push_back(cur->right);
                back = false;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
