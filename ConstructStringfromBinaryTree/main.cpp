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
    string tree2str(TreeNode* t) {
        if (t == NULL)
            return "";
        if (!t->left && !t->right)
            return to_string(t->val);
        string ret;
        ret += to_string(t->val);
        ret.push_back('(');
        if (t->left)
            ret += tree2str(t->left);
        ret.push_back(')');
        if (t->right) {
            ret.push_back('(');
            ret += tree2str(t->right);
            ret.push_back(')');
        }
        return ret;
    }
};

int main()
{
    return 0;
}
