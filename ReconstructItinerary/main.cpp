#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, deque<string>> map_;
    vector<string> ans_;
    void solve(string port) {
        auto& dests = map_[port];
        while (!dests.empty()) {
            auto dest = dests.front();
            dests.pop_front();
            solve(dest);
        }
        ans_.push_back(port);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& ticket : tickets)
            map_[ticket[0]].push_back(ticket[1]);
        for (auto& port : map_)
            sort(port.second.begin(), port.second.end());
        solve("JFK");
        return vector<string>(ans_.crbegin(), ans_.crend());
    }
};

int main()
{
    vector<vector<string>> in = {
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    Solution ins;
    for (const auto& it : ins.findItinerary(in)) cout<< it<< endl;
    return 0;
}
