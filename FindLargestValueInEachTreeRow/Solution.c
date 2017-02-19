/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode* node) {
    if (node == NULL) return 0;
    int l = height(node->left);
    int r = height(node->right);
    return (l > r ? l + 1 : r + 1);
}

int min(struct TreeNode* node) {
    int res = node->val;
    if (node->left) {
        int l = min(node->left);
        res = res > l ? l : res;
    }
    if (node->right) {
        int r = min(node->right);
        res = res > r ? r : res;
    }
    return res;
}

void traverse(struct TreeNode* node, int layer, int* res) {
    if (node == NULL) return;
    if (res[layer] < node->val) {
        res[layer] = node->val;
    }
    traverse(node->left, layer + 1, res);
    traverse(node->right, layer + 1, res);
    return;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    *returnSize = height(root);
    int* res = (int*) malloc((*returnSize) * sizeof(int));
    if (0 == *returnSize) return res;
    int m = min(root);
    for (int i = 0; i < *returnSize; i++) {
        res[i] = m;
    }
    traverse(root, 0, res);
    return res;
}