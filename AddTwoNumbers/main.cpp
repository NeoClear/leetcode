#include <iostream>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = nullptr;
        ListNode *ptr = ret;
        int inc = 0;
        while (l1 != nullptr || l2 != nullptr || inc != 0) {
            if (ret == nullptr) {
                ret = new ListNode(0);
                ret->next = nullptr;
                ptr = ret;
            } else {
                ptr->next = new ListNode(0);
                ptr = ptr->next;
                ptr->next = nullptr;
            }

            if (l1 != nullptr) {
                if (l2 != nullptr) {
                    ptr->val = l1->val + l2->val + inc;
                } else {
                    ptr->val = l1->val + inc;
                }
            } else {
                if (l2 != nullptr) {
                    ptr->val = l2->val + inc;
                } else {
                    ptr->val = inc;
                }
            }
            inc = 0;
            if (ptr->val > 9) {
                ptr->val -= 10;
                inc++;
            }
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return ret;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
