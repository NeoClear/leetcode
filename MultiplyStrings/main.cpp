#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> toInt(string s) {
        auto ret = vector<int>();
        for (auto it = s.rbegin(); it != s.rend(); it++)
            ret.push_back(*it - '0');
        return ret;
    }
    vector<int> multi(vector<int>& n1, vector<int>& n2) {
        auto ret = vector<int>();
        for (uint64_t i = 0; i < n1.size(); i++) {
            for (uint64_t j = 0; j < n2.size(); j++) {
                if (i + j >= ret.size())
                    ret.push_back(0);
                ret[i + j] += n1[i] * n2[j];
                if (ret[i + j] >= 10) {
                    if (i + j + 1 >= ret.size())
                        ret.push_back(0);
                    ret[i + j + 1] += ret[i + j] / 10;
                    ret[i + j] %= 10;
                }
            }
        }
        return ret;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        auto n1 = toInt(num1);
        auto n2 = toInt(num2);
        auto ret = multi(n1, n2);
        string res;
        for (auto it = ret.rbegin(); it != ret.rend(); it++)
            res.push_back(*it + '0');
        return res;
    }
};

int main()
{
    Solution ins;
    cout<< ins.multiply("999", "999")<< endl;
    return 0;
}
