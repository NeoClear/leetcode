#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class TweetCounts {
private:
    unordered_map<string, multiset<int>> tweet;
public:
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        tweet[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval;
        if (freq == "minute")
            interval = 60;
        else if (freq == "hour")
            interval = 3600;
        else
            interval = 3600 * 24;
        if (!tweet.count(tweetName)) { return {}; }
        vector<int> time;
        for (auto it = tweet[tweetName].lower_bound(startTime); it != tweet[tweetName].end() && *it <= endTime; it++)
            time.push_back(*it);
        vector<int> ans;
        int id = 0;
        for (int begin = startTime; begin <= endTime; begin += interval) {
            int cnt = 0;
            while (id < time.size() && time[id] < min(begin + interval, endTime + 1)) {
                cnt++;
                id++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

int main() {
    TweetCounts* tweetCounts = new TweetCounts();
    tweetCounts->recordTweet("tweet3", 0);
    tweetCounts->recordTweet("tweet3", 60);
    tweetCounts->recordTweet("tweet3", 10);                             
    for (const auto& it : tweetCounts->getTweetCountsPerFrequency("minute", "tweet3", 0, 59))
        cout << it << ", ";
    cout << endl;
    for (const auto& it : tweetCounts->getTweetCountsPerFrequency("minute", "tweet3", 0, 60))
        cout << it << ", ";
    cout << endl;
    tweetCounts->recordTweet("tweet3", 120);                           
    for (const auto& it : tweetCounts->getTweetCountsPerFrequency("hour", "tweet3", 0, 210))
        cout << it << ", ";
    cout << endl;
    return 0;
}

