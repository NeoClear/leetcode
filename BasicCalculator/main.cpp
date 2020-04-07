#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string meta;
    uint64_t ptr = 0;
    bool readlparen() {
        if (meta[ptr] == '(') {
            ptr++;
            return true;
        }
        return false;
    }
    bool readrparen() {
        if (meta[ptr] == ')') {
            ptr++;
            return true;
        }
        return false;
    }
    bool readplus() {
        if (meta[ptr] != '+')
            return false;
        ptr++;
        return true;
    }
    bool readminus() {
        if (meta[ptr] != '-')
            return false;
        ptr++;
        return true;
    }
    bool readNumber(int& ref) {
        if (!isdigit(meta[ptr]))
            return false;
        ref = 0;
        while (isdigit(meta[ptr])) {
            ref = ref * 10 - '0' + meta[ptr];
            ptr++;
        }
        return true;
    }

//    void readblank() {
//        while (ptr < meta.size() && meta[ptr] == ' ')
//            ptr++;
//    }
    int eval() {
        int ans = 0;
        if (readNumber(ans))
            return ans;
        readlparen();
        ans = eval();
        while (meta[ptr] != ')' && ptr < meta.size()) {
            if (readplus())
                ans += eval();
            else if (readminus())
                ans -= eval();
        }
        if (ptr != meta.size())
            readrparen();
        return ans;
    }
    int calculate(string s) {
        meta.push_back('(');
        for (const auto& c : s)
            if (c != ' ')
                meta.push_back(c);
        meta.push_back(')');
        return eval();
    }
};

int main()
{
    Solution ins;
    cout<< ins.calculate("1 + 2")<< endl;
    return 0;
}
