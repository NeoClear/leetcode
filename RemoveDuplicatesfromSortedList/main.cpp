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
        if (!head)
            return NULL;
        ListNode *ret = new ListNode(0);
        auto ptr = ret;
        auto p = head;
        while (p) {
            if (p->val != ptr->val || ptr == ret) {
                ptr->next = p;
                ptr = ptr->next;
            }
            p = p->next;
        }
        ptr->next = NULL;
        return ret->next;
    }
};

int main()
{
    return 0;
}
