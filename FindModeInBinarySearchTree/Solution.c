/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void cntHelper(struct TreeNode* node, int* cnt, int* maxCnt, int* prev, int* resSize) {
    if (node == NULL) return;
    cntHelper(node->left, cnt, maxCnt, prev, resSize);
    if (*cnt == 0) {
        *prev = node->val;
        *cnt = 1;
    } else {
        if (*prev == node->val) {
            (*cnt)++;
        } else {
            *prev = node->val;
            *cnt = 1;
        }
    }
    if (*maxCnt < *cnt) {
        *maxCnt = *cnt;
        *resSize = 1;
    } else if (*maxCnt == *cnt) {
        (*resSize)++;
    }
    cntHelper(node->right, cnt, maxCnt, prev, resSize);
    return;
}

void pickHelper(int* res, struct TreeNode* node, int* cnt, int maxCnt, int* prev, int* resSize) {
    if (node == NULL) return;
    pickHelper(res, node->left, cnt, maxCnt, prev, resSize);
    if (*cnt == 0) {
        *prev = node->val;
        *cnt = 1;
    } else {
        if (*prev == node->val) {
            *cnt = *cnt + 1;
        } else {
            *prev = node->val;
            *cnt = 1;
        }
    }
    if (maxCnt == *cnt) {
        res[*resSize] = node->val;
        (*resSize)++;
    }
    pickHelper(res, node->right, cnt, maxCnt, prev, resSize);
    return;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMode(struct TreeNode* root, int* returnSize) {
    int cnt = 0;
    int maxCnt = 0;
    int prev = 0;
    int resSize = 0;
    cntHelper(root, &cnt, &maxCnt, &prev, &resSize);
    cnt = 0;
    int* res = (int*) malloc(resSize * sizeof(int));
    *returnSize = resSize;
    resSize = 0;
    pickHelper(res, root, &cnt, maxCnt, &prev, &resSize);
    return res;
}