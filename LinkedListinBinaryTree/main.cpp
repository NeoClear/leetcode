#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> lst;
        while (head) {
            lst.push_back(head->val);
            head = head->next;
        }
        vector<int> tree;
        bool solved = false;
        auto match = [&]() {
            for (auto l = lst.rbegin(), t = tree.rbegin(); l != lst.rend(); l++, t++) {
                if (*l != *t)
                    return;
            }
            solved = true;
        };
        function<void(TreeNode*)> solve = [&](TreeNode* cur) {
            if (cur == NULL)
                return;
            if (solved)
                return;
            tree.push_back(cur->val);
            if (tree.size() >= lst.size())
                match();
            solve(cur->left);
            solve(cur->right);
            tree.pop_back();
        };
        solve(root);
        return solved;
    }
};

int main() {
    Solution ins;

    return 0;
}