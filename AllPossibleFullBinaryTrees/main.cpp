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
    vector<TreeNode*> allPossibleFBT(int N) {
        if ((N & 1) == 0) return {};
        if (N == 1) return {new TreeNode(NULL)};
        vector<TreeNode *> ans;
        for (int i = 1; i < N; i += 2) {
            for (auto l : allPossibleFBT(i)) {
                for (auto r : allPossibleFBT(N - i - 1)) {
                    auto root = new TreeNode(NULL);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
