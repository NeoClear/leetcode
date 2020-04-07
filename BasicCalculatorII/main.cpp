#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<char, int>> stack;
    int calculate(string s) {
        string num;
        s.push_back('@');
        for (const auto& c : s) {
            if (c == ' ')
                continue;
            if (isdigit(c))
                num.push_back(c);
            else {
                stack.push_back({'@', stoi(num)});
                if (c == '+')
                    stack.push_back({'+', 0});
                else if (c == '-')
                    stack.push_back({'-', 0});
                else if (c == '*')
                    stack.push_back({'*', 0});
                else if (c == '/')
                    stack.push_back({'/', 0});
                num.clear();
            }
        }
        vector<pair<char, int>> run;
        for (const auto& ele : stack) {
            run.push_back(ele);
            if (run.size() >= 3 && (run[run.size() - 2].first == '*' ||
                                    run[run.size() - 2].first == '/')) {
                if (run[run.size() - 2].first == '*') {
                    run[run.size() - 3].second *= run.back().second;
                    run.pop_back();
                    run.pop_back();
                } else {
                    run[run.size() - 3].second /= run.back().second;
                    run.pop_back();
                    run.pop_back();
                }
            }
        }
        vector<int> eval;
        char op = '@';
        for (const auto& it : run) {
            if (it.first == '@') {
                eval.push_back(it.second);
                if (op == '+')
                    eval.front() += eval.back();
                else if (op == '-')
                    eval.front() -= eval.back();
                else
                    continue;
                eval.pop_back();
                op = '@';
            } else
                op = it.first;
        }
        return eval.front();
    }
};

int main()
{
    Solution ins;
    cout<< ins.calculate("3/2")<< endl;
    return 0;
}
