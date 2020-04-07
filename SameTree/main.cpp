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
    bool solve(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL) {
            if (p == NULL && q == NULL)
                return true;
            return false;
        }
        return p->val == q->val &&
                solve(p->left, q->left) &&
                solve(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
