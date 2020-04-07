#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    multiset<int> set_;
    set<int>::iterator iter;
    bool init = true;
    MedianFinder() {
        iter = set_.begin();
    }
    void addNum(int num) {
        set_.insert(num);
        if (init) {
            init = false;
            iter = set_.begin();
            return;
        }
        if (set_.size() & 0x1) {
            if (num >= *iter)
                iter = next(iter);
        } else {
            if (num < *iter)
                iter = prev(iter);
        }
    }

    double findMedian() {
        if (set_.size() & 0x1) {
            return static_cast<double>(*iter);
        } else {
            return static_cast<double>(*iter + *next(iter)) / 2;
        }
    }
};

int main()
{
    MedianFinder ins;
    ins.addNum(-1);
    cout<< ins.findMedian()<< endl;
    ins.addNum(-2);
    cout<< ins.findMedian()<< endl;
    ins.addNum(6);
    cout<< ins.findMedian()<< endl;
    return 0;
}
