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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = 0;
        int rh = 0;
        TreeNode* node = root;
        while (node != NULL) { lh++; node = node->left; }
        node = root;
        while (node != NULL) { rh++; node = node->right; }
        if (lh == rh) { return pow(2, lh) - 1; }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
