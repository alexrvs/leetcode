/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    TreeLinkNode * firstNextChild(TreeLinkNode * node) {
        while (node) {
            if (node->left != NULL) return node->left;
            if (node->right != NULL) return node->right;
            node = node->next;
        }
        return NULL;
    }
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode * node = root;
        while (node != NULL) {
            if (node->left != NULL) {
                if (node->right != NULL) {
                    node->left->next = node->right;
                } else {
                    node->left->next = firstNextChild(node->next);
                }
            }
            if (node->right != NULL) {
                node->right->next = firstNextChild(node->next);
            }
            node = node->next;
        }
        connect(root->left);
        connect(root->right);
    }
};
