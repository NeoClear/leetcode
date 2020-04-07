#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    int val;
    vector<int> stack;
    vector<int> minstack;
    MinStack() {
    }

    void push(int x) {
        stack.push_back(x);
        if (minstack.empty())
            minstack.push_back(x);
        else
            minstack.push_back(min(x, minstack.back()));
    }

    void pop() {
        stack.pop_back();
        minstack.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return minstack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
