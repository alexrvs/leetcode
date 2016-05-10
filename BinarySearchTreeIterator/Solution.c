/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct TreeNode **stack;
    int size;
    int cur;
};

int height(struct TreeNode *node) {
    if (node == NULL) return 0;
    int l = height(node->left);
    int r = height(node->right);
    return  1 + (l > r ? l : r);
}

void helper(struct BSTIterator *iter, struct TreeNode *node) {
    while (node != NULL) {
        iter->cur++;
        iter->stack[iter->cur] = node;
        node = node->left;
    }
    return;
}

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator *iter = (struct BSTIterator*) malloc(sizeof(struct BSTIterator));
    iter->size = height(root);
    iter->stack = (struct TreeNode **) malloc(iter->size * sizeof(struct TreeNode *));
    iter->cur = -1;
    helper(iter, root);
    return iter;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    return (iter->cur != -1);
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    struct TreeNode *node = iter->stack[iter->cur];
    iter->cur--;
    helper(iter, node->right);
    return node->val;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
    free(iter->stack);
    free(iter);
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */
