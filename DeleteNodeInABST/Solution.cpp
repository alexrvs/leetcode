/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* toDel = root;
        TreeNode* prev = NULL;
        TreeNode* pred = NULL;
        while (NULL != toDel && key != toDel->val) {
            prev = toDel;
            if (key < toDel->val) toDel = toDel->left;
            else toDel = toDel->right;
        }
        if (NULL == toDel) return root;
        pred = toDel->left;
        if (NULL == pred) {
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
                root = pred;
            } else {
                if (toDel->val < prev->val) {
                    prev->left = pred;
                } else {
                    prev->right = pred;
                }
            }
            while (NULL != pred->right) {
                pred = pred->right;
            }
            pred->right = toDel->right;
        }
        delete toDel;
        return root;
    }
};