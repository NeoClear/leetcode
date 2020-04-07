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
//    TreeNode *big(TreeNode *root) {
//        while (root->right) root = root->right;
//        return root;
//    }
//    TreeNode *tin(TreeNode *root) {
//        while (root->left) root = root->left;
//        return root;
//    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            if (root->left) {
                TreeNode *pre = root;
                TreeNode *rep = root->left;
                while (rep->right) {
                    pre = rep;
                    rep = rep->right;
                }
                if (pre == root)
                    rep->right = root->right;
                else {
                    pre->right = rep->left;
                    rep->left = root->left;
                    rep->right = root->right;
                }
                return rep;
            } else if (root->right) {
                TreeNode *pre = root;
                TreeNode *rep = root->right;
                while (rep->left) {
                    pre = rep;
                    rep = rep->left;
                }
                if (pre == root)
                    rep->left = root->left;
                else {
                    pre->left = rep->right;
                    rep->right = root->right;
                    rep->left = root->left;
                }
                return rep;
            } else
                return nullptr;
        }
    }
};

int main()
{
    return 0;
}
