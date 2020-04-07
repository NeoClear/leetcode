#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> q;
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while (!q.empty()) {
            temp.push(q.top());
            q.pop();
        }
        q.push(x);
        while (!temp.empty()) {
            q.push(temp.top());
            temp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = q.top();
        q.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        return q.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty();
    }
};

int main()
{
    return 0;
}
