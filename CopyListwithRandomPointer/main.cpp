#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

unordered_map<Node *, Node *> map_;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        map_[NULL] = NULL;
        Node *ret = new Node(0, NULL, NULL);
        auto ptr = ret;
        auto p = head;
        while (p) {
            ptr->next = new Node(p->val, NULL, p->random);
            ptr = ptr->next;
            map_[p] = ptr;
            p = p->next;
        }
        auto q = ret->next;
        while (q) {
            q->random = map_[q->random];
            q = q->next;
        }
        return ret->next;
    }
};

int main()
{
    return 0;
}
