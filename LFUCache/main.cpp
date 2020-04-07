#include <bits/stdc++.h>

using namespace std;

struct CacheNode {
    int key;
    int value;
    int freq;
    uint64_t tms;
    CacheNode(int k, int v):
        key(k),
        value(v),
        freq(0),
        tms(0) {}
    bool operator <(const CacheNode& o) const {
        if (freq == o.freq) return tms < o.tms;
        return freq < o.freq;
    }
};

class LFUCache {
public:
    int capacity_;
    unordered_map<int, CacheNode> map_;
    set<CacheNode> cache_;
    uint64_t tms_;
    LFUCache(int capacity):
        capacity_(capacity),
        tms_(0) {}
    void update(CacheNode& n) {
        n.freq++;
        n.tms = tms_++;
    }
    int get(int key) {
        auto it = map_.find(key);
        if (it == map_.end()) return -1;
        cache_.erase(it->second);
        update(it->second);
        cache_.insert(it->second);
        return it->second.value;
    }

    void put(int key, int value) {
        if (capacity_ == 0) return;
        auto it = map_.find(key);
        if (it != map_.end()) {
            cache_.erase(it->second);
            update(it->second);
            it->second.value = value;
            cache_.insert(it->second);
            return;
        }

        if (map_.size() >= capacity_) {
            map_.erase(cache_.begin()->key);
            cache_.erase(cache_.begin());
        }
        CacheNode n_(key, value);
        update(n_);
        map_.insert({key, n_});
        cache_.insert(n_);
    }
};

int main()
{
    return 0;
}
