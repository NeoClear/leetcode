#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};
        for (int i = 1; i <= rowIndex; i++) {
            int pre = ans.front();
            for (int j = 1; j < ans.size(); j++) {
                ans[j] += pre;
                pre = ans[j] - pre;
            }
            ans.push_back(1);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
