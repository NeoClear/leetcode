#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        while (l1) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        vector<int> ans;
        int remain = 0;
        for (int i = 0; i < v1.size() || i < v2.size() || remain; i++) {
            int a1 = i < v1.size() ? v1[i] : 0;
            int a2 = i < v2.size() ? v2[i] : 0;
            ans.push_back(a1 + a2 + remain);
            remain = ans.back() / 10;
            ans.back() %= 10;
        }
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        for (auto it = ans.rbegin(); it != ans.rend(); it++) {
            ptr->next = new ListNode(*it);
            ptr = ptr->next;
        }
        return head->next;
    }
};

int main() {
    return 0;
}