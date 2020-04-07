#include <bits/stdc++.h>

using namespace std;

class WordFilter {
public:
    unordered_map<string, unordered_map<string, int>> map_;
    vector<string> genPre(string s) {
        vector<string> ans;
        int N = s.size();
        for (int i = 0; i <= N; i++)
            ans.push_back(s.substr(0, i));
        return ans;
    }
    vector<string> genSuf(string s) {
        vector<string> ans;
        int N = s.size();
        for (int i = 0; i <= N; i++)
            ans.push_back(s.substr(i, N - i));
        return ans;
    }
    WordFilter(vector<string>& words) {
        int id = 1;
        for (const auto& it : words) {
            for (const auto& pre : genPre(it)) {
                for (const auto& suf : genSuf(it)) {
                    map_[pre][suf] = id;
                }
            }
            id++;
        }
    }

    int f(string prefix, string suffix) {
        int query = map_[prefix][suffix];
        if (query)
            return query - 1;
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

int main()
{
    vector<string> in = {
        "apple",
        "peach",
        "inno"
    };
    WordFilter ins(in);
    cout<< ins.f("p", "a")<< endl;
    return 0;
}
