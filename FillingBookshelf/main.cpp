#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> h_;
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        h_.clear();
        int size = books.size();
        h_ = vector<int>(size, INT_MAX);
        for (int id = 0; id < size; id++) {
            int h = 0;
            int w = 0;
            for (int j = id; j >= 0; j--) {
                w += books[j][0];
                if (w > shelf_width)
                    break;
                h = max(h, books[j][1]);
                h_[id] = min(h_[id], (j == 0 ? 0 : h_[j - 1]) + h);
            }
        }
        return h_[size - 1];
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> b = {
        {1, 1},
        {2, 3},
        {2, 3},
        {1, 1},
        {1, 1},
        {1, 1},
        {1, 2}
    };
    cout<< ins.minHeightShelves(b, 4)<< endl;
    return 0;
}
