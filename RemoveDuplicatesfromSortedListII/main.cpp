#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // p q for the list itself
        // ptr for attachment to the list
        if (head == NULL)
            return head;
        auto p = head;
        auto q = p;
        ListNode *ret = new ListNode(0);
        auto ptr = ret;
        bool flag = true;
        while (p != NULL) {
            p = p->next;
            if (p != NULL && p->val == q->val) {
                flag = false;
            } else {
                if (flag) {
                    ptr->next = q;
                    ptr = ptr->next;
                    ptr->next = NULL;
                }
                flag = true;
            }

            q = p;
        }
        return ret->next;
    }
};

int main()
{
    return 0;
}
