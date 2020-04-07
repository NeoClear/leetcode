#include <bits/stdc++.h>

using namespace std;

//struct Node {
//    int left;
//    int right;
//    int val;
//    Node(): val(0) {}
//};

//class segTree {
//    static constexpr int inf = 1000000000;
//    vector<Node> meta_;
//    segTree() {
//        meta_ = vector<Node>(inf * 4);
//    }
//    void build(int left, int right, int id) {
//        meta_[id].left = left;
//        meta_[id].right = right;
//        meta_[id].val = 0;
//        if (left == right)
//            return;
//        int mid = (left + right) / 2;
//        build(left, mid, id * 2);
//        build(mid + 1, right, id * 2 + 1);
//    }
//    void update(int left, int right, int id) {
//        if (meta_[id].left == left &&
//            meta_[id].right == right)
//            meta_[id].val
//    }
//};

class MyCalendarThree {
public:
    map<int, int> delta_;
    MyCalendarThree() {
    }

    int book(int start, int end) {
        delta_[start]++;
        delta_[end]--;
        int count = 0;
        int ans = 0;
        for (const auto& kv : delta_)
            ans = max(ans, count += kv.second);
        return ans;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
