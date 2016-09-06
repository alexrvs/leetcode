struct SegmentTreeNode {
    int start;
    int end;
    int sum;
    struct SegmentTreeNode* left;
    struct SegmentTreeNode* right;
};

struct NumArray {
    struct SegmentTreeNode* root;
};

struct SegmentTreeNode* buildSegmentTree(int* nums, int i, int j) {
    struct SegmentTreeNode* node = (struct SegmentTreeNode*) malloc(sizeof(struct SegmentTreeNode));
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

void updateTree(struct SegmentTreeNode* node, int i, int val) {
    if (node->start > i || node->end < i) return;
    if (node->start == node->end && node->start == i) node->sum = val;
    else {
        int m = node->start + (node->end - node->start) / 2;
        updateTree(node->left, i, val);
        updateTree(node->right, i, val);
        node->sum = node->left->sum + node->right->sum;
    }
}

int queryTree(struct SegmentTreeNode* node, int i, int j) {
    if (node->start == i && node->end == j) return node->sum;
    int m = node->start + (node->end - node->start) / 2;
    if (j <= m) return queryTree(node->left, i, j);
    if (m + 1 <= i) return queryTree(node->right, i, j);
    return queryTree(node->left, i, m) + queryTree(node->right, m + 1, j);
}

void SegmentTreeFree(struct SegmentTreeNode* node) {
    if (node != NULL) {
        SegmentTreeFree(node->left);
        SegmentTreeFree(node->right);
        free(node);
    }
}

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray* numArray = (struct NumArray*) malloc(sizeof(struct NumArray));
    numArray->root = NULL;
    if (numsSize != 0) {
        numArray->root = buildSegmentTree(nums, 0, numsSize - 1);
    }
    return numArray;
}

void update(struct NumArray* numArray, int i, int val) {
    if (numArray->root != NULL) updateTree(numArray->root, i, val);
}

int sumRange(struct NumArray* numArray, int i, int j) {
    if (numArray->root != NULL) return queryTree(numArray->root, i, j);
    return 0;
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    SegmentTreeFree(numArray->root);
    free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// update(numArray, 1, 10);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
