#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> ans;
        // id, rating, veg, price, dis
        for (const auto& it : restaurants) {
            int id = it[0];
            int rating = it[1];
            int veg = it[2];
            int price = it[3];
            int dis = it[4];
            if (price > maxPrice || dis > maxDistance) { continue; }
            if (veganFriendly == 1 && veg == 0) { continue; }
            ans.push_back({id, rating});
        }
        sort(ans.begin(), ans.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        });
        vector<int> ret;
        for (const auto& it : ans) { ret.push_back(it.first); }
        return ret;
    }
};

int main() {
    return 0;
}