#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> isChild;
        for (const auto& it : leftChild) {
            if (it == -1)
                continue;
            if (isChild.count(it))
                return false;
            isChild.insert(it);
        }
        for (const auto& it : rightChild) {
            if (it == -1)
                continue;
            if (isChild.count(it))
                return false;
            isChild.insert(it);
        }
        return isChild.size() == n - 1;
    }
};

int main() {
    Solution ins;
    vector<int> left = {
        1,-1,-1,4,-1,-1
    }, right = {
        2,-1,-1,5,-1,-1
    };
    if (ins.validateBinaryTreeNodes(6, left, right))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}