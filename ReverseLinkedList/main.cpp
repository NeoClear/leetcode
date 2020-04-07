#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        vector<ListNode *> stack;
        while (head) {
            stack.push_back(head);
            head = head->next;
        }
        for (int i = stack.size() - 1; i >= 0; i--) {
            stack[i]->next = i == 0 ? NULL : stack[i - 1];
        }
        return stack.back();
    }
};

int main()
{
    return 0;
}
