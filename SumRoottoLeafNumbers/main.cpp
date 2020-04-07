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
    unordered_map<TreeNode *, TreeNode *> par;
    queue<TreeNode *> q;
    void build(TreeNode *root) {
        if (!root->left && !root->right) {
            q.push(root);
            return;
        }
        if (root->left) {
            par[root->left] = root;
            build(root->left);
        }
        if (root->right) {
            par[root->right] = root;
            build(root->right);
        }
    }
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return 0;
        build(root);
        int ans = 0;
        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto cur = q.front();
                q.pop();
                ans += cur->val * step;
                if (par.count(cur)) {
                    q.push(par[cur]);
                }
            }
            if (step == 1000000000)
                break;
            step *= 10;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
