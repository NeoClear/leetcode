#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return {};
        vector<vector<int>> ans = {{1}};
        for (int i = 2; i <= numRows; i++) {
            vector<int> cur;
            cur.push_back(1);
            for (int j = 0; j < ans.back().size() - 1; j++)
                cur.push_back(ans.back()[j] + ans.back()[j + 1]);
            cur.push_back(1);
            ans.push_back(cur);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
