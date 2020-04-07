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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        return to_string(root->val) + "," +
                serialize(root->left) + "," +
                serialize(root->right);
    }

    // Decodes your encoded data to tree.
    string meta_;
    int N;
    int ptr_ = 0;
    bool valid() { return ptr_ < N; }
    void read_null() {
        if (meta_[ptr_] == '#' && valid()) ptr_++;
    }
    void read_comma() {
        if (meta_[ptr_] == ',' && valid()) ptr_++;
    }
    int read_id() {
        string res;
        while (((meta_[ptr_] >= '0' && meta_[ptr_] <= '9') || meta_[ptr_] == '-') && valid()) {
            res.push_back(meta_[ptr_]);
            ptr_++;
        }
        cout<< res<< endl;
        return std::stoi(res);
    }
    TreeNode *readNode() {
        if (meta_[ptr_] == '#' && valid()) {
            read_null();
            return NULL;
        }
        TreeNode *ret = new TreeNode(read_id());
        read_comma();
        ret->left = readNode();
        read_comma();
        ret->right = readNode();
        return ret;
    }
    TreeNode* deserialize(string data) {
        meta_.swap(data);
        N = meta_.size();
        return readNode();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    Codec ins;
    cout<< ins.serialize(ins.deserialize("-1,0,#,#,1,#,#"))<< endl;
    return 0;
}
