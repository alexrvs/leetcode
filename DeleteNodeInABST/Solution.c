/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    struct TreeNode* toDel = root;
    struct TreeNode* prev = NULL;
    struct TreeNode* pred = NULL;
    while (NULL != toDel && toDel->val != key) {
        prev = toDel;
        if (key < toDel->val) {
            toDel = toDel->left;
        } else {
            toDel = toDel->right;
        }
    }
    if (NULL == toDel) return root;
    if (NULL == toDel->left) {
        if (NULL == prev) {
            root = toDel->right;
        } else {
            if (toDel->val < prev->val) {
                prev->left = toDel->right;
            } else {
                prev->right = toDel->right;
            }
        }
    } else {
        if (NULL == prev) {
            root = toDel->left;
        } else {
            if (toDel->val < prev->val) {
                prev->left = toDel->left;
            } else {
                prev->right = toDel->left;
            }
        }
        pred = toDel->left;
        while (NULL != pred->right) {
            pred = pred->right;
        }
        pred->right = toDel->right;
    }
    free(toDel);
    return root;
}