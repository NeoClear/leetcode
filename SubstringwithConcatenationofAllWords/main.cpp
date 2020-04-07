#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N;
    unordered_map<string, int> map_;
    map<int, string> hash_;
    vector<int> findSubstring(string s, vector<string> words) {
        if (words.empty()) return {};
        N = words[0].length();
        if (s.length() < N) return {};
        for (const auto& w : words)
            map_[w]++;
        for (int i = 0; i < s.size() - N + 1; i++) {
            if (map_.count(s.substr(i, N)))
                hash_[i] = s.substr(i, N);
        }
        vector<int> ans;
        for (int i = 0; i < s.size() - words.size() * N + 1; i++) {
            unordered_map<string, int> count_;
            bool flag = true;
            for (int j = i; j <= i + (words.size() - 1) * N; j += N) {
                if (!hash_.count(j)) {
                    flag = false;
                    break;
                }
                count_[hash_[j]]++;
                if (count_[hash_[j]] > map_[hash_[j]]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    for (const auto& i : ins.findSubstring("wordgoodgoodgoodbestword", {"word", "good", "best", "word"}))
        cout<< i<< endl;
    return 0;
}
