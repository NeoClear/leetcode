#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> map_;
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        auto it = map_.find(key);
        if (it == map_.end()) return -1;
//        int ret = it->second->second;
        cache_.splice(cache_.begin(), cache_, it->second);
        return cache_.begin()->second;
    }

    void put(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            cache_.splice(cache_.begin(), cache_, it->second);
            cache_.begin()->second = value;
        } else {
            if (cache_.size() >= capacity_) {
                map_.erase(cache_.back().first);
                cache_.pop_back();
            }
            cache_.push_front({key, value});
            map_[key] = cache_.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache ins(1);
    ins.put(2, 1);
    cout<< ins.get(2)<< endl;
    ins.put(3, 2);
    cout<< ins.get(2)<< endl;
    ins.get(3);
    cout<< 2333<< endl;
    return 0;
}
