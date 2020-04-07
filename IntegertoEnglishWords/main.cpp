#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> block;
    vector<string> zone;
    vector<string> analyze(int fra) {
        vector<string> ans;
        int h = fra / 100;
        if (h != 0) {
            ans.push_back(block[0][h - 1]);
            ans.push_back(block[2].front());
        }
        int t = (fra / 10) % 10;
        if (t != 0) {
            if (t == 1) {
                ans.push_back(block[0][fra % 100 - 1]);
                return ans;
            } else {
                ans.push_back(block[1][t - 2]);
            }
        }
        int o = fra % 10;
        if (o != 0) {
            ans.push_back(block[0][o - 1]);
        }
        return ans;
    }
    vector<int> split(int num) {
        vector<int> ans;
        while (num) {
            ans.push_back(num % 1000);
            num /= 1000;
        }
        return ans;
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        block = {
            {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"},
            {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"},
            {"Hundred"}
        };
        zone = {"Thousand", "Million", "Billion"};
        auto ret = split(num);
        vector<string> ans;
        for (int i = ret.size() - 1; i >= 0; i--) {
            auto meta = analyze(ret[i]);
            for (const auto& it : meta)
                ans.push_back(it);
            if (i != 0 && ret[i] != 0)
                ans.push_back(zone[i - 1]);
        }
        string ans_;
        for (const auto& it : ans) {
            if (!ans_.empty())
                ans_.push_back(' ');
            ans_ += it;
        }
        return ans_;
    }
};

int main()
{
    Solution ins;
    cout<< ins.numberToWords(1000000)<< endl;
    return 0;
}
