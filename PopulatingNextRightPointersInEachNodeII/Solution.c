/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  struct TreeLinkNode *left, *right, *next;
* };
*
*/
struct TreeLinkNode * firstNextChild(struct TreeLinkNode * node) {
    while (node) {
        if (node->left != NULL) return node->left;
        if (node->right != NULL) return node->right;
        node = node->next;
    }
    return NULL;
}

void connect(struct TreeLinkNode *root) {
    if (root == NULL) return;
    struct TreeLinkNode * node = root;
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
