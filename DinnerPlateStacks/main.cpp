#include <bits/stdc++.h>

using namespace std;

class DinnerPlates {
public:
    int capacity_;
    vector<vector<int>> stacks;
    int leftInsert;
    DinnerPlates(int capacity): capacity_(capacity) {
        leftInsert = 0;
    }

    void push(int val) {
        if (stacks.size() <= leftInsert) {
            stacks.push_back({});
        }
        stacks[leftInsert].push_back(val);
        if (stacks[leftInsert].size() >= capacity_) {
            for (; leftInsert < stacks.size() && stacks[leftInsert].size() >= capacity_; leftInsert++) {}
//            while (leftInsert < stacks.size() && stacks[leftInsert].size() >= capacity_) {
//                leftInsert++;
//            }
        }
    }

    int pop() {
        if (stacks.empty())
            return -1;
        if (stacks.back().size() == capacity_ && leftInsert == stacks.size())
            leftInsert--;
        int ret = stacks.back().back();
        stacks.back().pop_back();
        if (stacks.back().empty())
            while (!stacks.empty() && stacks.back().empty())
                stacks.pop_back();

        return ret;
    }

    int popAtStack(int index) {
        if (index >= stacks.size() || stacks[index].empty())
            return -1;
        int ret = stacks[index].back();
        stacks[index].pop_back();
        if (index < leftInsert)
            leftInsert = index;
        if (index == stacks.size() - 1 && stacks.back().empty()) {
            while (!stacks.empty() && stacks.back().empty())
                stacks.pop_back();
        }
        return ret;
    }
};

int main()
{
    return 0;
}
