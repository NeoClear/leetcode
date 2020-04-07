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
    TreeNode *solve(vector<int> in, vector<int> post) {
        if (in.empty() && post.empty())
            return NULL;
        TreeNode *root = new TreeNode(post.back());
        int id;
        for (id = 0; id < in.size(); id++)
            if (in[id] == root->val)
                break;
        root->left = solve(vector<int>(in.begin(), in.begin() + id),
                           vector<int>(post.begin(), post.begin() + id));
        root->right = solve(vector<int>(in.begin() + id + 1, in.end()),
                            vector<int>(post.begin() + id, post.end() - 1));
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, postorder);
    }
};

int main()
{
    return 0;
}
