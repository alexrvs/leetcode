/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    *returnSize = num + 1;
    int* res = (int*) malloc((*returnSize) * sizeof(int));
    res[0] = 0;
    int n = 1;
    for (int i = 1; i <= num; i++) {
        if (n == i) {
            res[i] = 1;
            n <<= 1;
        } else {
            res[i] = res[i - n / 2] + 1;
        }
    }
    return res;
}
