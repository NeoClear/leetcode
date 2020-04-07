#include <bits/stdc++.h>

using namespace std;

class Leaderboard {
public:
    unordered_map<int, multiset<int, std::greater<int>>::iterator> board;
    multiset<int, std::greater<int>> scores;

    Leaderboard() {

    }

    void addScore(int playerId, int score) {
        if (!board.count(playerId)) {
            board[playerId] = scores.insert(0);
        }
        auto old = board[playerId];
        board[playerId] = scores.insert(*old + score);
        scores.erase(old);
    }

    int top(int K) {
        int cnt = 0;
        for (auto it = scores.begin(); it != scores.end(), K--; it++, K)
            cnt += *it;
        return cnt;
    }

    void reset(int playerId) {
        auto old = board[playerId];
        board[playerId] = scores.insert(0);
        scores.erase(old);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

int main() {
}
