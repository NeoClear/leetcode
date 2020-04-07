#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end(), [](auto& a, auto& b) {
            return a > b;
        });
        if (digits.front() == 0)
            return "0";
        vector<int> rem0, rem1, rem2;
        for (const auto& it : digits) {
            if (it % 3 == 0)
                rem0.push_back(it);
            else if (it % 3 == 1)
                rem1.push_back(it);
            else
                rem2.push_back(it);
        }
        string ans;
        for (const auto& it : rem0)
            ans.push_back(it + '0');
        if (rem1.size() > rem2.size())
            rem1.swap(rem2);
        if ((rem2.size() - rem1.size()) % 3 == 1)
            rem2.pop_back();
        else if ((rem2.size() - rem1.size()) % 3 == 2) {
            if (!rem1.empty())
                rem1.pop_back();
            else {
                rem2.pop_back();
                rem2.pop_back();
            }
        }
        for (const auto& it : rem1) {
            ans.push_back(it + '0');
        }
        for (const auto& it : rem2) {
            ans.push_back(it + '0');
        }
        sort(ans.begin(), ans.end(), [](auto& a, auto& b) {
            return a > b;
        });
        if (!ans.empty() && ans.front() == '0')
            return "0";
        return ans;
    }
};

int main() {
    vector<int> in = {
        0,0,0,0,0,0,2,1
    };
    Solution ins;
    cout << ins.largestMultipleOfThree(in) << endl;
    return 0;
}