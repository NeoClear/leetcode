#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string meta_;
    uint64_t ptr_ = 0;
    uint64_t size_;
    // Encodes a tree to a single string.

    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        return to_string(root->val) + "," +
               serialize(root->left) + "," +
               serialize(root->right);
    }

    inline bool valid() { return ptr_ < size_; }

    int read_id() {
        string dat_;
        while (meta_[ptr_] >= '0' && meta_[ptr_] <= '9' && valid()) {
            dat_.push_back(meta_[ptr_]);
            ptr_++;
        }
        return std::stoi(dat_);
    }

    void read_null() {
        if (meta_[ptr_] == '#' && valid()) ptr_++;
    }

    void read_coma() {
        if (meta_[ptr_] == ',' && valid()) ptr_++;
    }

    bool is_null() {
        return meta_[ptr_] == '#';
    }

    TreeNode *read_node() {
        if (is_null()) {
            read_null();
            return NULL;
        }

        TreeNode *ret = new TreeNode(read_id());
        read_coma();
        ret->left = read_node();
        read_coma();
        ret->right = read_node();
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        meta_.swap(data);
        size_ = meta_.size();
        return read_node();
    }
};

int main()
{
    Codec ins;
    string in = "2,#,4,#,#";
    cout<< ins.serialize(ins.deserialize(in))<< endl;
    return 0;
}
