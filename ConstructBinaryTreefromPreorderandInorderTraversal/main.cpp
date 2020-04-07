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
    TreeNode *solve(vector<int> pre, vector<int> in) {
        if (pre.empty() && in.empty())
            return NULL;
        TreeNode *root = new TreeNode(pre.front());
        int id;
        for (id = 0; id < pre.size(); id++)
            if (in[id] == root->val)
                break;
        root->left = solve(vector<int>(pre.begin() + 1, pre.begin() + 1 + id),
                           vector<int>(in.begin(), in.begin() + id));
        root->right = solve(vector<int>(pre.begin() + 1 + id, pre.end()),
                            vector<int>(in.begin() + 1 + id, in.end()));
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder);
    }
};

int main()
{
    return 0;
}
