#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = false;
        for (const auto& digit : digits)
            if (digit != 9) {
                flag = true;
                break;
            }
        if (!flag) {
            vector<int> ret = vector<int>(digits.size() + 1, 0);
            ret.front() = 1;
            return ret;
        }
        for (auto it = digits.rbegin(); it != digits.rend(); it++) {
            if ((*it) + 1 >= 10) {
                (*it) = 0;
            } else {
                (*it)++;
                break;
            }
        }
        return digits;
    }
};

int main()
{
    return 0;
}
