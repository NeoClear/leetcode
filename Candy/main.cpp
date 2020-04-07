#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> count;
    int solve(int id, vector<int>& rating) {
        if (count[id])
            return count[id];
//        if (id < 0 || id >= rating.size())
//            return 0;
        int left = id == 0 ? 0 : (rating[id - 1] >= rating[id] ? 0 : solve(id - 1, rating));
        int right = id == rating.size() - 1 ? 0 : (rating[id + 1] >= rating[id] ? 0 : solve(id + 1, rating));
        return count[id] = max(left, right) + 1;
    }
    int candy(vector<int>& ratings) {
        count = vector<int>(ratings.size(), 0);
        for (int i = 0; i < ratings.size(); i++)
            if (count[i] == 0)
                solve(i, ratings);
        return accumulate(count.begin(), count.end(), 0);
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        1, 2, 2
    };
    cout<< ins.candy(in)<< endl;
    return 0;
}
