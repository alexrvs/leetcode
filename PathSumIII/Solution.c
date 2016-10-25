/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int helper(struct TreeNode* root, int* sums, int sumsSize, int target) {
    int cnt = 0;
    if (root == NULL) return cnt;
    for (int i = 0; i < sumsSize; i++) {
        sums[i] += root->val;
        if (sums[i] == target) cnt++;
    }
    if (root->val == target) cnt++;
    sums[sumsSize] = root->val;
    cnt += helper(root->left, sums, sumsSize + 1, target);
    cnt += helper(root->right, sums, sumsSize + 1, target);
    for (int i = 0; i < sumsSize; i++) {
        sums[i] -= root->val;
    }
    return cnt;
}

int height(struct TreeNode* root) {
    if (root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l + 1 : r + 1);
}

int pathSum(struct TreeNode* root, int sum) {
    int h = height(root);
    if (h == 0) return 0;
    int* sums = (int*) malloc(h * sizeof(int));
    memset(sums, 0, h * sizeof(int));
    int cnt = helper(root, sums, 0, sum);
    free(sums);
    return cnt;
}