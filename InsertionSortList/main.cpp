#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *ret;
    void insert(ListNode *root) {
        if (ret->next == NULL) {
            ret->next = root;
            root->next = NULL;
            return;
        }
        auto ptr = ret;
        while (ptr->next) {
            if (ptr->next->val >= root->val)
                break;
            ptr = ptr->next;
        }
        auto dest = ptr->next;
        ptr->next = root;
        root->next = dest;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode *cur = NULL, *dest = head;
        ret = new ListNode(INT_MIN);
        while (dest) {
            cur = dest;
            dest = dest->next;
            insert(cur);
        }
        return ret->next;
    }
};

int main()
{
    return 0;
}
