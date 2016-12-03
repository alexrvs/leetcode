/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recoverTree(struct TreeNode* root) {
    struct TreeNode* f = NULL;
    struct TreeNode* s = NULL;
    struct TreeNode* d = NULL;
    struct TreeNode* prev = NULL;
    struct TreeNode* cur = root;
    while (cur != NULL) {
        if (prev != NULL && prev->val > cur->val) {
            if (f == NULL) f = prev;
            s = cur;
        }
        if (cur->left != NULL) {
            d = cur->left;
            while (d->right != NULL && d->right != cur) {
                d = d->right;
            }
            if (d->right == cur) {
                d->right = NULL;
                prev = cur;
                cur = cur->right;
            } else {
                d->right = cur;
                cur = cur->left;
            }
        } else {
            prev = cur;
            cur = cur->right;
        }
    }
    
    int val = f->val;
    f->val = s->val;
    s->val = val;
    return;
}