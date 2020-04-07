#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    pair<vector<char>, char> less;
    unordered_set<char> left;
    bool same = false;
    int convert(string w, unordered_map<char, int>& kv) {
        int ans = 0;
        for (const auto& it : w)
            ans = ans * 10 + kv[it];
        return ans;
    }
    // bool inside(int step, char ch, vector<char>& attempt) {
    //     for (int i = 0; i < step; i++)
    //         if (attempt[i] == ch)
    //             return true;
    //     return false;
    // }
    bool solve(int step, vector<char>& attempt, unordered_set<int>& used, unordered_map<char, int>& kv, unordered_map<char, pair<int, int>>& use, vector<string>& words, string result) {
        ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
        if (step == attempt.size()) {
            int ans = 0;
            for (const auto& w : words)
                ans += convert(w, kv);
            return ans == convert(result, kv);
        }
        char cur = attempt[step];

        int start = use[cur].first, end = use[cur].second;
        // if (same) {
        //     if (left.count(cur)) {
        //         if (inside(step, result.front(), attempt)) {
        //             end = min(end, kv[result.front()]);
        //         }
        //     }
        //     if (result.front() == cur) {
        //         for (const auto& it : left)
        //             if (inside(step, it , attempt))
        //                 start = max(start, kv[it]);
        //     }
        // }

        for (int i = start; i <= end; i++) {
            if (used.count(i))
                continue;
            used.insert(i);
            kv[cur] = i;
            if (solve(step + 1, attempt, used, kv, use, words, result))
                return true;
            kv.erase(cur);
            used.erase(i);
        }
        return false;
    }

    bool isSolvable(vector<string>& words, string result) {
        unordered_map<char, pair<int, int>> use;
        vector<char> attempt;
        unordered_map<char, int> kv;

        int low = 0;
        for (const auto& word: words) {
            if (word.length() > result.length())
                return false;
            if (word.length() == result.length()) {
                less.first.push_back(word.front());
                left.insert(word.front());
                same = true;
            }
            if (word.length() == result.length() - 1)
                low++;
            for (const auto& ch : word)
                use[ch] = {0, 9};
            use[word.front()] = {1, 9};
        }
        for (const auto& ch : result)
            use[ch] = {0, 9};
        use[result.front()] = {1, 9};

        if (!same) { use[result.front()].second = low; }
        else { less.second = result.front(); }
        if (use[result.front()].second == 0) { return false; }
        for (auto [k, v] : use)
            attempt.push_back(k);
        unordered_set<int> used;
        return solve(0, attempt, used, kv, use, words, result);
    }
};

int main() {
    vector<string> words = {"THIS","IS","TOO"};
    string result = "FUNNY";
    Solution ins;
    if (ins.isSolvable(words, result))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}