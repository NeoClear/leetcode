#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        if (citations.front() == 0)
            return 0;
        for (int i = 1; i < citations.size(); i++) {
            if (citations[i - 1] >= i && citations[i] <= i)
                return i;
        }
        return citations.size();
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        3, 0, 6, 1, 5
    };
    cout<< ins.hIndex(in)<< endl;
    return 0;
}
