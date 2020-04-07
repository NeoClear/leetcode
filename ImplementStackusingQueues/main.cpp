#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> back;
        while (!q.empty()) {
            back.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!back.empty()) {
            q.push(back.front());
            back.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto ret = q.front();
        q.pop();
        return ret;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

int main()
{
    return 0;
}
