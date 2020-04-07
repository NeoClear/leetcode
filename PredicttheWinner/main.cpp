#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N;
    int total;
    vector<int> *G;
    bool solve(int player, int score0, int score1, int s, int e) {
        if (player == 0) {
            if (score0 >= (total + 1) / 2) return true;
            if (s > e) return false;
            if (!solve(1, score0 + (*G)[s], score1, s + 1, e) || !solve(1, score0 + (*G)[e], score1, s, e - 1)) return true;
            return false;
        } else if (player == 1) {
            if (score1 > total / 2) return true;
            if (s > e) return false;
            if (!solve(0, score0, score1 + (*G)[s], s + 1, e) || !solve(0, score0, score1 + (*G)[e], s, e - 1)) return true;
            return false;
        }
        return false;
    }
    bool PredictTheWinner(vector<int>& nums) {
        N = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);
        G = &nums;
        return solve(0, 0, 0, 0, N - 1);
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        1, 5, 2
    };
    if (ins.PredictTheWinner(in)) cout<< "True"<< endl;
    else cout<< "False"<< endl;

//    deque<int> test_ = {2};
//    if (ins.solve(0, 1, 5, test_)) cout<< "True"<< endl;
//    else cout<< "False"<< endl;

    return 0;
}
