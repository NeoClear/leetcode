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
    TreeNode *solve(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2)
            return NULL;
        if (t1 && t2) {
            t1->val += t2->val;
            t1->left = solve(t1->left, t2->left);
            t1->right = solve(t1->right, t2->right);
            return t1;
        }
        if (t1) return t1;
        if (t2) return t2;
        return NULL;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return solve(t1, t2);
    }
};

int main()
{
    return 0;
}
