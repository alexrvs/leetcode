/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int* res = (int*) malloc((rowIndex + 1) * sizeof(int));
    memset(res, 0, (rowIndex + 1) * sizeof(int));
    *returnSize = rowIndex + 1;
    res[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            res[j] += res[j - 1];
        }
    }
    return res;
}
