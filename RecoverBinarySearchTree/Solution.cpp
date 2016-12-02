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
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;
        TreeNode* pred = NULL;
        TreeNode* cur = root;
        while (cur != NULL) {
            if (prev != NULL && cur->val < prev->val) {
                if (first == NULL) first = prev;
                second = cur;
            }
            if (cur->left != NULL) {
                pred = cur->left;
                while (pred->right != NULL && pred->right != cur) {
                    pred = pred->right;
                }
                
                if (pred->right == NULL) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = NULL;
                    prev = cur;
                    cur = cur->right;
                }
            } else {
                prev = cur;
                cur = cur->right;
            }
        }
        int val = first->val;
        first->val = second->val;
        second->val = val;
        return;
    }
};