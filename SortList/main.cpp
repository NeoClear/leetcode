#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *root) {
    while (root) {
        cout<< root->val<< " ";
        root = root->next;
    }
    cout<< endl;
}

class Solution {
public:
    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *ret = new ListNode(0);
        auto ptr = ret;
        while (a || b) {
            if (a == NULL) {
                ptr->next = b;
                b = b->next;
            } else if (b == NULL) {
                ptr->next = a;
                a = a->next;
            } else {
                if (a->val < b->val) {
                    ptr->next = a;
                    a = a->next;
                } else {
                    ptr->next = b;
                    b = b->next;
                }
            }
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return ret->next;
    }
    pair<ListNode *, ListNode *> split(ListNode *root) {
//        print(root);
        auto head = new ListNode(0);
        head->next = root;
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto right = slow->next;
        slow->next = NULL;
        return {root, right};
    }
    ListNode *sortIt(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        auto ret = split(head);
//        print(ret.first);
//        print(ret.second);
        auto ans = merge(sortIt(ret.first), sortIt(ret.second));
//        print(ret.first);
//        print(ret.second);
//        print(ans);
        return ans;
    }
    ListNode* sortList(ListNode* head) {
        return sortIt(head);
    }
};

ListNode *gen(vector<int> nums) {
    ListNode *ret = new ListNode(0);
    auto p = ret;
    for (const auto& it : nums) {
        p->next = new ListNode(it);
        p = p->next;
    }
    return ret->next;
}

int main()
{
    Solution ins;
    print(ins.sortList(gen({4, 2, 1, 3})));
    return 0;
}
