#include <bits/stdc++.h>

using namespace std;

class RangeModule {
public:
    map<int, int> map_;
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = map_.upper_bound(left);
        if (it != map_.begin()) {
            auto it2 = prev(it);
            if (it2->second >= left) it = it2;
        }
        vector<pair<int, int>> fix_;
        int left_ = left, right_ = right;
        while (it != map_.end() && it->first <= right) {
            if (it->first < left) left_ = it->first;
            if (it->second > right) right_ = it->second;
            it = map_.erase(it);
        }
        map_[left_] = right_;
//        for (const auto& it : fix_) {
//            map_[it.first] = it.second;
//        }
    }

    bool queryRange(int left, int right) {
        auto it = map_.upper_bound(left);
        if (it != map_.begin()) {
            it = prev(it);
        }
        if (it == map_.end() || it->second < right || it->first > left) return false;
        return true;
    }

    void removeRange(int left, int right) {
        auto it = map_.upper_bound(left);
        if (it != map_.begin()) {
            auto it2 = prev(it);
            if (it2->second > left) it = it2;
        }
        vector<pair<int, int>> fix_;
        while (it != map_.end() && it->first < right) {
            if (it->first < left) fix_.emplace_back(it->first, left);
            if (it->second > right) fix_.emplace_back(right, it->second);
            it = map_.erase(it);
        }
        for (const auto& it : fix_) { map_[it.first] = it.second; }
    }
    void display() {
        for (const auto& it : map_) cout<< "["<< it.first<< ", "<< it.second<< "]"<< endl;
    }
};

int main()
{
    RangeModule ins;
    ins.addRange(6, 8);
    ins.removeRange(7, 8);
    ins.removeRange(8, 9);
    ins.addRange(8, 9);
    ins.addRange(7, 8);
    ins.display();
    if (ins.queryRange(3, 4))
        cout<< "True"<< endl;
    else
        cout<< "False"<< endl;
    return 0;
}
