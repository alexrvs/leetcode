class SegmentTreeNode {
public:
    int start;
    int end;
    int sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
};

class NumArray {
private:
    SegmentTreeNode* root;

    SegmentTreeNode* buildSegmentTree(vector<int> &nums, int i, int j) {
        SegmentTreeNode* node = new SegmentTreeNode();
        node->start = i;
        node->end = j;
        if (i == j) {
            node->sum = nums[i];
            node->left = NULL;
            node->right = NULL;
        } else {
            int m = i + (j - i) / 2;
            node->left = buildSegmentTree(nums, i, m);
            node->right = buildSegmentTree(nums, m + 1, j);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

    void updateTree(SegmentTreeNode* node, int i, int val) {
        if (i < node->start || i > node->end) return;
        if (node->start == node->end && node->start == i) {
            node->sum = val;
        } else {
            updateTree(node->left, i, val);
            updateTree(node->right, i, val);
            node->sum = node->left->sum + node->right->sum;
        }
    }

    int queryTree(SegmentTreeNode* node, int i, int j) {
        if (i > j) return queryTree(node, j, i);
        if (node->start == i && node->end == j) return node->sum;
        int m = node->start + (node->end - node->start) / 2;
        if (m + 1 <= i) return queryTree(node->right, i, j);
        if (j <= m) return queryTree(node->left, i, j);
        return queryTree(node->left, i, m) + queryTree(node->right, m + 1, j);
    }

public:
    NumArray(vector<int> &nums) {
        if (nums.size() == 0) {
            root = NULL;
            return;
        }
        root = buildSegmentTree(nums, 0, nums.size() - 1);
    }


    void update(int i, int val) {
        if (root != NULL) updateTree(root, i, val);
    }

    int sumRange(int i, int j) {
        if (root != NULL) return queryTree(root, i, j);
        return 0;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
