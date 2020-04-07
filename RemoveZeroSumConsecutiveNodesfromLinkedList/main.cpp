#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> stack;
    void solve() {
        int top = stack.size() - 1;
        int acc = 0;
        int flag = -1;
        for (int i = top; i >= 0; i--) {
            acc += stack[i];
            if (acc == 0) {
                flag = i;
            }
        }
        if (flag >= 0) {
            while (stack.size() > flag)
                stack.pop_back();
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        while (head) {
            stack.push_back(head->val);
            solve();
            head = head->next;
        }
        ListNode *ret = new ListNode(0);
        auto ptr = ret;
        for (const auto& it : stack) {
            ptr->next = new ListNode(it);
            ptr = ptr->next;
        }
        return ret->next;
    }
};

ListNode *gen(vector<int> nums) {
    ListNode *ret = new ListNode(0);
    auto ptr = ret;
    for (const auto& it : nums) {
        ptr->next = new ListNode(it);
        ptr = ptr->next;
    }
    return ret->next;
}

void print(ListNode *head) {
    while (head) {
        cout<< head->val<< " ";
        head = head->next;
    }
    cout<< endl;
}

int main()
{
    Solution ins;
    auto cur = ins.removeZeroSumSublists(gen({1, 2, -3, 3, 1}));
    print(cur);
    return 0;
}
