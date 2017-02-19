/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int layer(struct TreeNode* node) {
    if (node == NULL) return 0;
    int l = layer(node->left);
    int r = layer(node->right);
    return (l > r ? l + 1 : r + 1);
}

bool traverse(struct TreeNode* node, int layer, int target, int* res) {
    if (node == NULL) return false;
    if (target == layer) {
        *res = node->val;
        return true;
    }
    if(true == traverse(node->left, layer + 1, target, res) || 
       true == traverse(node->right, layer + 1, target, res) ) {
           return true;
    }
    return false;
}

int findBottomLeftValue(struct TreeNode* root) {
    int l = layer(root);
    int res = 0;
    traverse(root, 1, l, &res);
    return res;
}