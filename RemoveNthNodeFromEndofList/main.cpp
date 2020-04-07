#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    pair<ListNode *, int> solve(ListNode *node, int& n) {
        if (node == NULL)
            return {NULL, 0};
        auto ret = solve(node->next, n);
        if (ret.second == n - 1) {
//            free(node);
            return {ret.first, ret.second + 1};
        }
        node->next = ret.first;
        return {node, ret.second + 1};
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return solve(head, n).first;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
