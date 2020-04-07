#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto ret = new ListNode(0);
        auto p = ret;
        while (head) {
            if (head->val != val) {
                p->next = head;
                p = p->next;
            }
            head = head->next;
        }
        p->next = NULL;
        return ret->next;
    }
};

int main()
{
    return 0;
}
