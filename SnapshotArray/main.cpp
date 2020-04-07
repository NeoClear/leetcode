#include <bits/stdc++.h>

using namespace std;

class SnapshotArray {
public:
    unordered_map<int, map<int, int>> meta_;
    int snapid = 0;
    SnapshotArray(int length) {}

    void set(int index, int val) {
        meta_[index][snapid] = val;
    }

    int snap() {
        snapid++;
        return snapid - 1;
    }

    int get(int index, int snap_id) {
        auto p = meta_[index].upper_bound(snap_id);
        return p == meta_[index].begin() ? 0 : prev(p)->second;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
