#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode *ptr = head->next;
        head->next = swapPairs(ptr->next);
        ptr->next = head;
        return ptr;
    }
};

int main()
{
    return 0;
}
