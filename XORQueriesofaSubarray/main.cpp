#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> value = vector<int>(arr.size());
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            value[i] = (i == 0 ? 0 : value[i - 1]) ^ arr[i];
        }
        for (const auto& it : queries) {
            int l = it[0];
            int r = it[1];
            int cur = value[r] ^ (l == 0 ? 0 : value[l - 1]);
            ans.push_back(cur);
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {
        {0, 1},
        {1, 2},
        {0, 3},
        {3, 3}
    };
    Solution ins;
    for (const auto& it : ins.xorQueries(arr, queries))
        cout << it << endl;
    return 0;
}